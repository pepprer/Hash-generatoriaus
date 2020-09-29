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
    void readFile();
    void readCommandLine();
public:
    ReadWrite();

    void write();

    static string checkInput(const string& a, const string& b);

    string getInput();

    void setOutput(string str);
};


#endif //HASH_GENERATORIUS_READWRITE_H
