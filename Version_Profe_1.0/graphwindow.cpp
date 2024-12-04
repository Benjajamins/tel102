#include "graphwindow.h"
#include "ui_graphwindow.h"

graphWindow::graphWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::graphWindow), mw(new MainWindow)
{
    ui->setupUi(this);}

graphWindow::~graphWindow()
{
    delete ui;
}
