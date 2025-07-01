#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include "Calculator.hpp"
#include "Menu.hpp"
#include "Enums.hpp"

int main() {
    // Configuração do console para UTF-8
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int menuInput = 0; // Variável para armazenar a opção do menu

    // Loop principal do menu
    do {
        Menu::exibirMenuPrincipal(); // Exibe o menu principal
        std::cin >> menuInput; // Lê a entrada do usuário

        auto opcao = static_cast<MenuOption>(menuInput); // Converte a entrada do usuário para o enum MenuOption

        // Verifica a opção selecionada
        switch (opcao) {
            case MenuOption::CALCULAR: {
                Menu::exibirOperacoes(); // Exibe as operações disponíveis
                int operacaoInput; // Variável para armazenar a opção de operação
                std::cin >> operacaoInput; // Lê a entrada do usuário para a operação

                auto operation = static_cast<OperationType>(operacaoInput);
                // Converte a entrada do usuário para o enum OperationType

                double a, b, resultado; // Variáveis para armazenar os valores de entrada e o resultado

                try {
                    switch (operation) {
                        case OperationType::SOMA:
                            std::cout << "Digite dois valores: ";
                            std::cin >> a >> b;
                            resultado = Calculator::soma(a, b);
                            break;
                        case OperationType::SUBTRACAO:
                            std::cout << "Digite dois valores: ";
                            std::cin >> a >> b;
                            resultado = Calculator::subtracao(a, b);
                            break;
                        case OperationType::MULTIPLICACAO:
                            std::cout << "Digite dois valores: ";
                            std::cin >> a >> b;
                            resultado = Calculator::multiplicacao(a, b);
                            break;
                        case OperationType::DIVISAO:
                            std::cout << "Digite dois valores: ";
                            std::cin >> a >> b;
                            resultado = Calculator::divisao(a, b);
                            break;
                        case OperationType::PORCENTAGEM:
                            std::cout << "Digite o total e a porcentagem: ";
                            std::cin >> a >> b;
                            resultado = Calculator::porcentagem(a, b);
                            break;
                        case OperationType::RAIZ:
                            std::cout << "Digite o número: ";
                            std::cin >> a;
                            resultado = Calculator::raizQuadrada(a);
                            break;
                        case OperationType::POTENCIA:
                            std::cout << "Digite a base e o expoente: ";
                            std::cin >> a >> b;
                            resultado = Calculator::potencia(a, b);
                            break;
                        default:
                            std::cout << "Operação inválida!\n";
                            continue;
                    }

                    std::cout << "Resultado: " << resultado << "\n";
                } catch (const std::exception &e) {
                    std::cout << "Erro: " << e.what() << "\n";
                }

                break;
            }
            case MenuOption::SAIR:
                std::cout << "Saindo...\n";
                break;

            default:
                std::cout << "Opção inválida!\n";
                break;
        }
    } while (menuInput != static_cast<int>(MenuOption::SAIR));

    return 0;
}
