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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenHomeWork
{
public:
    QLabel *lSelectSubject;
    QLabel *lSelectPaper;
    QPushButton *pBOpen;
    QPushButton *pBClose;
    QPushButton *pBDeleteHomeWork;
    QTreeWidget *tWSelectSubject;
    QListWidget *lWHomeWorks;

    void setupUi(QWidget *OpenHomeWork)
    {
        if (OpenHomeWork->objectName().isEmpty())
            OpenHomeWork->setObjectName(QStringLiteral("OpenHomeWork"));
        OpenHomeWork->resize(662, 450);
        QFont font;
        font.setPointSize(12);
        OpenHomeWork->setFont(font);
        lSelectSubject = new QLabel(OpenHomeWork);
        lSelectSubject->setObjectName(QStringLiteral("lSelectSubject"));
        lSelectSubject->setGeometry(QRect(20, 5, 121, 21));
        lSelectSubject->setFont(font);
        lSelectPaper = new QLabel(OpenHomeWork);
        lSelectPaper->setObjectName(QStringLiteral("lSelectPaper"));
        lSelectPaper->setGeometry(QRect(330, 0, 101, 31));
        lSelectPaper->setFont(font);
        pBOpen = new QPushButton(OpenHomeWork);
        pBOpen->setObjectName(QStringLiteral("pBOpen"));
        pBOpen->setGeometry(QRect(490, 370, 161, 31));
        pBClose = new QPushButton(OpenHomeWork);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(570, 410, 75, 31));
        pBDeleteHomeWork = new QPushButton(OpenHomeWork);
        pBDeleteHomeWork->setObjectName(QStringLiteral("pBDeleteHomeWork"));
        pBDeleteHomeWork->setGeometry(QRect(330, 370, 141, 31));
        tWSelectSubject = new QTreeWidget(OpenHomeWork);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectSubject->setHeaderItem(__qtreewidgetitem);
        tWSelectSubject->setObjectName(QStringLiteral("tWSelectSubject"));
        tWSelectSubject->setGeometry(QRect(10, 30, 301, 411));
        tWSelectSubject->setFont(font);
        tWSelectSubject->setSortingEnabled(false);
        tWSelectSubject->header()->setVisible(false);
        lWHomeWorks = new QListWidget(OpenHomeWork);
        lWHomeWorks->setObjectName(QStringLiteral("lWHomeWorks"));
        lWHomeWorks->setGeometry(QRect(330, 30, 321, 331));
        lWHomeWorks->setFont(font);
        lWHomeWorks->setSortingEnabled(true);
        QWidget::setTabOrder(tWSelectSubject, lWHomeWorks);
        QWidget::setTabOrder(lWHomeWorks, pBOpen);
        QWidget::setTabOrder(pBOpen, pBDeleteHomeWork);
        QWidget::setTabOrder(pBDeleteHomeWork, pBClose);

        retranslateUi(OpenHomeWork);
        QObject::connect(pBClose, SIGNAL(clicked()), OpenHomeWork, SLOT(close()));

        QMetaObject::connectSlotsByName(OpenHomeWork);
    } // setupUi

    void retranslateUi(QWidget *OpenHomeWork)
    {
        OpenHomeWork->setWindowTitle(QApplication::translate("OpenHomeWork", "Select Home Work To Open", 0));
        lSelectSubject->setText(QApplication::translate("OpenHomeWork", "Select Subject", 0));
        lSelectPaper->setText(QApplication::translate("OpenHomeWork", "Select paper", 0));
        pBOpen->setText(QApplication::translate("OpenHomeWork", "Open", 0));
        pBClose->setText(QApplication::translate("OpenHomeWork", "Close", 0));
        pBDeleteHomeWork->setText(QApplication::translate("OpenHomeWork", "Delete Home Work", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenHomeWork: public Ui_OpenHomeWork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENHOMEWORK_H
