#include "inputwindow.h"
#include "ui_inputwindow.h"
using namespace SymEngine;
inputwindow::inputwindow(std::string texto, bool maxMin, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputwindow)
{
    setWindowTitle("Menú función");
    resize(1366, 768);
    maxmin=maxMin;
    std::string strPol(texto);
    Polinomio polinomio(texto);
}

inputwindow::~inputwindow()
{
    delete ui;
}
