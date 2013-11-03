/********************************************************************************
** Form generated from reading UI file 'manageclasses.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGECLASSES_H
#define UI_MANAGECLASSES_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageClasses
{
public:
    QTabWidget *tWManage;
    QWidget *tab;
    QLabel *lGradeName;
    QLineEdit *lEGradeName;
    QPushButton *pBAddGrade;
    QPushButton *pBClose;
    QWidget *tab_2;
    QLabel *label_2;
    QLineEdit *lEClassName;
    QLabel *label_3;
    QTextEdit *tEStudents;
    QPushButton *pBCreateClass;
    QPushButton *pBClose_2;
    QComboBox *cBSelectGrade_2;
    QLabel *label;
    QWidget *tab_3;
    QLabel *label_4;
    QComboBox *cBSelectClass;
    QLabel *label_5;
    QLineEdit *lEStudentName;
    QPushButton *pBAddStudent;
    QPushButton *pBClose_3;
    QLabel *label_10;
    QComboBox *cBSelectGrade_3;
    QWidget *tab_4;
    QLabel *label_6;
    QComboBox *cBSelectGrade;
    QPushButton *pBRemoveGrade;
    QPushButton *pBClose_4;
    QWidget *tab_5;
    QLabel *label_7;
    QComboBox *cBSelectClassForRClass;
    QPushButton *pBRemoveClass;
    QPushButton *pBClose_5;
    QLabel *label_11;
    QComboBox *cBSelectGradeForRClass;
    QWidget *tab_6;
    QLabel *label_8;
    QComboBox *cBSelectClassFRStudent;
    QLabel *label_9;
    QComboBox *cBSelectStudentFRStudent;
    QPushButton *pBRemoveStudent;
    QPushButton *pBClose_6;
    QLabel *label_12;
    QComboBox *cBSelectGradeFRStudent;

    void setupUi(QWidget *ManageClasses)
    {
        if (ManageClasses->objectName().isEmpty())
            ManageClasses->setObjectName(QStringLiteral("ManageClasses"));
        ManageClasses->resize(698, 274);
        tWManage = new QTabWidget(ManageClasses);
        tWManage->setObjectName(QStringLiteral("tWManage"));
        tWManage->setGeometry(QRect(0, 0, 701, 281));
        QFont font;
        font.setPointSize(12);
        tWManage->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lGradeName = new QLabel(tab);
        lGradeName->setObjectName(QStringLiteral("lGradeName"));
        lGradeName->setGeometry(QRect(60, 65, 111, 21));
        lEGradeName = new QLineEdit(tab);
        lEGradeName->setObjectName(QStringLiteral("lEGradeName"));
        lEGradeName->setGeometry(QRect(190, 60, 231, 31));
        pBAddGrade = new QPushButton(tab);
        pBAddGrade->setObjectName(QStringLiteral("pBAddGrade"));
        pBAddGrade->setGeometry(QRect(470, 62, 91, 31));
        pBClose = new QPushButton(tab);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(600, 192, 75, 31));
        tWManage->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 60, 91, 31));
        lEClassName = new QLineEdit(tab_2);
        lEClassName->setObjectName(QStringLiteral("lEClassName"));
        lEClassName->setGeometry(QRect(130, 60, 151, 31));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 160, 91, 21));
        tEStudents = new QTextEdit(tab_2);
        tEStudents->setObjectName(QStringLiteral("tEStudents"));
        tEStudents->setGeometry(QRect(130, 100, 461, 121));
        pBCreateClass = new QPushButton(tab_2);
        pBCreateClass->setObjectName(QStringLiteral("pBCreateClass"));
        pBCreateClass->setGeometry(QRect(600, 80, 91, 61));
        pBClose_2 = new QPushButton(tab_2);
        pBClose_2->setObjectName(QStringLiteral("pBClose_2"));
        pBClose_2->setGeometry(QRect(610, 202, 75, 31));
        cBSelectGrade_2 = new QComboBox(tab_2);
        cBSelectGrade_2->setObjectName(QStringLiteral("cBSelectGrade_2"));
        cBSelectGrade_2->setGeometry(QRect(130, 11, 151, 31));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 101, 20));
        tWManage->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 80, 111, 31));
        cBSelectClass = new QComboBox(tab_3);
        cBSelectClass->setObjectName(QStringLiteral("cBSelectClass"));
        cBSelectClass->setGeometry(QRect(180, 80, 171, 31));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 150, 111, 16));
        lEStudentName = new QLineEdit(tab_3);
        lEStudentName->setObjectName(QStringLiteral("lEStudentName"));
        lEStudentName->setGeometry(QRect(180, 140, 171, 31));
        pBAddStudent = new QPushButton(tab_3);
        pBAddStudent->setObjectName(QStringLiteral("pBAddStudent"));
        pBAddStudent->setGeometry(QRect(450, 80, 101, 41));
        pBClose_3 = new QPushButton(tab_3);
        pBClose_3->setObjectName(QStringLiteral("pBClose_3"));
        pBClose_3->setGeometry(QRect(600, 190, 75, 41));
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 35, 101, 21));
        cBSelectGrade_3 = new QComboBox(tab_3);
        cBSelectGrade_3->setObjectName(QStringLiteral("cBSelectGrade_3"));
        cBSelectGrade_3->setGeometry(QRect(180, 31, 171, 31));
        tWManage->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 70, 111, 31));
        cBSelectGrade = new QComboBox(tab_4);
        cBSelectGrade->setObjectName(QStringLiteral("cBSelectGrade"));
        cBSelectGrade->setGeometry(QRect(210, 70, 151, 31));
        pBRemoveGrade = new QPushButton(tab_4);
        pBRemoveGrade->setObjectName(QStringLiteral("pBRemoveGrade"));
        pBRemoveGrade->setGeometry(QRect(460, 60, 131, 51));
        pBClose_4 = new QPushButton(tab_4);
        pBClose_4->setObjectName(QStringLiteral("pBClose_4"));
        pBClose_4->setGeometry(QRect(590, 192, 75, 31));
        tWManage->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        label_7 = new QLabel(tab_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 140, 111, 31));
        cBSelectClassForRClass = new QComboBox(tab_5);
        cBSelectClassForRClass->setObjectName(QStringLiteral("cBSelectClassForRClass"));
        cBSelectClassForRClass->setGeometry(QRect(200, 140, 121, 31));
        pBRemoveClass = new QPushButton(tab_5);
        pBRemoveClass->setObjectName(QStringLiteral("pBRemoveClass"));
        pBRemoveClass->setGeometry(QRect(390, 90, 131, 41));
        pBClose_5 = new QPushButton(tab_5);
        pBClose_5->setObjectName(QStringLiteral("pBClose_5"));
        pBClose_5->setGeometry(QRect(610, 192, 75, 31));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 55, 111, 21));
        cBSelectGradeForRClass = new QComboBox(tab_5);
        cBSelectGradeForRClass->setObjectName(QStringLiteral("cBSelectGradeForRClass"));
        cBSelectGradeForRClass->setGeometry(QRect(200, 51, 121, 31));
        tWManage->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        label_8 = new QLabel(tab_6);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 120, 121, 21));
        cBSelectClassFRStudent = new QComboBox(tab_6);
        cBSelectClassFRStudent->setObjectName(QStringLiteral("cBSelectClassFRStudent"));
        cBSelectClassFRStudent->setGeometry(QRect(190, 110, 131, 31));
        label_9 = new QLabel(tab_6);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 180, 111, 21));
        cBSelectStudentFRStudent = new QComboBox(tab_6);
        cBSelectStudentFRStudent->setObjectName(QStringLiteral("cBSelectStudentFRStudent"));
        cBSelectStudentFRStudent->setGeometry(QRect(170, 180, 171, 31));
        pBRemoveStudent = new QPushButton(tab_6);
        pBRemoveStudent->setObjectName(QStringLiteral("pBRemoveStudent"));
        pBRemoveStudent->setGeometry(QRect(390, 100, 131, 41));
        pBClose_6 = new QPushButton(tab_6);
        pBClose_6->setObjectName(QStringLiteral("pBClose_6"));
        pBClose_6->setGeometry(QRect(600, 192, 75, 31));
        label_12 = new QLabel(tab_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 45, 101, 21));
        cBSelectGradeFRStudent = new QComboBox(tab_6);
        cBSelectGradeFRStudent->setObjectName(QStringLiteral("cBSelectGradeFRStudent"));
        cBSelectGradeFRStudent->setGeometry(QRect(190, 41, 131, 31));
        tWManage->addTab(tab_6, QString());

        retranslateUi(ManageClasses);
        QObject::connect(pBClose, SIGNAL(clicked()), ManageClasses, SLOT(close()));
        QObject::connect(pBClose_2, SIGNAL(clicked()), ManageClasses, SLOT(close()));
        QObject::connect(pBClose_4, SIGNAL(clicked()), ManageClasses, SLOT(close()));
        QObject::connect(pBClose_3, SIGNAL(clicked()), ManageClasses, SLOT(close()));
        QObject::connect(pBClose_5, SIGNAL(clicked()), ManageClasses, SLOT(close()));
        QObject::connect(pBClose_6, SIGNAL(clicked()), ManageClasses, SLOT(close()));

        tWManage->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(ManageClasses);
    } // setupUi

    void retranslateUi(QWidget *ManageClasses)
    {
        ManageClasses->setWindowTitle(QApplication::translate("ManageClasses", "Form", 0));
        lGradeName->setText(QApplication::translate("ManageClasses", "Grade Name :", 0));
        pBAddGrade->setText(QApplication::translate("ManageClasses", "Add Grade", 0));
        pBClose->setText(QApplication::translate("ManageClasses", "Close", 0));
        tWManage->setTabText(tWManage->indexOf(tab), QApplication::translate("ManageClasses", "Add Grade", 0));
        label_2->setText(QApplication::translate("ManageClasses", "Class Name :", 0));
        label_3->setText(QApplication::translate("ManageClasses", "Students :", 0));
        pBCreateClass->setText(QApplication::translate("ManageClasses", "Create class", 0));
        pBClose_2->setText(QApplication::translate("ManageClasses", "Close", 0));
        label->setText(QApplication::translate("ManageClasses", "SelectGrade :", 0));
        tWManage->setTabText(tWManage->indexOf(tab_2), QApplication::translate("ManageClasses", "Add Class", 0));
        label_4->setText(QApplication::translate("ManageClasses", "Select Class", 0));
        label_5->setText(QApplication::translate("ManageClasses", "Student Index", 0));
        pBAddStudent->setText(QApplication::translate("ManageClasses", "Add Student", 0));
        pBClose_3->setText(QApplication::translate("ManageClasses", "Close", 0));
        label_10->setText(QApplication::translate("ManageClasses", "Select Grade :", 0));
        tWManage->setTabText(tWManage->indexOf(tab_3), QApplication::translate("ManageClasses", "Add Student", 0));
        label_6->setText(QApplication::translate("ManageClasses", "Select Grade", 0));
        pBRemoveGrade->setText(QApplication::translate("ManageClasses", "Remove Grade", 0));
        pBClose_4->setText(QApplication::translate("ManageClasses", "Close", 0));
        tWManage->setTabText(tWManage->indexOf(tab_4), QApplication::translate("ManageClasses", "Remove Grade", 0));
        label_7->setText(QApplication::translate("ManageClasses", "Select Class", 0));
        pBRemoveClass->setText(QApplication::translate("ManageClasses", "Remove Class", 0));
        pBClose_5->setText(QApplication::translate("ManageClasses", "Close", 0));
        label_11->setText(QApplication::translate("ManageClasses", "Select Grade", 0));
        tWManage->setTabText(tWManage->indexOf(tab_5), QApplication::translate("ManageClasses", "Remove Class", 0));
        label_8->setText(QApplication::translate("ManageClasses", "Select Class", 0));
        label_9->setText(QApplication::translate("ManageClasses", "Select Student", 0));
        pBRemoveStudent->setText(QApplication::translate("ManageClasses", "Remove Stuent", 0));
        pBClose_6->setText(QApplication::translate("ManageClasses", "Close", 0));
        label_12->setText(QApplication::translate("ManageClasses", "Select Grade", 0));
        tWManage->setTabText(tWManage->indexOf(tab_6), QApplication::translate("ManageClasses", "Remove Student", 0));
    } // retranslateUi

};

namespace Ui {
    class ManageClasses: public Ui_ManageClasses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGECLASSES_H
