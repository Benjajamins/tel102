#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QMainWindow>
#include "polinomio.h"
#include <QLineSeries>
#include <QChartView>
#include <QChart>
#include <QValueAxis>
#include <QVBoxLayout>
#include <QScatterSeries>

namespace Ui {
class inputwindow;
}

class inputwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputwindow(std::string texto, bool max_min, QWidget *parent = nullptr);
    ~inputwindow();
    void actualizarGrafico(double x_min, double x_max);
    void iniciarGrafico();

private slots:
    void on_xmin_valueChanged(double arg1);

    void on_xmax_valueChanged(double arg1);

    void on_xmin_2_valueChanged(double arg1);

    void on_xmax_2_valueChanged(double arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::inputwindow *ui;
    Polinomio pol;
    bool maxmin;
    std::string strPol;
    double xmin;
    double xmax;
    double ymin;
    double ymax;
};

#endif // INPUTWINDOW_H
