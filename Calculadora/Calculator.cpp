#include "Calculator.hpp"

#include <stdexcept>

// Esta é uma classe de calculadora simples que fornece operações aritméticas básicas.
// Implementação das funções da classe Calculator
double Calculator::soma(double a, double b) { return a + b; } // Soma dois números.

double Calculator::subtracao(double a, double b) { return a - b; } // Subtrai o segundo número do primeiro.

double Calculator::multiplicacao(double a, double b) { return a * b; } // Multiplica dois números.

double Calculator::divisao(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Divisão por zero não é permitida.");
    }
    return a / b;
} // Divide o primeiro número pelo segundo, lançando uma exceção se o divisor for zero.

double Calculator::porcentagem(double total, double percentagem) {
    return total * percentagem / 100;
} // Calcula a porcentagem de um total, multiplicando o total pela porcentagem e dividindo por 100.

double Calculator::raizQuadrada(double a) {
    if (a < 0) {
        throw std::invalid_argument("Raiz quadrada de número negativo não é permitida.");
    }
    return sqrt(a);
} // Calcula a raiz quadrada de um número, lançando uma exceção se o número for negativo.

double Calculator::potencia(const double base, const double expoente) {
    return pow(base, expoente);
} // Calcula a potência de um número elevado a um expoente, usando a função pow da biblioteca cmath.
