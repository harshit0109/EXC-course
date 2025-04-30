#include <iostream>
#include <string>
#include <iomanip> // for std::hex and std::setw
using namespace std;

// XOR Encryption/Decryption function
string xorEncryptDecrypt(const string& text, const string& key) {
    if (key.empty()) {
        throw invalid_argument("Key cannot be empty.");
    }

    string result;
    for (size_t i = 0; i < text.size(); ++i) {
        result += text[i] ^ key[i % key.length()];
    }
    return result;
}

// Helper function to print encrypted output as hex
void printHex(const string& data) {
    for (unsigned char c : data) {
        cout << hex << setw(2) << setfill('0') << (int)c;
    }
    cout << dec << endl; // reset back to decimal
}

int main() {
    string text, key;

    cout << "Enter text to encrypt: ";
    getline(cin, text);

    cout << "Enter key: ";
    getline(cin, key);

    if (key.empty()) {
        cerr << "Error: Key cannot be empty!" << endl;
        return 1;
    }

    try {
        // Encrypt
        string encrypted = xorEncryptDecrypt(text, key);
        cout << "Encrypted (hex): ";
        printHex(encrypted);

        // Decrypt
        string decrypted = xorEncryptDecrypt(encrypted, key);
        cout << "Decrypted text: " << decrypted << endl;
    }
    catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}
