//
// Created by Patryk on 2020-09-29.
//

#include "../hFiles/Test.h"

Test::Test(bool start) {
    cout << "Testas:" << endl;
    cout << endl;
//    if (start) {
//        this->filesWithOneSymbol();
//        this->filesWithMoreThan1000Symbols();
//        this->filesWithMoreThan1000SymbolsOneWithOneDif();
//        this->emptyFile();
//        this->check25k10Symbols();
//        this->check25k100Symbols();
//        this->check25k500Symbols();
//        this->check25k1000Symbols();
//        this->checkKonstitucija();
//    }
this->checkInBits();
}

string Test::readFile(const string &fileName) {
    string text;
    ifstream fd(fileName);
    text.assign((istreambuf_iterator<char>(fd)),
                (istreambuf_iterator<char>()));
    fd.close();
    return text;
}

void Test::filesWithOneSymbol() {
    Hash hashing;
    this->runProcessWith2Files("oneSymbol1.txt", "Uzsifruotas simbolis:", "oneSymbol2.txt",
                               "Uzsifruotas simbolis:");
}

void Test::filesWithMoreThan1000Symbols() {
    this->runProcessWith2Files("1001Symbols1.txt", "Uzsifruota 1001 simboliu:", "1001Symbols2.txt",
                               "Uzsifruota kitu 1001 simboliu:");
}

void Test::filesWithMoreThan1000SymbolsOneWithOneDif() {
    this->runProcessWith2Files("1001Symbols3.txt", "Uzsifruota 1001 simboliu:", "1001Symbols4.txt",
                               "Uzsifruota 1001 tupaciu simboliu tik pakeistas vienas simbolis 501 pozicijoje:");
}

void Test::emptyFile() {
    Hash hashing;
    string text;

    text = this->readFile("emptyFile.txt");
    hashing.hashNew(text);
    cout << "Uzsifruotas tuscias failas:" << endl;
    cout << hashing.getHashValue() << endl;
    cout << endl;

    text = "";
}

void Test::runProcessWith2Files(const string &fileName1, const string &message1, const string &fileName2,
                                const string &message2) {
    Hash hashing;
    string text;

    text = this->readFile(fileName1);
    hashing.hashNew(text);
    cout << message1 << endl;
    cout << hashing.getHashValue() << endl;

    text = this->readFile(fileName2);
    hashing.hashNew(text);
    cout << message2 << endl;
    cout << hashing.getHashValue() << endl;

    cout << endl;
}

void Test::check25k10Symbols() {
    this->runProcess("check25k10Symbols.txt", "Sutapimu tarp 10: ");
}

void Test::check25k100Symbols() {
    this->runProcess("check25k100Symbols.txt", "Sutapimu tarp 100: ");
}

void Test::check25k500Symbols() {
    this->runProcess("check25k500Symbols.txt", "Sutapimu tarp 500: ");
}

void Test::check25k1000Symbols() {
    this->runProcess("check25k1000Symbols.txt", "Sutapimu tarp 1000: ");
}

void Test::checkKonstitucija() {
    vector<string> text;
    for (const string &line: this->readFileToVector("konstitucija.txt")) {
        text.push_back(line);
    }

    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < text.size(); i++) {
        sha256(text.at(1));
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> d = end-start;
    cout<< "SHA256 sifravo faila konstitucija.txt: "<< d.count() << endl;

    start = chrono::high_resolution_clock::now();
    for(int i = 0; i < text.size(); i++) {
        myHash(text.at(1));
    }
    end = chrono::high_resolution_clock::now();
     d = end-start;
    cout<< "Mano sifravimo algoritmas sifravo faila konstitucija.txt: "<< d.count() << endl;
}

void Test::runProcess(const string &fileName, const string &message) {
    Hash hashing;
    vector<string> text;
    for (const string &line: this->readFileToVector(fileName)) {
        hashing.hashNew(line);
        text.push_back(hashing.getHashValue());
    }
    cout << message << this->checkCoincidences(text, text.size()) << endl;
}

vector<string> Test::readFileToVector(const string &fileName) {
    vector<string> lines;
    string str;
    ifstream fd(fileName);
    while (getline(fd, str)) {
        lines.push_back(str);
    }
    return lines;
}

int Test::checkCoincidences(vector<string> text, int length) {
    int sutapimai = 0;

    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (text.at(i) == text.at(j)) sutapimai++;
        }
    }
    return sutapimai;
}

void Test::checkInBits() {
    Hash hashing;
    string str;
    vector<string> text1, text2;
    vector<double> skirtumai;
    ifstream fd("porosStringu.txt");

    while (getline(fd, str)) {
        hashing.hashNew(str.substr(0, 32));
        text1.push_back(hashing.getHashValue());

        hashing.hashNew(str.substr(33, 32));
        text2.push_back(hashing.getHashValue());
    }

    for(int s = 0; s < 100000; s++) {
        bitset<512> b1;
        for (int i = 0; i < 64; ++i) {
            char c = text1.at(s).at(i);
            for (int j = 7; j >= 0 && c; --j) {
                if (c & 0x1) {
                    b1.set(8 * i + j);
                }
                c >>= 1;
            }
        }

        bitset<512> b2;
        for (int i = 0; i < 64; ++i) {
            char c = text2.at(s).at(i);
            for (int j = 7; j >= 0 && c; --j) {
                if (c & 0x1) {
                    b2.set(8 * i + j);
                }
                c >>= 1;
            }
        }

        double sutapimai = 0;
        for(int j = 0; j < 512; j++) if(b1.test(j) == b2.test(j)) sutapimai++;

        skirtumai.push_back(sutapimai / 512 * 100);
    }

    cout << "Max Element = " << *max_element(skirtumai.begin(), skirtumai.end()) << endl;
    cout << "Min Element = " << *min_element(skirtumai.begin(), skirtumai.end()) << endl;
    cout << "Average  Element = " << accumulate( skirtumai.begin(), skirtumai.end(), 0.0) / skirtumai.size() << endl;

}

void test()
{
    Test test = Test(true);
}
