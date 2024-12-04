#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <vector>
#include <symengine/expression.h>
#include <symengine/derivative.h>
#include <symengine/solve.h>
#include <symengine/symbol.h>
#include <symengine/sets.h>
#include <symengine/parser.h>
#include <symengine/eval_double.h>
#include <symengine/real_double.h>
#include <QMainWindow>
#include <QFile>

class Polinomio {
private:
    SymEngine::RCP<const SymEngine::Symbol> x;
    SymEngine::Expression poly;
    SymEngine::Expression primera_derivada;
    SymEngine::Expression segunda_derivada;
    std::vector<SymEngine::Expression> puntos_criticos;

public:
    Polinomio(std::string arg);  // Constructor

    void leerPolinomio(const std::string& user_input);              // Leer polinomio desde el usuario
    void encontrarPuntosCriticos();    // Encontrar puntos críticos
    void clasificarPuntosCriticos();   // Clasificar los puntos críticos
    void mostrarResultados() const;   // Mostrar el polinomio y la derivada
    double evaluar(double x_value);
    double evaluarSegundaDerivada(double x_valor);
    std::vector<std::string> getPuntosCriticos();
    std::vector<double> getMaximos();
    std::vector<double> getMinimos();
    void escribirLog(const QString &mensaje);
};

#endif // POLINOMIO_H
