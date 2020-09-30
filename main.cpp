#include "header.h"

int main() {
    cout << "Norite paleisti testus ? (iveskite: 'taip' arba 'ne' be kabuciu)" << endl;

    if (ReadWrite::checkInput("taip", "ne") == "taip") {
        Test test(true);
    } else {
        ReadWrite readWrite;
        Hash hashing(readWrite.getInput());
        readWrite.setOutput(hashing.getHashValue());
        readWrite.write();
    }

    return 0;
}
