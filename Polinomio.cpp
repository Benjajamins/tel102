#include "Polinomio.h"
using namespace SymEngine;
using namespace std;

// Constructor
Polinomio::Polinomio() : x(symbol("x")) {}

// Leer polinomio desde la entrada del usuario
void Polinomio::leerPolinomio(const string& user_input) {
    try {
        // Inicializar directamente poly usando el argumento recibido
        poly = Expression(parse(user_input)); 
    } catch (const std::exception& e) {
        cerr << "Error al procesar el polinomio ingresado: " << e.what() << endl;
    }
}

// Calcular la primera derivada
void Polinomio::calcularDerivada() {
    first_derivative = diff(poly, x);
}

// Encontrar puntos críticos resolviendo f'(x) = 0
void Polinomio::encontrarPuntosCriticos() {
    RCP<const Set> solutions = solve(first_derivative.get_basic(), x);

    if (is_a<FiniteSet>(*solutions)) {
        const auto &finite_set = down_cast<const FiniteSet &>(*solutions);
        for (const auto &point : finite_set.get_container()) {
            critical_points.push_back(Expression(point));
        }
    }
}

// Clasificar puntos críticos
void Polinomio::clasificarPuntosCriticos() {
    if (critical_points.empty()) {
        cout << "No se encontraron puntos críticos." << endl;
        return;
    }

    cout << "\nPuntos críticos y su clasificación:" << endl;
    for (const auto &point : critical_points) {
        // Evaluar la derivada a la izquierda y derecha del punto crítico
        auto left_value = first_derivative.subs({{x, point - 1e-3}});  // Ligeramente a la izquierda
        auto right_value = first_derivative.subs({{x, point + 1e-3}}); // Ligeramente a la derecha

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

// Mostrar el polinomio y su derivada
void Polinomio::mostrarResultados() const {
    cout << "\nPolinomio ingresado: " << poly << endl;
    cout << "Primera derivada: " << first_derivative << endl;
}
