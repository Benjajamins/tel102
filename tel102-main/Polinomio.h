#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>
#include <vector>
#include <symengine/expression.h>
#include <symengine/derivative.h>
#include <symengine/solve.h>
#include <symengine/symbol.h>
#include <symengine/sets.h>
#include <symengine/parser.h>

class Polinomio {
private:
    SymEngine::RCP<const SymEngine::Symbol> x;             // Variable simbólica
    SymEngine::Expression poly;                            // Polinomio
    SymEngine::Expression first_derivative;                // Primera derivada
    std::vector<SymEngine::Expression> critical_points;    // Puntos críticos

public:
    Polinomio();  // Constructor

    void leerPolinomio();              // Leer polinomio desde el usuario
    void calcularDerivada();           // Calcular la derivada del polinomio
    void encontrarPuntosCriticos();    // Encontrar puntos críticos
    void clasificarPuntosCriticos();   // Clasificar los puntos críticos
    void mostrarResultados() const;   // Mostrar el polinomio y la derivada
};

#endif // POLINOMIO_H
