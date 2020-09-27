//
// Created by Patryk on 2020-09-27.
//

#ifndef HASH_GENERATORIUS_READWRITE_H
#define HASH_GENERATORIUS_READWRITE_H

#include "header.h"

class ReadWrite {
private:
    string input;
    string output;
public:
    ReadWrite();

    void readFile();

    void readCommandLine();

    void write();

    static string checkInput(const string& a, const string& b);

    string getInput();

    string getOutput();
};


#endif //HASH_GENERATORIUS_READWRITE_H
