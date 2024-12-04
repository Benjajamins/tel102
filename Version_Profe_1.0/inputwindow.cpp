#include "inputwindow.h"
#include "ui_inputwindow.h"
#include "polinomio.h"
#include <QDir>
#include <QMessageBox>
#include <QPainter>
#include <QFileDialog>
using namespace SymEngine;

inputwindow::inputwindow(std::string texto, bool maxMin, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputwindow), pol(texto), xmax(100), xmin(-100), ymin(-100), ymax(100)
{
    ui->setupUi(this);
    setWindowTitle("Menú gráfico");
    resize(1366, 768);
    maxmin = maxMin;
    strPol = texto;
    ui->labelFuncion->setText(QString::fromStdString("Función modelada: " + texto));
    iniciarGrafico();
}

inputwindow::~inputwindow()
{
    delete ui;
}

void inputwindow::iniciarGrafico() {
    Polinomio polinomio(strPol);

    polinomio.encontrarPuntosCriticos(); //Encuentra los puntos criticos de la funcion.
    polinomio.clasificarPuntosCriticos();// Los clasifica.

    std::vector<double> maximos_valores = polinomio.getMaximos();//Obtiene los maximos de la funcion.
    std::vector<double> minimos_valores = polinomio.getMinimos();//Obtiene los minimos de la funcion


    std::string info;
    if (maxmin) { // Si existen maximos.
        info = "Máximos:\n"; // Muestra los maximos.
        for (double maximo : maximos_valores) { // itera todos los posibles maximos
            info += "x = " + std::to_string(maximo) + // transforma a string para despues mostrarlo en la ventana.
                    ", f(x) = " + std::to_string(polinomio.evaluar(maximo)) + "\n"; // lo mismo pero para y.
        }
    } else { // en caso de que no existan maximos entra a este bloque.
        info = "Mínimos:\n"; //Muestra los minimos
        for (double minimo : minimos_valores) { //itera todos los posibles minimos.
            info += "x = " + std::to_string(minimo) + // transforma a string los posibles minimos.
                    ", f(x) = " + std::to_string(polinomio.evaluar(minimo)) + "\n"; // lo mismo pero para y
        }
    }
    ui->labelClasificacion->setText(QString::fromStdString(info));

    QLineSeries *series = new QLineSeries(); // Crea un qlineseries para mostrar la funcion en el grafico
    double step = 0.1;
    for (double x_val = xmin; x_val <= xmax; x_val += step) {
        series->append(x_val, polinomio.evaluar(x_val));
    }

    // Crear la serie para los puntos críticos
    QScatterSeries *puntosSeries = new QScatterSeries();
    puntosSeries->setMarkerSize(10);

    if (maxmin) {
        // Mostrar máximos en rojo
        puntosSeries->setColor(Qt::red);
        puntosSeries->setName("Máximos");
        for (double punto : maximos_valores) {
            puntosSeries->append(punto, polinomio.evaluar(punto));
        }
    } else {
        // Mostrar mínimos en azul
        puntosSeries->setColor(Qt::blue);
        puntosSeries->setName("Mínimos");
        for (double punto : minimos_valores) {
            puntosSeries->append(punto, polinomio.evaluar(punto));
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(puntosSeries);
    series->setName("Función");

    // Configurar los ejes X e Y
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(xmin, xmax);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    puntosSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(ymin, ymax);
    std::string polinomioTexto = strPol;
    axisY->setTitleText("f(x)= " + QString::fromStdString(polinomioTexto));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    puntosSeries->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio: " + QString::fromStdString(polinomioTexto));

    // Crear vista y reemplazar el layout
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Limpiar layout anterior antes de agregar el nuevo gráfico
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);

    if (ui->graphicsView->layout() != nullptr) {
        QLayoutItem *item;
        while ((item = ui->graphicsView->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete ui->graphicsView->layout();
    }

    ui->graphicsView->setLayout(layout);
}



void inputwindow::actualizarGrafico(double x_min, double x_max) {
    Polinomio polinomio(strPol);

    // Encontrar y clasificar puntos críticos
    polinomio.encontrarPuntosCriticos();
    polinomio.clasificarPuntosCriticos();

    // Obtener máximos y mínimos
    std::vector<double> maximos_valores = polinomio.getMaximos();
    std::vector<double> minimos_valores = polinomio.getMinimos();

    // Construir el texto para mostrar en el QLabel
    std::string info;
    if (maxmin) {
        // Mostrar solo máximos
        info = "Máximos:\n";
        for (double maximo : maximos_valores) {
            info += "x = " + std::to_string(maximo) +
                    ", f(x) = " + std::to_string(polinomio.evaluar(maximo)) + "\n";
        }
    } else {
        // Mostrar solo mínimos
        info = "Mínimos:\n";
        for (double minimo : minimos_valores) {
            info += "x = " + std::to_string(minimo) +
                    ", f(x) = " + std::to_string(polinomio.evaluar(minimo)) + "\n";
        }
    }
    ui->labelClasificacion->setText(QString::fromStdString(info));

    // Crear la serie para la función
    QLineSeries *series = new QLineSeries();
    double step = 0.1;
    for (double x_val = xmin; x_val <= xmax; x_val += step) {
        series->append(x_val, polinomio.evaluar(x_val));
    }

    // Crear la serie para los puntos críticos
    QScatterSeries *puntosSeries = new QScatterSeries();
    puntosSeries->setMarkerSize(10);

    if (maxmin) {
        // Mostrar máximos en rojo
        puntosSeries->setColor(Qt::red);
        puntosSeries->setName("Máximos");
        for (double punto : maximos_valores) {
            puntosSeries->append(punto, polinomio.evaluar(punto));
        }
    } else {
        // Mostrar mínimos en azul
        puntosSeries->setColor(Qt::blue);
        puntosSeries->setName("Mínimos");
        for (double punto : minimos_valores) {
            puntosSeries->append(punto, polinomio.evaluar(punto));
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(puntosSeries);
    series->setName("Función");

    // Configurar los ejes X e Y
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(xmin, xmax);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    puntosSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(ymin, ymax);
    std::string polinomioTexto = strPol;
    axisY->setTitleText("f(x)= " + QString::fromStdString(polinomioTexto));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    puntosSeries->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio: " + QString::fromStdString(polinomioTexto));

    // Crear vista y reemplazar el layout
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Limpiar layout anterior antes de agregar el nuevo gráfico
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(chartView);

    if (ui->graphicsView->layout() != nullptr) {
        QLayoutItem *item;
        while ((item = ui->graphicsView->layout()->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete ui->graphicsView->layout();
    }

    ui->graphicsView->setLayout(layout);
}


// Cambios en las spinboxes
void inputwindow::on_xmin_valueChanged(double arg1) {
    xmin = arg1;
    actualizarGrafico(arg1, xmax);
}

void inputwindow::on_xmax_valueChanged(double arg1) {
    xmax = arg1;
    actualizarGrafico(xmin, arg1);
}

void inputwindow::on_xmin_2_valueChanged(double arg1) {
    ymin = arg1;
    actualizarGrafico(xmin, xmax);
}

void inputwindow::on_xmax_2_valueChanged(double arg1) {
    ymax = arg1;
    actualizarGrafico(xmin, xmax);
}

void inputwindow::on_pushButton_2_clicked()
{
    this->close();
}


void inputwindow::on_pushButton_clicked()
{
    // Crear la carpeta "registro" si no existe
    QDir dir("registro");
    if (!dir.exists())
    {
        dir.mkpath("."); // Crea la carpeta si no existe
    }

    // Abrir un cuadro de diálogo para que el usuario elija el nombre del archivo
    QString defaultFileName = dir.filePath("grafico.png");
    QString filePath = QFileDialog::getSaveFileName(
        this,
        "Guardar gráfico como",
        defaultFileName,
        "Imágenes (*.png)");

    // Si el usuario cancela, salimos del método
    if (filePath.isEmpty())
        return;

    // Capturar el contenido del gráfico como imagen
    QChartView *chartView = qobject_cast<QChartView *>(ui->graphicsView->layout()->itemAt(0)->widget());
    if (!chartView)
    {
        QMessageBox::warning(this, "Error", "No se pudo encontrar el gráfico para guardar.");
        return;
    }

    QPixmap pixmap(chartView->size());
    QPainter painter(&pixmap);
    chartView->render(&painter);

    // Guardar la imagen como archivo PNG
    if (pixmap.save(filePath))
    {
        QMessageBox::information(this, "Éxito", "Gráfico guardado en: " + filePath);
    }
    else
    {
        QMessageBox::warning(this, "Error", "No se pudo guardar el gráfico.");
    }

    // Cerrar la ventana después de guardar
    this->close();
}

