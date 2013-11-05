/********************************************************************************
** Form generated from reading UI file 'addstudentinfromation.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTINFROMATION_H
#define UI_ADDSTUDENTINFROMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStudentInfromation
{
public:
    QLabel *label_12;
    QLabel *label_13;
    QTextEdit *TEStudentDiscription;
    QPushButton *pBSubmit;
    QPushButton *pBClose;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lEStudentName;
    QLabel *label_2;
    QLineEdit *lEStudentFullName;
    QLabel *label_11;
    QLineEdit *lEStudentBDate;
    QLabel *label_3;
    QLineEdit *lEStudentFatherName;
    QLabel *label_5;
    QLineEdit *lEStudentFOcupation;
    QLabel *label_7;
    QLineEdit *lEStudentFTelNo;
    QLabel *label_4;
    QLineEdit *lEMotherFullName;
    QLabel *label_8;
    QLineEdit *lEMotherOccupation;
    QLabel *label_6;
    QLineEdit *lEMotherTelNo;
    QLabel *label_9;
    QLineEdit *lEStudentHomeAddress;
    QLabel *label_10;
    QLineEdit *lEStudentHomeTelNo;

    void setupUi(QDialog *AddStudentInfromation)
    {
        if (AddStudentInfromation->objectName().isEmpty())
            AddStudentInfromation->setObjectName(QStringLiteral("AddStudentInfromation"));
        AddStudentInfromation->resize(527, 562);
        QFont font;
        font.setPointSize(12);
        AddStudentInfromation->setFont(font);
        label_12 = new QLabel(AddStudentInfromation);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(130, 10, 271, 31));
        QFont font1;
        font1.setPointSize(15);
        label_12->setFont(font1);
        label_13 = new QLabel(AddStudentInfromation);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 410, 91, 16));
        TEStudentDiscription = new QTextEdit(AddStudentInfromation);
        TEStudentDiscription->setObjectName(QStringLiteral("TEStudentDiscription"));
        TEStudentDiscription->setGeometry(QRect(10, 430, 511, 81));
        pBSubmit = new QPushButton(AddStudentInfromation);
        pBSubmit->setObjectName(QStringLiteral("pBSubmit"));
        pBSubmit->setGeometry(QRect(180, 520, 111, 31));
        pBClose = new QPushButton(AddStudentInfromation);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(440, 520, 75, 31));
        widget = new QWidget(AddStudentInfromation);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1, 51, 511, 351));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lEStudentName = new QLineEdit(widget);
        lEStudentName->setObjectName(QStringLiteral("lEStudentName"));
        lEStudentName->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lEStudentName);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lEStudentFullName = new QLineEdit(widget);
        lEStudentFullName->setObjectName(QStringLiteral("lEStudentFullName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lEStudentFullName);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_11);

        lEStudentBDate = new QLineEdit(widget);
        lEStudentBDate->setObjectName(QStringLiteral("lEStudentBDate"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lEStudentBDate);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        lEStudentFatherName = new QLineEdit(widget);
        lEStudentFatherName->setObjectName(QStringLiteral("lEStudentFatherName"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lEStudentFatherName);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lEStudentFOcupation = new QLineEdit(widget);
        lEStudentFOcupation->setObjectName(QStringLiteral("lEStudentFOcupation"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lEStudentFOcupation);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_7);

        lEStudentFTelNo = new QLineEdit(widget);
        lEStudentFTelNo->setObjectName(QStringLiteral("lEStudentFTelNo"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lEStudentFTelNo);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_4);

        lEMotherFullName = new QLineEdit(widget);
        lEMotherFullName->setObjectName(QStringLiteral("lEMotherFullName"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lEMotherFullName);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        lEMotherOccupation = new QLineEdit(widget);
        lEMotherOccupation->setObjectName(QStringLiteral("lEMotherOccupation"));

        formLayout->setWidget(7, QFormLayout::FieldRole, lEMotherOccupation);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_6);

        lEMotherTelNo = new QLineEdit(widget);
        lEMotherTelNo->setObjectName(QStringLiteral("lEMotherTelNo"));

        formLayout->setWidget(8, QFormLayout::FieldRole, lEMotherTelNo);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_9);

        lEStudentHomeAddress = new QLineEdit(widget);
        lEStudentHomeAddress->setObjectName(QStringLiteral("lEStudentHomeAddress"));

        formLayout->setWidget(9, QFormLayout::FieldRole, lEStudentHomeAddress);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_10);

        lEStudentHomeTelNo = new QLineEdit(widget);
        lEStudentHomeTelNo->setObjectName(QStringLiteral("lEStudentHomeTelNo"));

        formLayout->setWidget(10, QFormLayout::FieldRole, lEStudentHomeTelNo);


        retranslateUi(AddStudentInfromation);

        QMetaObject::connectSlotsByName(AddStudentInfromation);
    } // setupUi

    void retranslateUi(QDialog *AddStudentInfromation)
    {
        AddStudentInfromation->setWindowTitle(QApplication::translate("AddStudentInfromation", "Dialog", 0));
        label_12->setText(QApplication::translate("AddStudentInfromation", "Student Information Form", 0));
        label_13->setText(QApplication::translate("AddStudentInfromation", "Discription", 0));
        pBSubmit->setText(QApplication::translate("AddStudentInfromation", "Submit", 0));
        pBClose->setText(QApplication::translate("AddStudentInfromation", "Close", 0));
        label->setText(QApplication::translate("AddStudentInfromation", "Student Name", 0));
        label_2->setText(QApplication::translate("AddStudentInfromation", "Student Full Name", 0));
        label_11->setText(QApplication::translate("AddStudentInfromation", "Date of birth", 0));
        label_3->setText(QApplication::translate("AddStudentInfromation", "Father Full Name", 0));
        label_5->setText(QApplication::translate("AddStudentInfromation", "Father Occupation", 0));
        label_7->setText(QApplication::translate("AddStudentInfromation", "Father Tel No", 0));
        label_4->setText(QApplication::translate("AddStudentInfromation", "Mother Full Name", 0));
        label_8->setText(QApplication::translate("AddStudentInfromation", "Mother Occupation", 0));
        label_6->setText(QApplication::translate("AddStudentInfromation", "Mother Tel No", 0));
        label_9->setText(QApplication::translate("AddStudentInfromation", "Home Address ", 0));
        label_10->setText(QApplication::translate("AddStudentInfromation", "Home TelNo", 0));
    } // retranslateUi

};

namespace Ui {
    class AddStudentInfromation: public Ui_AddStudentInfromation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTINFROMATION_H
