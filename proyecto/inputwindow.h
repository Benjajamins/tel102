#ifndef INPUTWINDOW_H
#define INPUTWINDOW_H

#include <QMainWindow>
#include "polinomio.h"

namespace Ui {
class inputwindow;
}

class inputwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit inputwindow(std::string texto, bool max_min, QWidget *parent = nullptr);
    ~inputwindow();

private:
    Ui::inputwindow *ui;
    SymEngine::Expression pol;
    bool maxmin;
};

#endif // INPUTWINDOW_H
