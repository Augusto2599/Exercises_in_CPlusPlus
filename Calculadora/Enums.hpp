#ifndef ENUMS_HPP
#define ENUMS_HPP

// Esse arquivo contém as definições de enums utilizados no sistema.
// As enums são usadas para representar tipos de operações e opções de menu.
enum class OperationType {
    SOMA = 1,
    SUBTRACAO = 2,
    MULTIPLICACAO = 3,
    DIVISAO = 4,
    PORCENTAGEM = 5,
    RAIZ = 6,
    POTENCIA = 7
};

enum class MenuOption {
    CALCULAR = 1,
    SAIR = 2
};

#endif //ENUMS_HPP
