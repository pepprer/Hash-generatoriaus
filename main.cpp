#include "header.h"

int main() {
    string text;
    string text2;
    cout << "Norite paleisti testus ? (iveskite: 'taip' arba 'ne' be kabuciu)" << endl;
    if (ReadWrite::checkInput("taip", "ne") == "taip") {
        test();
    } else {
        cout << "Norite nuskaityti faila ? (iveskite: 'taip' arba 'ne' be kabuciu)" << endl;

        if (ReadWrite::checkInput("taip", "ne") == "taip") {
            ReadWrite readWrite;
            Hash hashing(readWrite.getInput());
            readWrite.setOutput(hashing.getHashValue());
            readWrite.write();
        } else {
            do {
                cout << "Iveskite teksta kuri norite su konvertuoti: " << endl;
                cin >> text;
                getline(cin, text2);
                cout << "Sekmingai uzsifruotas: " << myHash(text+text2) << endl;
                cout << endl;
                cout << "Norite uzsifruoti dar? (iveskite: 'taip' arba 'ne' be kabuciu)" << endl;
            } while(ReadWrite::checkInput("taip", "ne") == "taip");
        }
    }

    return 0;
}
