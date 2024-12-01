#ifndef INPUT_H
#define INPUT_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Input;
}

class Input : public QMainWindow
{
    Q_OBJECT

public:
    explicit Input(QWidget *parent = nullptr);
    ~Input();

private:
    Ui::Input *ui;
    MainWindow mw;
};

#endif // INPUT_H
