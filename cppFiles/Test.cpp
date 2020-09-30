//
// Created by Patryk on 2020-09-29.
//

#include "../hFiles/Test.h"

Test::Test(bool start) {
    cout << "Testas:" << endl;
    cout << endl;
    if (start) {
        this->filesWithOneSymbol();
        this->filesWithMoreThan1000Symbols();
        this->filesWithMoreThan1000SymbolsOneWithOneDif();
        this->emptyFile();
        this->check25k10Symbols();
        this->check25k100Symbols();
        this->check25k500Symbols();
        this->check25k1000Symbols();
        this->checkKonstitucija();
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
    this->runProcess("konstitucija.txt", "Sutapimu konstitucijoje: ");
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
