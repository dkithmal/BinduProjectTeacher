/********************************************************************************
** Form generated from reading UI file 'subjectmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBJECTMANAGE_H
#define UI_SUBJECTMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubjectManage
{
public:
    QTabWidget *tWSubjectManage;
    QWidget *tab;
    QPushButton *pBClose;
    QLabel *label;
    QComboBox *cBSelectGradeAdd;
    QLabel *label_2;
    QLineEdit *lESubjectName;
    QPushButton *pBAddSubject;
    QWidget *tab_2;
    QPushButton *pBClose_2;
    QLabel *label_3;
    QComboBox *cBSelectGradeRemove;
    QLabel *label_4;
    QComboBox *cBSelectSubjectRemove;
    QPushButton *pBRemove;

    void setupUi(QWidget *SubjectManage)
    {
        if (SubjectManage->objectName().isEmpty())
            SubjectManage->setObjectName(QStringLiteral("SubjectManage"));
        SubjectManage->resize(626, 319);
        tWSubjectManage = new QTabWidget(SubjectManage);
        tWSubjectManage->setObjectName(QStringLiteral("tWSubjectManage"));
        tWSubjectManage->setGeometry(QRect(0, 0, 631, 321));
        QFont font;
        font.setPointSize(12);
        tWSubjectManage->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pBClose = new QPushButton(tab);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(524, 222, 81, 41));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 60, 111, 21));
        cBSelectGradeAdd = new QComboBox(tab);
        cBSelectGradeAdd->setObjectName(QStringLiteral("cBSelectGradeAdd"));
        cBSelectGradeAdd->setGeometry(QRect(160, 50, 121, 31));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 130, 161, 16));
        lESubjectName = new QLineEdit(tab);
        lESubjectName->setObjectName(QStringLiteral("lESubjectName"));
        lESubjectName->setGeometry(QRect(160, 120, 171, 31));
        pBAddSubject = new QPushButton(tab);
        pBAddSubject->setObjectName(QStringLiteral("pBAddSubject"));
        pBAddSubject->setGeometry(QRect(430, 70, 111, 51));
        tWSubjectManage->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        pBClose_2 = new QPushButton(tab_2);
        pBClose_2->setObjectName(QStringLiteral("pBClose_2"));
        pBClose_2->setGeometry(QRect(530, 232, 75, 31));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 50, 101, 31));
        cBSelectGradeRemove = new QComboBox(tab_2);
        cBSelectGradeRemove->setObjectName(QStringLiteral("cBSelectGradeRemove"));
        cBSelectGradeRemove->setGeometry(QRect(180, 51, 131, 31));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 135, 111, 21));
        cBSelectSubjectRemove = new QComboBox(tab_2);
        cBSelectSubjectRemove->setObjectName(QStringLiteral("cBSelectSubjectRemove"));
        cBSelectSubjectRemove->setGeometry(QRect(180, 130, 131, 31));
        pBRemove = new QPushButton(tab_2);
        pBRemove->setObjectName(QStringLiteral("pBRemove"));
        pBRemove->setGeometry(QRect(430, 82, 131, 31));
        tWSubjectManage->addTab(tab_2, QString());

        retranslateUi(SubjectManage);
        QObject::connect(pBClose, SIGNAL(clicked()), SubjectManage, SLOT(close()));
        QObject::connect(pBClose_2, SIGNAL(clicked()), SubjectManage, SLOT(close()));

        tWSubjectManage->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SubjectManage);
    } // setupUi

    void retranslateUi(QWidget *SubjectManage)
    {
        SubjectManage->setWindowTitle(QApplication::translate("SubjectManage", "Form", 0));
        pBClose->setText(QApplication::translate("SubjectManage", "Close", 0));
        label->setText(QApplication::translate("SubjectManage", "Select Grade :", 0));
        label_2->setText(QApplication::translate("SubjectManage", "Enter Subject Name :", 0));
        pBAddSubject->setText(QApplication::translate("SubjectManage", "Add Subject", 0));
        tWSubjectManage->setTabText(tWSubjectManage->indexOf(tab), QApplication::translate("SubjectManage", "Add Subject", 0));
        pBClose_2->setText(QApplication::translate("SubjectManage", "Close", 0));
        label_3->setText(QApplication::translate("SubjectManage", "Select Grade :", 0));
        label_4->setText(QApplication::translate("SubjectManage", "Select Subject :", 0));
        pBRemove->setText(QApplication::translate("SubjectManage", "Remove Subject", 0));
        tWSubjectManage->setTabText(tWSubjectManage->indexOf(tab_2), QApplication::translate("SubjectManage", "Remove Subject", 0));
    } // retranslateUi

};

namespace Ui {
    class SubjectManage: public Ui_SubjectManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBJECTMANAGE_H