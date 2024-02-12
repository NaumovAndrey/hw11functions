
#include <vector>
#include "iostream"
#include "conio.h"
#include <sstream>

/**
 *  Валидация IP-адреса
 * @return
 */

void massage(std::string textMassage){
    std::cout << textMassage;
}

bool isValidateIpAddres(const std::string& ip){
    std::istringstream s(ip); //разбиения строки на отдельные элементы,
    std::string part;
    std::vector<int> parts;

    while (std::getline(s, part, '.')) {
        if (part.empty() || part.size() > 3) {
            return false;
        }
        for (char c : part) {
            if (!std::isdigit(c)) {
                return false;
            }
        }

        int num = std::stoi(part); //конвертируем строку в int
        if (num < 0 || num > 255 || (part.size() > 1 && part[0] == '0')) {
            return false;
        }

        parts.push_back(num);
    }

    return parts.size() == 4;
}

int main(){
    massage("Enter ip address: ");
    std::string ipAddress;
    std::getline(std::cin, ipAddress);

    if (isValidateIpAddres(ipAddress)){
        massage("Valid");
    } else {
        massage("Invalid");
    }
}