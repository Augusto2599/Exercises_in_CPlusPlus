#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <cmath>

// Esta é uma classe de calculadora simples que fornece operações aritméticas básicas.
// As funções são estáticas, pois não dependem de estado interno da classe.
// As operações suportadas incluem soma, subtração, multiplicação, divisão, porcentagem, raiz quadrada e potência.
class Calculator {
public:
    static double soma(double a, double b); // Soma dois números.

    static double subtracao(double a, double b); // Subtrai o segundo número do primeiro.

    static double multiplicacao(double a, double b); // Multiplica dois números.

    static double divisao(double a, double b); // Divide o primeiro número pelo segundo, lançando uma exceção se o divisor for zero.

    static double porcentagem(double total, double percentagem); // Calcula a porcentagem de um total, multiplicando o total pela porcentagem e dividindo por 100.

    static double raizQuadrada(double a); // Calcula a raiz quadrada de um número, lançando uma exceção se o número for negativo.

    static double potencia(double base, double expoente); // Calcula a potência de um número elevado a um expoente, usando a função pow da biblioteca cmath.
};

#endif //CALCULATOR_HPP
