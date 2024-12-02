#include "inputwindow.h"
#include "ui_inputwindow.h"
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
    QLineSeries *series = new QLineSeries();
    double x_start = -100.0;
    double x_end = 100.0;
    double step = 0.1;

    for (double x_val = x_start; x_val <= x_end; x_val += step) {
        double y_val = pol.evaluar(x_val);
        series->append(x_val, y_val);
    }
    QScatterSeries *puntosSeries = new QScatterSeries();

    if (maxmin) {
        qDebug() << "Buscando máximos...";
        std::vector<double> maximos = pol.getMaximos();
        for (double punto : maximos) {
            double y = pol.evaluar(punto);
            puntosSeries->append(punto, y);
            qDebug() << "[Gráfico] Máximo agregado: x =" << punto << ", y =" << y;
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
        }
        puntosSeries->setColor(Qt::blue);
        puntosSeries->setName("Mínimos");
    }

    puntosSeries->setMarkerSize(10); // Configurar el tamaño de los puntos

    // Crear el gráfico
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(puntosSeries);
    series->setName("Función");

    // Configurar ejes X e Y
    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(x_start, x_end);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    puntosSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    double y_start = -100.0; // Puedes ajustar dinámicamente si lo deseas
    double y_end = 100.0;
    axisY->setRange(y_start, y_end);
    axisY->setTitleText("f(x)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    puntosSeries->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio");

    // Crear vista y reemplazar el layout
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

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

    if (maxmin) {
        qDebug() << "Buscando máximos...";
        std::vector<double> maximos = pol.getMaximos();
        for (double punto : maximos) {
            double y = pol.evaluar(punto);
            puntosSeries->append(punto, y);
            qDebug() << "[Gráfico] Máximo agregado: x =" << punto << ", y =" << y;
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
        }
        puntosSeries->setColor(Qt::blue);
        puntosSeries->setName("Mínimos");
    }

    puntosSeries->setMarkerSize(10);
    QChart *chart = new QChart();

    chart->removeAllSeries();

    chart->addSeries(series);

    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(x_start, x_end);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(ymin, ymax);
    axisY->setTitleText("f(x)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

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

