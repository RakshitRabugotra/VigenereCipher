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


/**
 * Generates the Vigenere Cipher Table
 * @return Vigenere Cipher Table
*/
char** generateVigenereCipherTable();

/**
 * Prints a 2D array
*/
template<typename T>
void print2DArray(T** array, int rows, int columns);
