#include "Menu.hpp"
#include <iostream>

// Essa função é responsável por exibir o menu principal.
void Menu::exibirMenuPrincipal() {
    std::cout << "Bem-vindo ao Menu Principal!";
    std::cout << "\n1. Calcular";
    std::cout << "\n2. Sair";
    std::cout << "\n3. Escolha uma opção: ";
}

// Essa função exibe as operações matemáticas disponíveis para o usuário.
void Menu::exibirOperacoes() {
    std::cout << "\nOperações disponíveis:";
    std::cout << "\n1. Soma";
    std::cout << "\n2. Subtração";
    std::cout << "\n3. Multiplicação";
    std::cout << "\n4. Divisão";
    std::cout << "\n5. Porcentagem";
    std::cout << "\n6. Raiz Quadrada";
    std::cout << "\n7. Potência";
    std::cout << "\n8. Escolha uma operação: ";
}
