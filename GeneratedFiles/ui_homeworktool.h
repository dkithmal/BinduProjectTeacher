/********************************************************************************
** Form generated from reading UI file 'homeworktool.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWORKTOOL_H
#define UI_HOMEWORKTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWorkTool
{
public:
    QLabel *lHomeWork;
    QPushButton *pBClose;
    QGroupBox *groupBox;
    QPushButton *pBNewHomeWork;
    QRadioButton *rBNewHomeWrok;
    QRadioButton *rBNewShotNote;
    QGroupBox *groupBox_2;
    QPushButton *pBOpenExistingHw;
    QRadioButton *rBOpenHomeWork;
    QRadioButton *rBOpenNote;

    void setupUi(QWidget *HomeWorkTool)
    {
        if (HomeWorkTool->objectName().isEmpty())
            HomeWorkTool->setObjectName(QStringLiteral("HomeWorkTool"));
        HomeWorkTool->setEnabled(true);
        HomeWorkTool->resize(576, 294);
        lHomeWork = new QLabel(HomeWorkTool);
        lHomeWork->setObjectName(QStringLiteral("lHomeWork"));
        lHomeWork->setGeometry(QRect(200, 10, 181, 16));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        lHomeWork->setFont(font);
        pBClose = new QPushButton(HomeWorkTool);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(470, 240, 81, 31));
        groupBox = new QGroupBox(HomeWorkTool);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 50, 271, 171));
        QFont font1;
        font1.setPointSize(12);
        groupBox->setFont(font1);
        pBNewHomeWork = new QPushButton(groupBox);
        pBNewHomeWork->setObjectName(QStringLiteral("pBNewHomeWork"));
        pBNewHomeWork->setGeometry(QRect(80, 110, 111, 41));
        rBNewHomeWrok = new QRadioButton(groupBox);
        rBNewHomeWrok->setObjectName(QStringLiteral("rBNewHomeWrok"));
        rBNewHomeWrok->setGeometry(QRect(10, 40, 111, 31));
        rBNewHomeWrok->setFont(font1);
        rBNewHomeWrok->setIconSize(QSize(16, 16));
        rBNewShotNote = new QRadioButton(groupBox);
        rBNewShotNote->setObjectName(QStringLiteral("rBNewShotNote"));
        rBNewShotNote->setGeometry(QRect(140, 46, 101, 21));
        rBNewShotNote->setFont(font1);
        groupBox_2 = new QGroupBox(HomeWorkTool);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 50, 271, 171));
        groupBox_2->setFont(font1);
        pBOpenExistingHw = new QPushButton(groupBox_2);
        pBOpenExistingHw->setObjectName(QStringLiteral("pBOpenExistingHw"));
        pBOpenExistingHw->setGeometry(QRect(80, 110, 111, 41));
        rBOpenHomeWork = new QRadioButton(groupBox_2);
        rBOpenHomeWork->setObjectName(QStringLiteral("rBOpenHomeWork"));
        rBOpenHomeWork->setGeometry(QRect(20, 46, 111, 21));
        rBOpenHomeWork->setFont(font1);
        rBOpenNote = new QRadioButton(groupBox_2);
        rBOpenNote->setObjectName(QStringLiteral("rBOpenNote"));
        rBOpenNote->setGeometry(QRect(150, 46, 101, 21));
        rBOpenNote->setFont(font1);
        QWidget::setTabOrder(rBNewHomeWrok, rBNewShotNote);
        QWidget::setTabOrder(rBNewShotNote, pBNewHomeWork);
        QWidget::setTabOrder(pBNewHomeWork, rBOpenHomeWork);
        QWidget::setTabOrder(rBOpenHomeWork, rBOpenNote);
        QWidget::setTabOrder(rBOpenNote, pBOpenExistingHw);
        QWidget::setTabOrder(pBOpenExistingHw, pBClose);

        retranslateUi(HomeWorkTool);
        QObject::connect(pBClose, SIGNAL(clicked()), HomeWorkTool, SLOT(close()));

        QMetaObject::connectSlotsByName(HomeWorkTool);
    } // setupUi

    void retranslateUi(QWidget *HomeWorkTool)
    {
        HomeWorkTool->setWindowTitle(QApplication::translate("HomeWorkTool", "Home Work Tool", 0));
        lHomeWork->setText(QApplication::translate("HomeWorkTool", "Home Work Tool", 0));
        pBClose->setText(QApplication::translate("HomeWorkTool", "Close", 0));
        groupBox->setTitle(QApplication::translate("HomeWorkTool", "Create New One", 0));
        pBNewHomeWork->setText(QApplication::translate("HomeWorkTool", "Create ", 0));
        rBNewHomeWrok->setText(QApplication::translate("HomeWorkTool", "Home Work", 0));
        rBNewShotNote->setText(QApplication::translate("HomeWorkTool", "Short Note", 0));
        groupBox_2->setTitle(QApplication::translate("HomeWorkTool", "Open Existing one", 0));
        pBOpenExistingHw->setText(QApplication::translate("HomeWorkTool", "Open ", 0));
        rBOpenHomeWork->setText(QApplication::translate("HomeWorkTool", "Home Work", 0));
        rBOpenNote->setText(QApplication::translate("HomeWorkTool", "Short Note", 0));
    } // retranslateUi

};

namespace Ui {
    class HomeWorkTool: public Ui_HomeWorkTool {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWORKTOOL_H
