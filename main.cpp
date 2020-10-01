#include "header.h"

int main() {
    cout << "Norite paleisti testus ? (iveskite: 'taip' arba 'ne' be kabuciu)" << endl;

    if (ReadWrite::checkInput("taip", "ne") == "taip") {
        test();
    } else {
        ReadWrite readWrite;
        Hash hashing(readWrite.getInput());
        readWrite.setOutput(hashing.getHashValue());
        readWrite.write();

        cout << endl;
        cout << "Norite uzsifruoti dar? (iveskite: 'taip' arba 'ne' be kabuciu)" << endl;
        while(ReadWrite::checkInput("taip", "ne") == "taip") {
            cout << "Norite uzsifruoti dar? (iveskite: 'taip' arba 'ne' be kabuciu)" << endl;
            string helper;
            cout << "Iveskite teksta kuri norite su konvertuoti: " << endl;
            cin >> helper;
            getline(cin, helper);
            cout << "Sekmingai uzsifruotas: " << myHash(helper) << endl;
        }
    }

    return 0;
}
