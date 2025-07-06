#include "InputReader.hpp"
#include <iostream>
#include <limits>

std::string InputReader::readString(const std::string &prompt) {
    std::string input;
    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (input.empty()) {
            std::cout << "Entrada não pode ser vazia. Tente novamente.\n";
        }
    } while (input.empty());
    return input;
}

std::string InputReader::readOptionalString(const std::string &prompt) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    return input;
}


int InputReader::readInt(const std::string &prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        } else {
            std::cout << "Entrada inválida. Digite um número inteiro.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

int InputReader::readInt(const std::string &prompt, int min, int max) {
    int value;
    do {
        value = readInt(prompt);
        if (value < min || value > max) {
            std::cout << "Número fora do intervalo. Deve estar entre " << min << " e " << max << ".\n";
        }
    } while (value < min || value > max);
    return value;
}
