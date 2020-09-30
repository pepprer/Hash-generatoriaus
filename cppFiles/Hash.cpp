//
// Created by Patryk on 2020-09-29.
//

#include "../hFiles/Hash.h"

void Hash::convertTo32() {
    int textLength = this->text.length();
    int firstLength = textLength;

    if (textLength == 0) this->string32 = "0123456789ABCDEFabcdefghijklmnpt";

    else if (textLength % 32 == 0) this->string32 = this->text;

    else {
        string saveText = this->text;

        while (textLength < 32) {
            this->text += saveText;
            textLength = this->text.length();
        }

        if (textLength % 32 == 0) {
            string32 = this->text;
        } else {
            int gcd;

            for (int i = 1; i <= 32 && i <= textLength; i++) {
                if (32 % i == 0 && textLength % i == 0) {
                    gcd = i;
                }
            }

            saveText = this->text;

            for (int i = 0; i < gcd; i++) {
                this->text += saveText;
            }
            this->string32 = this->text;
        }
    }

    int length = this->string32.length() / 32;


    if (length != 1) {
        int acv = this->size % length;

        string string32Return;

        for (int i = 0; i < 32; i++) {
            string32Return += this->string32.at(i * length + acv);
        }

        this->string32 = string32Return;
    }
}

Hash::Hash(string str) {
    this->text = str;
    this->countSize();
    this->convertTo32();
    this->cryptString();
}

void Hash::countSize() {
    for (char s: this->text) {
        this->size = size += (int) s;
    }
    this->size += this->text.size();
}

void Hash::cryptString() {
    static const char alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    unsigned long long int crypt = 43;
    if (this->size == 0) this->size = 1;
    for (char c : string32) {
        crypt += (int) c * this->size * (int) c;
        if (crypt % 124 > 62) {
            this->hashValue += alphabet[crypt % 124 - 62];
        } else if (crypt % 92 > 32) {
            this->hashValue += alphabet[crypt % 92 - 32];
        } else if (crypt % 88 > 12) {
            this->hashValue += alphabet[crypt % 92 + 17];
        } else if (crypt % 62 > 32) {
            this->hashValue += alphabet[crypt % 62 - 20];
        } else {
            this->hashValue += alphabet[crypt % 62];
        }
    }

    crypt = 777;
    for (char c : string32) {
        crypt += (int) c * this->size * (int) c;
        if (crypt % 186 > 124) {
            this->hashValue += alphabet[crypt % 186 - 124];
        } else if (crypt % 77 > 32) {
            this->hashValue += alphabet[crypt % 77 - 32];
        } else if (crypt % 66 > 32) {
            this->hashValue += alphabet[crypt % 66 - 32];
        } else if (crypt % 34 > 12) {
            this->hashValue += alphabet[crypt % 34 - 12];
        } else {
            this->hashValue += alphabet[crypt % 62];
        }
    }
}

string Hash::getHashValue() {
    return this->hashValue;
}

void Hash::hashNew(string str) {
    this->text = str;
    this->string32 = "";
    this->hashValue = "";
    this->size = 0;
    this->countSize();
    this->convertTo32();
    this->cryptString();
}

string myHash(const string str)
{
    Hash hash = Hash(str);

    return hash.getHashValue();
}