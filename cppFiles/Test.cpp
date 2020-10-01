//
// Created by Patryk on 2020-09-29.
//

#include "../hFiles/Test.h"

Test::Test(bool start) {
    if (start) {
        filesWithOneSymbol();
        filesWithMoreThan1000Symbols();
        filesWithMoreThan1000SymbolsOneWithOneDif();
        emptyFile();
        check25k10Symbols();
        check25k100Symbols();
        check25k500Symbols();
        check25k1000Symbols();
        checkKonstitucija();
        checkInBits();
    }
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
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TESTAS: failai su vienu simboliu:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    Hash hashing;
    runProcessWith2Files("oneSymbol1.txt", "oneSymbol2.txt");
}

void Test::filesWithMoreThan1000Symbols() {
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TESTAS: failai su daugiau nei 1000 simboliu:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    runProcessWith2Files("1001Symbols1.txt", "1001Symbols2.txt");
}

void Test::filesWithMoreThan1000SymbolsOneWithOneDif() {
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TESTAS: failai su daugiau nei 1000 simboliu kur keiciasi tik vienas simbolis viduryje:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    runProcessWith2Files("1001Symbols3.txt", "1001Symbols4.txt");
}

void Test::emptyFile() {
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TESTAS: tuscias failas:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    Hash hashing;
    string text;
    text = readFile("emptyFile.txt");
    hashing.hashNew(text);
    cout << "Sifras: " << hashing.getHashValue() << endl;
    cout << endl;

    text = "";
}

void Test::runProcessWith2Files(const string &fileName1, const string &fileName2) {
    Hash hashing;
    string text;

    text = readFile(fileName1);
    hashing.hashNew(text);
    cout << "Sifras: " << hashing.getHashValue() << endl;

    text = readFile(fileName2);
    hashing.hashNew(text);
    cout << "Sifras: " << hashing.getHashValue() << endl;

    cout << endl;
}

void Test::check25k10Symbols() {
    runProcess("check25k10Symbols.txt",  10);
}

void Test::check25k100Symbols() {
    runProcess("check25k100Symbols.txt", 100);
}

void Test::check25k500Symbols() {
    runProcess("check25k500Symbols.txt", 500);
}

void Test::check25k1000Symbols() {
    runProcess("check25k1000Symbols.txt", 1000);
}

void Test::checkKonstitucija() {
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TESTAS: konstitucijos isfravimas lygiomis aplinkybemis:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    vector<string> text;
    for (const string &line: readFileToVector("konstitucija.txt")) {
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
    cout << endl;
}

void Test::runProcess(const string &fileName, int s) {
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TESTAS: failas su 25000 reiksmemis po " + to_string(s) + " simboliu:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    vector<string> text1, text2;

    readAndHashToVectors(fileName, text1, text2, s);

    int sutapimas = 0;

    for(int i = 0; i < text1.size(); i++) {
        if(text1.at(i) == text2.at(i)) sutapimas++;
    }

    cout << "Sutapimu: " << sutapimas << endl;
    cout << endl;
}

void Test::readAndHashToVectors(const string &fileName, vector<string> &text1, vector<string> &text2, int s) {
    Hash hashing;
    string str;
    ifstream fd(fileName);

    while (getline(fd, str)) {
        hashing.hashNew(str.substr(0, s));
        text1.push_back(hashing.getHashValue());

        hashing.hashNew(str.substr(s+1, s));
        text2.push_back(hashing.getHashValue());
    }
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
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "TESTAS: Procentinis skirtingumas:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    vector<string> text1, text2;

    readAndHashToVectors("porosStringu.txt", text1, text2, 32);

    vector<double> skirtumai;

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

    cout << "Min skirtumo reiksme = " << *min_element(skirtumai.begin(), skirtumai.end()) << "%" << endl;
    cout << "Max skirtumo reiksme = " << *max_element(skirtumai.begin(), skirtumai.end()) << "%" << endl;
    cout << "Vidurkines skirtumo reiksme = " << accumulate( skirtumai.begin(), skirtumai.end(), 0.0) / skirtumai.size() << "%" << endl;
}

void test()
{
    Test test = Test(true);
}
