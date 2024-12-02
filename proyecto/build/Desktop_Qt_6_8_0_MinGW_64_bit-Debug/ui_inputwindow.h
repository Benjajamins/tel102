/********************************************************************************
** Form generated from reading UI file 'inputwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTWINDOW_H
#define UI_INPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputwindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QDoubleSpinBox *xmin;
    QDoubleSpinBox *xmax;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *labelFuncion;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QDoubleSpinBox *xmin_2;
    QDoubleSpinBox *xmax_2;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *inputwindow)
    {
        if (inputwindow->objectName().isEmpty())
            inputwindow->setObjectName("inputwindow");
        inputwindow->resize(1366, 768);
        centralwidget = new QWidget(inputwindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(40, 30, 851, 651));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(1080, 30, 121, 16));
        xmin = new QDoubleSpinBox(centralwidget);
        xmin->setObjectName("xmin");
        xmin->setGeometry(QRect(1040, 90, 62, 22));
        xmin->setMinimum(-9999.000000000000000);
        xmin->setMaximum(9999.000000000000000);
        xmin->setSingleStep(10.000000000000000);
        xmin->setValue(-100.000000000000000);
        xmax = new QDoubleSpinBox(centralwidget);
        xmax->setObjectName("xmax");
        xmax->setGeometry(QRect(1220, 90, 62, 22));
        xmax->setMinimum(-9999.000000000000000);
        xmax->setMaximum(9999.000000000000000);
        xmax->setSingleStep(10.000000000000000);
        xmax->setValue(100.000000000000000);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1000, 90, 21, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1140, 90, 41, 16));
        labelFuncion = new QLabel(centralwidget);
        labelFuncion->setObjectName("labelFuncion");
        labelFuncion->setGeometry(QRect(940, 240, 241, 71));
        labelFuncion->setTextFormat(Qt::TextFormat::AutoText);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(950, 90, 21, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(950, 160, 21, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1000, 160, 21, 16));
        xmin_2 = new QDoubleSpinBox(centralwidget);
        xmin_2->setObjectName("xmin_2");
        xmin_2->setGeometry(QRect(1040, 160, 62, 22));
        xmin_2->setMinimum(-9999.000000000000000);
        xmin_2->setMaximum(9999.000000000000000);
        xmin_2->setSingleStep(10.000000000000000);
        xmin_2->setValue(-100.000000000000000);
        xmax_2 = new QDoubleSpinBox(centralwidget);
        xmax_2->setObjectName("xmax_2");
        xmax_2->setGeometry(QRect(1220, 160, 62, 22));
        xmax_2->setMinimum(-9999.000000000000000);
        xmax_2->setMaximum(9999.000000000000000);
        xmax_2->setSingleStep(10.000000000000000);
        xmax_2->setValue(100.000000000000000);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(1140, 160, 41, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1090, 340, 91, 16));
        inputwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(inputwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1366, 22));
        inputwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(inputwindow);
        statusbar->setObjectName("statusbar");
        inputwindow->setStatusBar(statusbar);

        retranslateUi(inputwindow);

        QMetaObject::connectSlotsByName(inputwindow);
    } // setupUi

    void retranslateUi(QMainWindow *inputwindow)
    {
        inputwindow->setWindowTitle(QCoreApplication::translate("inputwindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("inputwindow", "Opciones de gr\303\241fica", nullptr));
        xmin->setPrefix(QString());
        label_2->setText(QCoreApplication::translate("inputwindow", "De", nullptr));
        label_3->setText(QCoreApplication::translate("inputwindow", "Hasta", nullptr));
        labelFuncion->setText(QCoreApplication::translate("inputwindow", "Funci\303\263n modelada:", nullptr));
        label_4->setText(QCoreApplication::translate("inputwindow", "X:", nullptr));
        label_5->setText(QCoreApplication::translate("inputwindow", "Y:", nullptr));
        label_6->setText(QCoreApplication::translate("inputwindow", "De", nullptr));
        xmin_2->setPrefix(QString());
        label_7->setText(QCoreApplication::translate("inputwindow", "Hasta", nullptr));
        label_8->setText(QCoreApplication::translate("inputwindow", "Puntos cr\303\255ticos", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputwindow: public Ui_inputwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTWINDOW_H
