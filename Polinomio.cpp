#include "Polinomio.h"
using namespace SymEngine;
using namespace std;

// Constructor
Polinomio::Polinomio() : x(symbol("x")) {}

void Polinomio::leerPolinomio(const string& user_input) {
    try {
        poly = Expression(parse(user_input)); 
    } catch (const std::exception& e) {
        cerr << "Error al procesar el polinomio ingresado: " << e.what() << endl;
    }
}

void Polinomio::calcularDerivada() {
    first_derivative = diff(poly, x);
}

void Polinomio::encontrarPuntosCriticos() {
    RCP<const Set> solutions = solve(first_derivative.get_basic(), x);

    if (is_a<FiniteSet>(*solutions)) {
        const auto &finite_set = down_cast<const FiniteSet &>(*solutions);
        for (const auto &point : finite_set.get_container()) {
            critical_points.push_back(Expression(point));
        }
    }
}

void Polinomio::clasificarPuntosCriticos() {
    if (critical_points.empty()) {
        cout << "No se encontraron puntos críticos." << endl;
        return;
    }

    cout << "\nPuntos críticos y su clasificación:" << endl;
    for (const auto &point : critical_points) {
        auto left_value = first_derivative.subs({{x, point - 1e-3}});  
        auto right_value = first_derivative.subs({{x, point + 1e-3}}); 

        cout << "x = " << point << " -> ";
        if (str(left_value).find('-') == string::npos && str(right_value).find('-') != string::npos) {
            cout << "Máximo local" << endl;
        } else if (str(left_value).find('-') != string::npos && str(right_value).find('-') == string::npos) {
            cout << "Mínimo local" << endl;
        } else {
            cout << "Punto de inflexión o sin clasificación" << endl;
        }
    }
}

void Polinomio::mostrarResultados() const {
    cout << "\nPolinomio ingresado: " << poly << endl;
    cout << "Primera derivada: " << first_derivative << endl;
}
