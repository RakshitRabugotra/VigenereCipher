#include <iostream>
#include <unordered_map>
#include "vigenereCipherTable.cpp"

int main(int argc, char** argv) {

    char** vigenereTable = generateVigenereCipherTable();

    print2DArray(vigenereTable, LETTERS, LETTERS);

    return 0;
}