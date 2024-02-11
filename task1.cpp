#include <iostream>
#include <string>

//Реализовать шифр Цезаря.

std::string encrypt_caesar(const std::string& message, int shift) {
    std::string result = "";

    for (char symbol : message) {
        if (std::isalpha(symbol)) {
            char base = (std::islower(symbol)) ? 'a' : 'A';
            char encrypted = (symbol - base + shift) % 26 + base;
            result += encrypted;
        } else {
            result += symbol;
        }
    }

    return result;
}

std::string decrypt_caesar(const std::string& message, int shift) {
    return encrypt_caesar(message, -shift);
}

int main() {
    setlocale(LC_ALL, "Rus");


    int shift;
    std::string message;

    std::cout << "Введите сообщение: ";
    std::getline(std::cin, message);

    std::cout << "Введите сдвиг: ";
    std::cin >> shift;

    std::string encrypted = encrypt_caesar(message, shift);
    std::string decrypted = decrypt_caesar(encrypted, shift);

    std::cout << "Зашифрованное сообщение: " << encrypted << std::endl;
    std::cout << "Расшифрованное сообщение: " << decrypted << std::endl;

    return 0;
}