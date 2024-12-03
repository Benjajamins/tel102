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
    SymEngine::RCP<const SymEngine::Symbol> x;             
    SymEngine::Expression poly;                            
    SymEngine::Expression first_derivative;                
    std::vector<SymEngine::Expression> critical_points;    

public:
    Polinomio();  

    void leerPolinomio();              
    void calcularDerivada();           
    void encontrarPuntosCriticos();    
    void clasificarPuntosCriticos();   
    void mostrarResultados() const;  
};

#endif // POLINOMIO_H
