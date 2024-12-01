#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowTitle("Opti Fine");//título
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool esValido(const QString& input) {
    // Expresión regular para permitir solo números y 'x'
    QRegularExpression regex("^[0-9x^]+$");

    // Comprobar si el string coincide con la expresión regular
    QRegularExpressionMatch match = regex.match(input);

    // Si la coincidencia es válida, es un string válido
    return match.hasMatch();
}

void MainWindow::showErrorMessage(const QString& errorMessage)
{
    QMessageBox::warning(this,
                          "Error", // Título de la ventana de mensaje
                          errorMessage, // El mensaje que se muestra
                          QMessageBox::Ok); // Botón que cierra el cuadro de mensaje
}

void MainWindow::on_salir_clicked()
{
    QCoreApplication::quit();
}


void MainWindow::on_comboBox_activated(int index)//FALSE=MIN, TRUE=MAX
{
    maxmin=(index==1)? true:false;
    maxmin=(index==0)? true:false;
    qDebug()<<maxmin;
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    qDebug()<<arg1;
    textNow=arg1.toStdString();
}




void MainWindow::on_calcular_clicked()
{
    if (textNow.empty()) {
        showErrorMessage("El campo de texto está vacío. Por favor, ingrese un valor.");
    } if(!(esValido(QString::fromStdString(textNow)))){
        showErrorMessage("Ingrese sólo números y x's");
    }
    inputwindow *ventana = new inputwindow(textNow, maxmin, this);
    ventana->show();
}

