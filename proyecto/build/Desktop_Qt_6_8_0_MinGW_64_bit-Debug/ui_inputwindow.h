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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inputwindow
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *inputwindow)
    {
        if (inputwindow->objectName().isEmpty())
            inputwindow->setObjectName("inputwindow");
        inputwindow->resize(687, 187);
        centralwidget = new QWidget(inputwindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(170, 40, 321, 71));
        inputwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(inputwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 687, 22));
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
        textEdit->setHtml(QCoreApplication::translate("inputwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class inputwindow: public Ui_inputwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTWINDOW_H
