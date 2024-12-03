#include "polinomio.h"
using namespace SymEngine;
using namespace std;

// Constructor

Polinomio::Polinomio(std::string arg) : x(symbol("x")), poly(SymEngine::Expression(SymEngine::zero)), first_derivative(SymEngine::zero), second_derivative(SymEngine::zero) {
    try {
        // Parseamos la expresión de entrada, esta devuelve un tipo RCP<const Basic>
        auto parsed_expr = SymEngine::parse(arg);

        // Asignamos la expresión parseada a poly (que es un alias para RCP<const Basic>)
        poly = SymEngine::Expression(parsed_expr);  // No es necesario hacer nada más, ya es un RCP<const Basic>

        // Calculamos las derivadas una vez que 'poly' ha sido inicializado correctamente
        first_derivative = diff(poly, x);
        second_derivative = diff(first_derivative, x);

        std::cout << "La expresion ingresada es valida: " << arg << std::endl;
    } catch (const SymEngine::ParseError &e) {
        // Si ocurre un error en el parseo, manejamos la excepción
        std::cerr << "Error: La expresion ingresada no es valida. Detalles: " << e.what() << std::endl;

        // Asignamos 'poly' con un valor de 0 usando el constructor adecuado de Expression
        poly = SymEngine::Expression(SymEngine::zero);  // Asignación correcta
        first_derivative = SymEngine::Expression(SymEngine::zero); // Asignamos la derivada también como cero
        second_derivative = SymEngine::Expression(SymEngine::zero); // Asignamos la segunda derivada como cero
    } catch (const std::exception &e) {
        // Manejo de otros errores
        std::cerr << "Error inesperado: " << e.what() << std::endl;

        // Asignamos 'poly' con un valor de 0 usando el constructor adecuado de Expression
        poly = SymEngine::Expression(SymEngine::zero);  // Asignación correcta
        first_derivative = SymEngine::Expression(SymEngine::zero); // Asignamos la derivada también como cero
        second_derivative = SymEngine::Expression(SymEngine::zero); // Asignamos la segunda derivada como cero
    }
};

void Polinomio::leerPolinomio(const string& user_input) {
    try {
        // Inicializar directamente poly usando el argumento recibido
        poly = Expression(parse(user_input));
    } catch (const std::exception& e) {
        cerr << "Error al procesar el polinomio ingresado: " << e.what() << endl;
    }
}

std::vector<double> Polinomio::getMaximos() {
    std::vector<double> maximos;
    for (const auto& punto : critical_points) {
        double punto_eval = SymEngine::eval_double(punto);
        double segunda_derivada_valor = evaluarSegundaDerivada(punto_eval);

        if (segunda_derivada_valor < 0) {  // Condición de máximo
            maximos.push_back(punto_eval);
            escribirLog("Máximo encontrado: x = " + QString::number(punto_eval));
        }
    }
    return maximos;
}

std::vector<double> Polinomio::getMinimos() {
    std::vector<double> minimos;
    for (const auto& punto : critical_points) {
        double punto_eval = SymEngine::eval_double(punto);
        double segunda_derivada_valor = evaluarSegundaDerivada(punto_eval);
        if (segunda_derivada_valor > 0) {  // Condición de mínimo
            minimos.push_back(punto_eval);
            escribirLog("Minimo encontrado: x = " + QString::number(punto_eval));
        }
    }
    return minimos;
}

void Polinomio::encontrarPuntosCriticos() {
    RCP<const Set> solutions = solve(first_derivative.get_basic(), x);

    if (is_a<FiniteSet>(*solutions)) {
        const auto &finite_set = down_cast<const FiniteSet &>(*solutions);
        for (const auto &point : finite_set.get_container()) {
            critical_points.push_back(Expression(point));
            escribirLog("Punto crítico encontrado: " + QString::number(SymEngine::eval_double(Expression(point))));
        }
    } else {
        escribirLog("No se encontraron puntos críticos.");
    }
}

std::vector<std::string> Polinomio::getPuntosCriticos() {
    std::vector<std::string> puntos_criticos_texto;

    if (critical_points.empty()) {
        puntos_criticos_texto.push_back("No se encontraron puntos críticos.");
    } else {
        for (const auto &point : critical_points) {
            puntos_criticos_texto.push_back("x = " + str(point));
        }
    }

    return puntos_criticos_texto;
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


double Polinomio::evaluar(double x_value) {
    SymEngine::map_basic_basic subs;
    subs[x] = SymEngine::rcp(new SymEngine::RealDouble(x_value));
    SymEngine::Expression result = poly.subs(subs);
    return SymEngine::eval_double(result);
}


double Polinomio::evaluarSegundaDerivada(double x_valor) {
    SymEngine::map_basic_basic subs;
    subs[x] = SymEngine::rcp(new SymEngine::RealDouble(x_valor));
    SymEngine::Expression result = second_derivative.subs(subs);

    return SymEngine::eval_double(result);
}

void Polinomio::escribirLog(const QString &mensaje) {
    QFile archivo("debug_log.txt");  // Usando una ruta relativa
    if (archivo.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&archivo);
        out << mensaje << "\n";
    } else {
        qDebug() << "Error al abrir el archivo para escritura.";
    }
}



