//
// Created by Patryk on 2020-09-29.
//

#ifndef HASH_GENERATORIUS_TEST_H
#define HASH_GENERATORIUS_TEST_H

#include "../header.h"

class Test {
private:
    string readFile(const string &fileName);

    int checkCoincidences(vector<string> text, int length);

    vector<string> readFileToVector(const string &fileName);

    void readAndHashToVectors(const string &fileName, vector<string> &text1, vector<string> &text2, int s);

    void runProcessWith2Files(const string &fileName1, const string &fileName2);

    void runProcess(const string &fileName, int s);

public:
    Test(bool start = false);

    void filesWithOneSymbol();

    void filesWithMoreThan1000Symbols();

    void filesWithMoreThan1000SymbolsOneWithOneDif();

    void emptyFile();

    void check25k10Symbols();

    void check25k100Symbols();

    void check25k500Symbols();

    void check25k1000Symbols();

    void checkKonstitucija();

    void checkInBits();
};

void test();


#endif //HASH_GENERATORIUS_TEST_H
