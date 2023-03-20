#include <iostream>

const int LETTERS = 26;
const int A = 65;
const int Z = A + LETTERS;


/**
 * Shifts the given string by 'shift' characters in right circular manner
 * 
 * @param sample the given string to shift
 * @param shift the numbers to characters to shift
 * @return sample string shifted by 'shift' characters
 */
std::string circShiftRight(std::string sample, int shift);

/**
 * Shifts the given string by 'shift' characters in left circular manner
 * 
 * @param sample the given string to shift
 * @param shift the numbers to characters to shift
 * @return sample string shifted by 'shift' characters
 */
std::string circShiftLeft(std::string sample, int shift);


int main(int argc, char** argv) {

    std::string numbers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int j = 0; j < LETTERS; j++) {
        std::cout << circShiftLeft(numbers, j) << std::endl;
    }

    return 0;
}


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