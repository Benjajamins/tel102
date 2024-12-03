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

    polinomio.encontrarPuntosCriticos();
    polinomio.clasificarPuntosCriticos();

    std::vector<std::string> puntos_criticos = polinomio.getPuntosCriticos();

    std::string clasificacion = "Puntos críticos:\n";
    for (const auto& punto : puntos_criticos) {
        clasificacion += punto + "\n";
    }
    ui->labelClasificacion->setText(QString::fromStdString(clasificacion));

    QLineSeries *series = new QLineSeries();
    double x_start = xmin;
    double x_end = xmax;
    double step = 0.1;

    for (double x_val = x_start; x_val <= x_end; x_val += step) {
        double y_val = polinomio.evaluar(x_val);
        series->append(x_val, y_val);
    }

    QScatterSeries *puntosSeries = new QScatterSeries();

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

    puntosSeries->setMarkerSize(10);  

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(puntosSeries);
    series->setName("Función");

    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(x_start, x_end);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    puntosSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(ymin, ymax);
    std::string polinomioTexto=strPol;
    axisY->setTitleText("f(x)= "+ QString::fromStdString(polinomioTexto));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    puntosSeries->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio: "+ QString::fromStdString(polinomioTexto));

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
    Polinomio polinomio(strPol);

    polinomio.encontrarPuntosCriticos();
    polinomio.clasificarPuntosCriticos();

    std::vector<std::string> puntos_criticos = polinomio.getPuntosCriticos();
    
    std::string clasificacion = "Puntos críticos:\n";
    for (const auto& punto : puntos_criticos) {
        clasificacion += punto + "\n";
    }
    ui->labelClasificacion->setText(QString::fromStdString(clasificacion));

    QLineSeries *series = new QLineSeries();
    double x_start = xmin;
    double x_end = xmax;
    double step = 0.1;

    for (double x_val = x_start; x_val <= x_end; x_val += step) {
        double y_val = polinomio.evaluar(x_val);
        series->append(x_val, y_val);
    }

    QScatterSeries *puntosSeries = new QScatterSeries();

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

    puntosSeries->setMarkerSize(10);  
    
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(puntosSeries);
    series->setName("Función");

    QValueAxis *axisX = new QValueAxis();
    axisX->setRange(x_start, x_end);
    axisX->setTitleText("x");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    puntosSeries->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(ymin, ymax);
    std::string polinomioTexto=strPol;
    axisY->setTitleText("f(x)= "+ QString::fromStdString(polinomioTexto));
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    puntosSeries->attachAxis(axisY);

    chart->setTitle("Gráfico del Polinomio: "+ QString::fromStdString(polinomioTexto));

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
