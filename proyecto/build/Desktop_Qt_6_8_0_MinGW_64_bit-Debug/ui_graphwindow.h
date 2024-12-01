/********************************************************************************
** Form generated from reading UI file 'graphwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHWINDOW_H
#define UI_GRAPHWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graphWindow)
    {
        if (graphWindow->objectName().isEmpty())
            graphWindow->setObjectName("graphWindow");
        graphWindow->resize(692, 356);
        centralwidget = new QWidget(graphWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(290, 140, 181, 41));
        graphWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(graphWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 692, 22));
        graphWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(graphWindow);
        statusbar->setObjectName("statusbar");
        graphWindow->setStatusBar(statusbar);

        retranslateUi(graphWindow);

        QMetaObject::connectSlotsByName(graphWindow);
    } // setupUi

    void retranslateUi(QMainWindow *graphWindow)
    {
        graphWindow->setWindowTitle(QCoreApplication::translate("graphWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphWindow: public Ui_graphWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHWINDOW_H
