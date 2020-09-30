//
// Created by Patryk on 2020-09-29.
//

#ifndef HASH_GENERATORIUS_HASH_H
#define HASH_GENERATORIUS_HASH_H

#include "../header.h"

class Hash {
private:
    string text;
    string string32;
    string hashValue;
    unsigned long long int size = 0;

    void convertTo32();

    void countSize();

    void cryptString();

public:
    Hash(string str = "");

    string getHashValue();

    void hashNew(string str);
};

string myHash(const string str);

#endif //HASH_GENERATORIUS_HASH_H
