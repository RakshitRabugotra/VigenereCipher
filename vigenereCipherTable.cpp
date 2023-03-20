#include <iostream>
#include "vigenereCipherTable.hpp"


std::string circShiftRight(std::string sample, int shift) {
    if(shift <= 0) {
        return sample;
    }

    int length = sample.length();
    if(length == 0) {
        return sample;
    }

    // Repeat the process 'n'/'shift' times
    for(int k = 0; k < shift; k++) {
        char temp = sample[length-1];
        // Else, shift the string by one character in given direction
        for(int i = length-1; i > 0; i--) {
            sample[i] = sample[i-1];
        }
        sample[0] = temp;
    }

    // Decrement the shift and call the function again
    return sample;
}

std::string circShiftLeft(std::string sample, int shift) {
    if(shift <= 0) {
        return sample;
    }

    int length = sample.length();
    if(length == 0) {
        return sample;
    }

    // Repeat the process 'n'/'shift' times
    for(int k = 0; k < shift; k++) {
        char temp = sample[0];
        // Repeat the process 'n'/'shift' times
        for(int i = 0; i < length-1; i++) {
            sample[i] = sample[i+1];
        }
        sample[length-1] = temp;
    }

    return sample;
}

char** generateVigenereCipherTable() {
    // The alphabets which would be used in encryption
    const std::string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // The table to store the cipher table
    char** vigenereTable = new char*[LETTERS];

    // Iterate over the table and add the row
    for(int i = 0; i < LETTERS; i++) {
        // Add a row
        vigenereTable[i] = new char[LETTERS];

        int j = 0;
        for(const char c: circShiftLeft(alphabets, i)) {
            vigenereTable[i][j] = c;
            j++;
        }
    }
    return vigenereTable;
}

template<typename T>
void print2DArray(T** array, int rows, int columns) {
    for(int j = 0; j < rows; j++) {
        std::cout << "[ ";
        for(int i = 0; i < columns; i++) {
            std::cout << array[j][i] << " ";
        }
        std::cout << "]\n";
    }
}
