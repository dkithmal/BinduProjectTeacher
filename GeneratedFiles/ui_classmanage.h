/********************************************************************************
** Form generated from reading UI file 'classmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSMANAGE_H
#define UI_CLASSMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ClassManage
{
public:
    QPushButton *pBMarkPapers;
    QPushButton *pBStudentProgress;
    QPushButton *pBEditStudent;
    QPushButton *pushButton;

    void setupUi(QDialog *ClassManage)
    {
        if (ClassManage->objectName().isEmpty())
            ClassManage->setObjectName(QStringLiteral("ClassManage"));
        ClassManage->resize(805, 270);
        QFont font;
        font.setPointSize(15);
        ClassManage->setFont(font);
        pBMarkPapers = new QPushButton(ClassManage);
        pBMarkPapers->setObjectName(QStringLiteral("pBMarkPapers"));
        pBMarkPapers->setGeometry(QRect(30, 20, 201, 181));
        pBStudentProgress = new QPushButton(ClassManage);
        pBStudentProgress->setObjectName(QStringLiteral("pBStudentProgress"));
        pBStudentProgress->setGeometry(QRect(270, 20, 221, 181));
        pBEditStudent = new QPushButton(ClassManage);
        pBEditStudent->setObjectName(QStringLiteral("pBEditStudent"));
        pBEditStudent->setGeometry(QRect(530, 20, 241, 181));
        pushButton = new QPushButton(ClassManage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(700, 222, 75, 31));
        QFont font1;
        font1.setPointSize(10);
        pushButton->setFont(font1);

        retranslateUi(ClassManage);
        QObject::connect(pushButton, SIGNAL(clicked()), ClassManage, SLOT(close()));

        QMetaObject::connectSlotsByName(ClassManage);
    } // setupUi

    void retranslateUi(QDialog *ClassManage)
    {
        ClassManage->setWindowTitle(QApplication::translate("ClassManage", "Dialog", 0));
        pBMarkPapers->setText(QApplication::translate("ClassManage", "Mark Papers", 0));
        pBStudentProgress->setText(QApplication::translate("ClassManage", "View Student Progress", 0));
        pBEditStudent->setText(QApplication::translate("ClassManage", "Edit Student Details", 0));
        pushButton->setText(QApplication::translate("ClassManage", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassManage: public Ui_ClassManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSMANAGE_H
