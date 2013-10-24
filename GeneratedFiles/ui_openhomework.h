/********************************************************************************
** Form generated from reading UI file 'openhomework.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENHOMEWORK_H
#define UI_OPENHOMEWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenHomeWork
{
public:
    QTreeView *treeView;
    QLabel *lSelectSubject;
    QLabel *lSelectPaper;
    QListView *listView;
    QPushButton *pBOpen;
    QPushButton *pBClose;

    void setupUi(QWidget *OpenHomeWork)
    {
        if (OpenHomeWork->objectName().isEmpty())
            OpenHomeWork->setObjectName(QStringLiteral("OpenHomeWork"));
        OpenHomeWork->resize(800, 450);
        treeView = new QTreeView(OpenHomeWork);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(10, 30, 411, 401));
        lSelectSubject = new QLabel(OpenHomeWork);
        lSelectSubject->setObjectName(QStringLiteral("lSelectSubject"));
        lSelectSubject->setGeometry(QRect(20, 5, 121, 21));
        QFont font;
        font.setPointSize(12);
        lSelectSubject->setFont(font);
        lSelectPaper = new QLabel(OpenHomeWork);
        lSelectPaper->setObjectName(QStringLiteral("lSelectPaper"));
        lSelectPaper->setGeometry(QRect(430, 5, 101, 21));
        lSelectPaper->setFont(font);
        listView = new QListView(OpenHomeWork);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(430, 30, 361, 331));
        pBOpen = new QPushButton(OpenHomeWork);
        pBOpen->setObjectName(QStringLiteral("pBOpen"));
        pBOpen->setGeometry(QRect(430, 370, 361, 31));
        pBClose = new QPushButton(OpenHomeWork);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(710, 410, 75, 31));

        retranslateUi(OpenHomeWork);
        QObject::connect(pBClose, SIGNAL(clicked()), OpenHomeWork, SLOT(close()));

        QMetaObject::connectSlotsByName(OpenHomeWork);
    } // setupUi

    void retranslateUi(QWidget *OpenHomeWork)
    {
        OpenHomeWork->setWindowTitle(QApplication::translate("OpenHomeWork", "Form", 0));
        lSelectSubject->setText(QApplication::translate("OpenHomeWork", "Select Subject", 0));
        lSelectPaper->setText(QApplication::translate("OpenHomeWork", "Select paper", 0));
        pBOpen->setText(QApplication::translate("OpenHomeWork", "Open", 0));
        pBClose->setText(QApplication::translate("OpenHomeWork", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenHomeWork: public Ui_OpenHomeWork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENHOMEWORK_H
