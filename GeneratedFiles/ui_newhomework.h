/********************************************************************************
** Form generated from reading UI file 'newhomework.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWHOMEWORK_H
#define UI_NEWHOMEWORK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewHomeWork
{
public:
    QLabel *lPaperName;
    QLabel *lSelectSubject;
    QLineEdit *lEPaperName;
    QLabel *lDuration;
    QLineEdit *lEDuration;
    QGroupBox *gBSelectType;
    QRadioButton *rBMcq;
    QRadioButton *rBEssay;
    QRadioButton *rBEssayMcq;
    QPushButton *pBCreatePaper;
    QPushButton *pBClose;
    QTreeWidget *tWSelectSubject;

    void setupUi(QWidget *NewHomeWork)
    {
        if (NewHomeWork->objectName().isEmpty())
            NewHomeWork->setObjectName(QStringLiteral("NewHomeWork"));
        NewHomeWork->resize(781, 447);
        QFont font;
        font.setPointSize(12);
        NewHomeWork->setFont(font);
        lPaperName = new QLabel(NewHomeWork);
        lPaperName->setObjectName(QStringLiteral("lPaperName"));
        lPaperName->setGeometry(QRect(400, 10, 91, 21));
        lPaperName->setFont(font);
        lSelectSubject = new QLabel(NewHomeWork);
        lSelectSubject->setObjectName(QStringLiteral("lSelectSubject"));
        lSelectSubject->setGeometry(QRect(10, 5, 111, 21));
        lSelectSubject->setFont(font);
        lEPaperName = new QLineEdit(NewHomeWork);
        lEPaperName->setObjectName(QStringLiteral("lEPaperName"));
        lEPaperName->setGeometry(QRect(400, 40, 371, 31));
        lDuration = new QLabel(NewHomeWork);
        lDuration->setObjectName(QStringLiteral("lDuration"));
        lDuration->setGeometry(QRect(400, 80, 71, 16));
        lDuration->setFont(font);
        lEDuration = new QLineEdit(NewHomeWork);
        lEDuration->setObjectName(QStringLiteral("lEDuration"));
        lEDuration->setGeometry(QRect(400, 110, 371, 31));
        gBSelectType = new QGroupBox(NewHomeWork);
        gBSelectType->setObjectName(QStringLiteral("gBSelectType"));
        gBSelectType->setGeometry(QRect(400, 150, 371, 111));
        gBSelectType->setFont(font);
        rBMcq = new QRadioButton(gBSelectType);
        rBMcq->setObjectName(QStringLiteral("rBMcq"));
        rBMcq->setGeometry(QRect(50, 30, 82, 17));
        rBEssay = new QRadioButton(gBSelectType);
        rBEssay->setObjectName(QStringLiteral("rBEssay"));
        rBEssay->setGeometry(QRect(50, 50, 82, 17));
        rBEssayMcq = new QRadioButton(gBSelectType);
        rBEssayMcq->setObjectName(QStringLiteral("rBEssayMcq"));
        rBEssayMcq->setGeometry(QRect(50, 70, 131, 17));
        pBCreatePaper = new QPushButton(NewHomeWork);
        pBCreatePaper->setObjectName(QStringLiteral("pBCreatePaper"));
        pBCreatePaper->setGeometry(QRect(400, 270, 371, 41));
        pBClose = new QPushButton(NewHomeWork);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(680, 380, 75, 31));
        tWSelectSubject = new QTreeWidget(NewHomeWork);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectSubject->setHeaderItem(__qtreewidgetitem);
        tWSelectSubject->setObjectName(QStringLiteral("tWSelectSubject"));
        tWSelectSubject->setGeometry(QRect(10, 40, 371, 391));
        tWSelectSubject->setFont(font);
        tWSelectSubject->setSortingEnabled(true);
        tWSelectSubject->header()->setVisible(false);

        retranslateUi(NewHomeWork);
        QObject::connect(pBClose, SIGNAL(clicked()), NewHomeWork, SLOT(close()));

        QMetaObject::connectSlotsByName(NewHomeWork);
    } // setupUi

    void retranslateUi(QWidget *NewHomeWork)
    {
        NewHomeWork->setWindowTitle(QApplication::translate("NewHomeWork", "Form", 0));
        lPaperName->setText(QApplication::translate("NewHomeWork", "Paper Name", 0));
        lSelectSubject->setText(QApplication::translate("NewHomeWork", "Select Subject", 0));
        lDuration->setText(QApplication::translate("NewHomeWork", "Duration", 0));
        gBSelectType->setTitle(QApplication::translate("NewHomeWork", "Select Type", 0));
        rBMcq->setText(QApplication::translate("NewHomeWork", "Mcq", 0));
        rBEssay->setText(QApplication::translate("NewHomeWork", "Essay", 0));
        rBEssayMcq->setText(QApplication::translate("NewHomeWork", "Mcq and Essay", 0));
        pBCreatePaper->setText(QApplication::translate("NewHomeWork", "Create Paper", 0));
        pBClose->setText(QApplication::translate("NewHomeWork", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class NewHomeWork: public Ui_NewHomeWork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWHOMEWORK_H
