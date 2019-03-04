#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

char lowercase(char in) {
    if (in > 64 && in < 91) return in+32;
    if (in > 96 && in < 123) return in;
    return '\0';
}

std::string getkey() {
    std::cout << "Input your key" << std::endl;
    std::string buffer;
    char check = getc(stdin);
    while (check != '\n') {
        if (check = lowercase(check)) {
            buffer += check;
        }
        check = getc(stdin);
    }
    return buffer;
}

bool selectmode() {
    std::cout << std::endl << "If encrypt, input '1'. If decrypt, input '0'." << std::endl;
    unsigned int mode = 1;
    scanf("%u", &mode);
    fflush(stdin);
    if (mode) {
        return true;
    } else {
        return false;
    }
}

bool encrypt(std::string key) {
    std::cout << "Input your plaintext:" << std::endl;
    unsigned int length = key.length(), key_iterator = 0;
    char in;
    while ((in = getc(stdin)) != '\n') {
        if (in = lowercase(in)) {
            std::cout << (char)((in+key[key_iterator]-194)%26+65);
            key_iterator = (key_iterator+1)%length;
        }
    }
    fflush(stdin);
    return true;
}

bool decrypt(std::string key) {
    std::cout << "Input your ciphertext:" << std::endl;
    unsigned int length = key.length(), key_iterator = 0;
    char in;
    while ((in = getc(stdin)) != '\n') {
        if (in = lowercase(in)) {
            std::cout << (char)((in+26-key[key_iterator])%26+97);
            key_iterator = (key_iterator+1)%length;
        }
    }
    fflush(stdin);
    return true;
}

int main () {
    std::string key;
    while (key.empty()) {
        key = getkey();
    }
    while (true) {
        if (selectmode()) {
            encrypt(key);
        } else {
            decrypt(key);
        }
    }
    system("pause");
    return 0;
}
