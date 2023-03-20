#include <iostream>
#include <cstring>
#include "vigenereCipherTable.cpp"


/**
 * Encrypts the string using Vigenere-Cipher
 * @param plainText the sample text for encryption (in uppercase)
 * @param key the key used for encryption, the same key will be used to decrypt (in uppercase)
 * @return the encrypted text using the key
*/
std::string encrypt(std::string plainText, std::string key);

/**
 * Decrypts the string using Vigenere-Cipher
 * @param encryptedText the encrypted text for decryption (in uppercase)
 * @param key the key used for decryption, the same key which was used to encrypt (in uppercase)
 * @return the decrypted plain text using the key
*/
std::string decrypt(std::string encryptedText, std::string key);

/**
 * Converts the whole string to uppercase, letter-by-letter
 * @param string the string you want to convert
*/
inline void toUppercase(std::string string);

/**
 * Checks whether the value is in given range
 * @param value
 * @param low
 * @param high
 * @return true, if low <= value < high, else false
*/
bool isWithin(int value, int low, int high);


int main(int argc, char** argv) {

    std::string sampleText = "VERSAILLES";
    std::string key = "CHEESE";

    std::string encryptedText = encrypt(sampleText, key);
    std::cout << "Encrypted text: " << encryptedText << std::endl;

    std::string decryptedText = decrypt(encryptedText, key);
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    return 0;
}

/*
    Implementation of the above defined functions
*/
std::string encrypt(std::string plainText, std::string key) {
    // Generate the cipher table
    char** vigenereTable = generateVigenereCipherTable();

    // Convert the key and text to uppercase
    toUppercase(plainText);
    toUppercase(key);

    // The new encrypted text
    std::string result = "";

    // Create a proper shift key
    int i = 0;
    while(key.length() < plainText.length()) {
        key += key[i];
        i++;
    }

    // Iterate over the given text letter by letter
    int row = 0, col = 0;
    for(int k = 0; k < plainText.length(); k++) {
        // Fetch the index in the 2D array
        row = ((int) plainText[k]) - A;
        col = ((int) key[k]) - A;
        // Add encrypted result
        if(!isWithin(row, 0, LETTERS) || !isWithin(col, 0, LETTERS)) {
            result += plainText[k];
        } else {
            result += vigenereTable[row][col];
        }
    }

    return result;
}

std::string decrypt(std::string encryptedText, std::string key) {
    // Generate the cipher table
    char** vigenereTable = generateVigenereCipherTable();

    // Convert the key and text to uppercase
    toUppercase(encryptedText);
    toUppercase(key);

    // The new encrypted text
    std::string result = "";

    // Create a proper shift key
    int i = 0;
    while(key.length() < encryptedText.length()) {
        key += key[i];
        i++;
    }

    // Iterate over the given text letter by letter
    int row = 0, col = 0;
    for(int k = 0; k < encryptedText.length(); k++) {
        // Reset the column
        col = 0;
        // Fetch the index in the 2D array
        row = ((int) key[k]) - A;
        // If we go out of bounds with row, then add the encrypted text
        if(!isWithin(row, 0, LETTERS)) {
            result += encryptedText[k];
            continue;
        }

        // We will march down this row until
        // we find the encrypted letter
        while(vigenereTable[row][col] != encryptedText[k]) col++;
        
        // If we go out of bounds with column, then add the encrypted text
        if(!isWithin(col, 0, LETTERS)) {
            result += encryptedText[k];
            continue;
        }

        // Now that we've found the column,
        // the letter corresponding to this column is the decrypted letter
        result += (char) (col + A);
    }

    return result;
}

/**
 * Converts the whole string to uppercase, letter-by-letter
 * @param string the string you want to convert
 * @return the string but in uppercase
*/
inline void toUppercase(std::string string) {
    for(int i = 0; i < string.length(); i++) {string[i] = toupper(string[i]);}
}

bool isWithin(int value, int low, int high) {
    if(low > value) return false;
    if(high <= value) return false;
    return true;
}