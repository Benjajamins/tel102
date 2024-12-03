#include "Polinomio.h"
using namespace std;
using namespace SymEngine;
int main() {
    Polinomio polinomio;

    try {
        polinomio.leerPolinomio();
        polinomio.calcularDerivada();
        polinomio.encontrarPuntosCriticos();
        polinomio.mostrarResultados();
        polinomio.clasificarPuntosCriticos();
    } catch (const SymEngineException &e) {
        cout << "Error al procesar el polinomio: " << e.what() << endl;
    }

    return 0;
}
