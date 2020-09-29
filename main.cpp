#include "header.h"

int main() {
    ReadWrite readWrite;
    Hash hashing(readWrite.getInput());
    readWrite.setOutput(hashing.getHashValue());
    readWrite.write();
    return 0;
}
