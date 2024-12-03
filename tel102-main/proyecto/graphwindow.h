#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class graphWindow;
}

class graphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit graphWindow(QWidget *parent = nullptr);
    ~graphWindow();

private:
    Ui::graphWindow *ui;
    MainWindow *mw;
};

#endif // GRAPHWINDOW_H
