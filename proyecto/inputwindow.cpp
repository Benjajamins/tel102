#include "inputwindow.h"
#include "ui_inputwindow.h"
#include "polinomio.h"
using namespace SymEngine;
inputwindow::inputwindow(std::string texto, bool maxMin, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::inputwindow), pol(texto), xmax(100), xmin(-100), ymin(-100), ymax(100)
{
    ui->setupUi(this);
    setWindowTitle("Menú gráfico");
    resize(1366, 768);
    maxmin=maxMin;
    strPol=texto;
    ui->labelFuncion->setText(QString::fromStdString("Función modelada: " + texto));
    iniciarGrafico();
}


inputwindow::~inputwindow()
{
    delete ui;
}

void inputwindow::iniciarGrafico() {

    Polinomio polinomio(strPol);

    polinomio.encontrarPuntosCriticos();

    polinomio.clasificarPuntosCriticos();

    std::vector<std::string> puntos_criticos = polinomio.getPuntosCriticos();


    std::string clasificacion = "Puntos críticos:\n";
    for (const auto& punto : puntos_criticos) {
        clasificacion += punto + "\n";
    }
    ui->labelClasificacion->setText(QString::fromStdString(clasificacion));

    // Crear una serie para la función
    QLineSeries *series = new QLineSeries();
    double x_start = xmin;
    double x_end = xmax;
    double step = 0.1;

    // Añadir puntos de la función al gráfico
    for (double x_val = x_start; x_val <= x_end; x_val += step) {
        double y_val = polinomio.evaluar(x_val);
        series->append(x_val, y_val);
    }

    // Crear la serie para los puntos críticos
    QScatterSeries *puntosSeries = new QScatterSeries();

    // Decidir si mostrar máximos o mínimos
    if (maxmin) {
        qDebug() << "Buscando máximos...";
        std::vector<double> maximos = polinomio.getMaximos();
        for (double punto : maximos) {
            double y = polinomio.evaluar(punto);
            puntosSeries->append(punto, y);
            qDebug() << "[Gráfico] Máximo agregado: x =" << punto << ", y =" << y;
        }
        puntosSeries->setColor(Qt::red);
        puntosSeries->setName("Máximos");
    } else {
        qDebug() << "Buscando mínimos...";
        std::vector<double> minimos = polinomio.getMinimos();
        for (double punto : minimos) {
            double y = polinomio.evaluar(punto);
            puntosSeries->append(punto, y);
            qDebug() << "[Gráfico] Mínimo agregado: x =" << punto << ", y =" << y;
        }
        puntosSeries->setColor(Qt::blue);
        puntosSeries->setName("Mínimos");
    }

    puntosSeries->setMarkerSize(10);  // Configurar el tamaño de los puntos

    // Crear el gráfico
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(puntosSeries);
    series->setName("Función");

    // Configurar los ejes X e Y
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(x_start, x_end);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    puntosSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(ymin, ymax);
    axisY->setTitleText("f(x)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    puntosSeries->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio");

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
    QLineSeries *series = new QLineSeries();
    series->setName("Función");
    double x_start = x_min;
    double x_end = x_max;
    double step = 0.1;

    for (double x_val = x_start; x_val <= x_end; x_val += step) {
        double y_val = pol.evaluar(x_val);
        series->append(x_val, y_val);
    }

    QScatterSeries *puntosSeries = new QScatterSeries();

    // Buscando máximos o mínimos según la variable `maxmin`
    if (maxmin) {
        qDebug() << "Buscando máximos...";
        std::vector<double> maximos = pol.getMaximos();
        for (double punto : maximos) {
            double y = pol.evaluar(punto);
            puntosSeries->append(punto, y);
            qDebug() << "[Gráfico] Máximo agregado: x =" << punto << ", y =" << y;

            // Agregar etiqueta de "Máximo" al gráfico
            QGraphicsTextItem *maxLabel = new QGraphicsTextItem(QString("Máximo: x = %1, y = %2").arg(punto).arg(y));
            maxLabel->setPos(punto, y);  // Posicionar la etiqueta cerca del punto
            ui->graphicsView->scene()->addItem(maxLabel);  // Añadir la etiqueta al gráfico
        }
        puntosSeries->setColor(Qt::red);
        puntosSeries->setName("Máximos");
    } else {
        qDebug() << "Buscando mínimos...";
        std::vector<double> minimos = pol.getMinimos();
        for (double punto : minimos) {
            double y = pol.evaluar(punto);
            puntosSeries->append(punto, y);
            qDebug() << "[Gráfico] Mínimo agregado: x =" << punto << ", y =" << y;

            // Agregar etiqueta de "Mínimo" al gráfico
            QGraphicsTextItem *minLabel = new QGraphicsTextItem(QString("Mínimo: x = %1, y = %2").arg(punto).arg(y));
            minLabel->setPos(punto, y);  // Posicionar la etiqueta cerca del punto
            ui->graphicsView->scene()->addItem(minLabel);  // Añadir la etiqueta al gráfico
        }
        puntosSeries->setColor(Qt::blue);
        puntosSeries->setName("Mínimos");
    }

    puntosSeries->setMarkerSize(10);

    // Crear el gráfico
    QChart *chart = new QChart();
    chart->removeAllSeries();
    chart->addSeries(series);

    // Configurar los ejes
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(x_start, x_end);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(ymin, ymax);  // Asumiendo que ymin y ymax están definidos correctamente
    axisY->setTitleText("f(x)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio");

    // Crear la vista del gráfico
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Limpiar el layout actual antes de agregar el nuevo gráfico
    QLayout *layout = ui->graphicsView->layout();
    if (layout != nullptr) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
    }

    layout->addWidget(chartView);
    ui->graphicsView->setLayout(layout);
}


void inputwindow::on_xmin_valueChanged(double arg1)
{
    xmin=arg1;
    actualizarGrafico(arg1, xmax);
}


void inputwindow::on_xmax_valueChanged(double arg1)
{
    xmax=arg1;
    actualizarGrafico(xmin, arg1);
}


void inputwindow::on_xmin_2_valueChanged(double arg1)
{
    ymin=arg1;
    actualizarGrafico(xmin,xmax);
}


void inputwindow::on_xmax_2_valueChanged(double arg1)
{
    ymax=arg1;
    actualizarGrafico(xmin,xmax);
}


