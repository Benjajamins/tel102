#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "polinomio.h"
#include "inputwindow.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showErrorMessage(const QString& errorMessage);

private slots:

    void on_salir_clicked();

    void on_comboBox_activated(int index);

    void on_lineEdit_textEdited(const QString &arg1);


    void on_calcular_clicked();

private:
    Ui::MainWindow *ui;
protected:
    bool maxmin;
    std::string textNow;
};
#endif // MAINWINDOW_H
