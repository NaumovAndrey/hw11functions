#include <iostream>
#include <string>
#include <vector>
#include "conio.h"

//Разработать программу проверки корректности email-адреса.

/**
 * Проверка наличия символа в строке
 * @param str строка
 * @param c символ
 * @return
 */
bool contains(const std::string& str, char c) {
    return str.find(c) != std::string::npos;
}

/**
 * Проверка корректности локальной части
 * @param localPart
 * @return
 */
bool validateLocalPart(const std::string& localPart) {
    std::string validChars = "!#$%&'*+-/=?^_{|}~.`";

    if (localPart.empty() || localPart.length() > 64 || localPart[0] == '.' || localPart[localPart.length() - 1] == '.') {
        return false;
    }

    for (char c : localPart) {
        if (!std::isalnum(c) && !contains(validChars, c)) {
            return false;
        }
    }

    for (size_t i = 0; i < localPart.size() - 1; ++i) {
        if (validChars.find(localPart[i]) != std::string::npos && validChars.find(localPart[i + 1]) != std::string::npos) {
            return false;
        }
    }

    return true;
}


/**
 * Проверка корректности доменной части
 * @param domainPart
 * @return
 */
bool validateDomainPart(const std::string& domainPart) {
    if (domainPart.empty() || domainPart.length() > 63 || domainPart[0] == '.' || domainPart[domainPart.length() - 1] == '.') {
        return false;
    }

    std::vector<std::string> parts;

    // Разделение доменной части на поддомены по точке
    size_t start = 0;
    for (size_t i = 0; i < domainPart.length(); i++) {
        if (domainPart[i] == '.') {
            std::string part = domainPart.substr(start, i - start);
            if (part.empty()) {
                return false;
            }
            parts.push_back(part);
            start = i + 1;
        }
    }

    std::string lastPart = domainPart.substr(start);
    if (lastPart.empty()) {
        return false;
    }
    parts.push_back(lastPart);

    // Проверка поддоменов на корректность
    for (const std::string& part : parts) {
        if (!std::isalnum(part[0])) {
            return false;
        }
        for (char c : part) {
            if (!std::isalnum(c) && c != '-') {
                return false;
            }
        }
    }

    return true;
}

// Проверка корректности email-адреса
bool validateEmail(const std::string& email) {
    size_t atPos = email.find('@');
    std::string localPart = email.substr(0, atPos);
    std::string domainPart = email.substr(atPos + 1);

    return (atPos != std::string::npos) && validateLocalPart(localPart) && validateDomainPart(domainPart);
}

int main(){
    std::string email;

    std::cout << "Enter an email address: ";
    std::getline(std::cin, email);

    if (validateEmail(email)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    _getch();
    return 0;
}
