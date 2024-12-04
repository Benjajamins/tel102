#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), maxmin(true)
{
    ui->setupUi(this);
    setWindowTitle("Opti Fine");//título
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool esValido(const QString& input) {
    // Expresión regular para permitir solo números y 'x'
    QRegularExpression regex("^[0-9x^+-]+$");

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
        return;
    } if(!(esValido(QString::fromStdString(textNow)))){
        showErrorMessage("Ingrese sólo números y x's");
        return;
    }
    inputwindow *ventana = new inputwindow(textNow, maxmin, this);
    ventana->show();
}

void MainWindow::on_registro_clicked()
{
    // Ruta a la carpeta "registro"
    QString folderPath = QDir::currentPath() + "/registro";

    // Verificar si la carpeta existe
    if (!QDir(folderPath).exists())
    {
        QMessageBox::warning(this, "Error", "La carpeta de registro no existe.");
        return;
    }

    // Abrir la carpeta con el explorador de archivos predeterminado
    QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
}
