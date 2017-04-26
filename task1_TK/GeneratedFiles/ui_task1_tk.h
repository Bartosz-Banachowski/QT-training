/********************************************************************************
** Form generated from reading UI file 'task1_tk.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK1_TK_H
#define UI_TASK1_TK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_task1_TKClass
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QPushButton *buttonK;
    QPushButton *buttonD;
    QPushButton *buttonB;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *task1_TKClass)
    {
        if (task1_TKClass->objectName().isEmpty())
            task1_TKClass->setObjectName(QStringLiteral("task1_TKClass"));
        task1_TKClass->resize(656, 730);
        centralWidget = new QWidget(task1_TKClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(330, 90, 261, 251));
        buttonK = new QPushButton(centralWidget);
        buttonK->setObjectName(QStringLiteral("buttonK"));
        buttonK->setGeometry(QRect(90, 220, 141, 61));
        buttonD = new QPushButton(centralWidget);
        buttonD->setObjectName(QStringLiteral("buttonD"));
        buttonD->setGeometry(QRect(90, 430, 141, 61));
        buttonB = new QPushButton(centralWidget);
        buttonB->setObjectName(QStringLiteral("buttonB"));
        buttonB->setGeometry(QRect(90, 330, 141, 61));
        textBrowser_3 = new QTextBrowser(centralWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(340, 30, 241, 41));
        textBrowser_4 = new QTextBrowser(centralWidget);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(60, 90, 221, 51));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(310, 380, 301, 251));
        task1_TKClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(task1_TKClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 656, 21));
        task1_TKClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(task1_TKClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        task1_TKClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(task1_TKClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        task1_TKClass->setStatusBar(statusBar);

        retranslateUi(task1_TKClass);

        QMetaObject::connectSlotsByName(task1_TKClass);
    } // setupUi

    void retranslateUi(QMainWindow *task1_TKClass)
    {
        task1_TKClass->setWindowTitle(QApplication::translate("task1_TKClass", "task1_TK", 0));
        textBrowser->setHtml(QApplication::translate("task1_TKClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        buttonK->setText(QApplication::translate("task1_TKClass", "KODOWANIE", 0));
        buttonD->setText(QApplication::translate("task1_TKClass", "DEKODOWANIE", 0));
        buttonB->setText(QApplication::translate("task1_TKClass", "ZROB BLAD", 0));
        textBrowser_3->setHtml(QApplication::translate("task1_TKClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        textBrowser_4->setHtml(QApplication::translate("task1_TKClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600;\">Bartosz Banachowski 203849<br />\305\201ukasz Rogozi\305\204ski 203979</span></p></body></html>", 0));
        textBrowser_2->setHtml(QApplication::translate("task1_TKClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class task1_TKClass: public Ui_task1_TKClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK1_TK_H
