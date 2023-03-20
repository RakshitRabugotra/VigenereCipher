#include <iostream>
#include <cstring>
#include "vigenereCipherTable.cpp"


/**
 * Encrypts the string using Vigenere-Cipher
 * @param text the sample text for encryption (in uppercase)
 * @param key the key used for encryption, the same key will be used to decrypt (in uppercase)
 * @return the encrypted text using the key
*/
std::string encrypt(std::string text, std::string key);

/**
 * Converts the whole string to uppercase, letter-by-letter
 * @param string the string you want to convert
*/
inline void toUppercase(std::string string);


int main(int argc, char** argv) {

    std::string sampleText = "VERSAILLES";

    std::string encryptedText = encrypt(sampleText, "CHEESE");

    std::cout << "Encrypted text: " << encryptedText << std::endl;

    return 0;
}


/**
 * Encrypts the string using Vigenere-Cipher
 * @param text the sample text for encryption (in uppercase)
 * @param key the key used for encryption, the same key will be used to decrypt (in uppercase)
 * @return the encrypted text using the key
*/
std::string encrypt(std::string text, std::string key) {
    // Generate the cipher table
    char** vigenereTable = generateVigenereCipherTable();

    // Convert the key and text to uppercase
    toUppercase(text);
    toUppercase(key);

    // The new encrypted text
    std::string result = "";

    // Create a proper shift key
    int i = 0;
    while(key.length() < text.length()) {
        key += key[i];
        i++;
    }

    // Iterate over the given text letter by letter
    int row = -1, col = -1;
    for(int k = 0; k < text.length(); k++) {
        // Fetch the index in the 2D array
        row = ((int) text[k]) - A;
        col = ((int) key[k]) - A;
        // Add encrypted result
        result += vigenereTable[row][col];
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