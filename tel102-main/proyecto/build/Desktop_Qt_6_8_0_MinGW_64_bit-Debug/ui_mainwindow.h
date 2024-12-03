/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *salir;
    QPushButton *registro;
    QPushButton *calcular;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 504);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        salir = new QPushButton(centralwidget);
        salir->setObjectName("salir");
        salir->setGeometry(QRect(30, 370, 141, 71));
        registro = new QPushButton(centralwidget);
        registro->setObjectName("registro");
        registro->setGeometry(QRect(620, 370, 141, 71));
        calcular = new QPushButton(centralwidget);
        calcular->setObjectName("calcular");
        calcular->setGeometry(QRect(410, 190, 91, 41));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(250, 190, 69, 22));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(250, 130, 251, 22));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 100, 211, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        salir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        registro->setText(QCoreApplication::translate("MainWindow", "Registro", nullptr));
        calcular->setText(QCoreApplication::translate("MainWindow", "Calcular", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Maximo", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "M\303\255nimo", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Ingrese funci\303\263n en t\303\251rminos de x", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
