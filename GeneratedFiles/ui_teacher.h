/********************************************************************************
** Form generated from reading UI file 'teacher.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHER_H
#define UI_TEACHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherClass
{
public:
    QFrame *line;
    QGroupBox *groupBox;
    QPushButton *pBHomeWork;
    QPushButton *pBUpload;
    QPushButton *pBManager;
    QComboBox *cBSettings;
    QLCDNumber *lcdNClock;

    void setupUi(QWidget *TeacherClass)
    {
        if (TeacherClass->objectName().isEmpty())
            TeacherClass->setObjectName(QStringLiteral("TeacherClass"));
        TeacherClass->resize(1301, 705);
        line = new QFrame(TeacherClass);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 40, 1301, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox = new QGroupBox(TeacherClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 1281, 181));
        pBHomeWork = new QPushButton(groupBox);
        pBHomeWork->setObjectName(QStringLiteral("pBHomeWork"));
        pBHomeWork->setGeometry(QRect(50, 20, 280, 140));
        pBUpload = new QPushButton(groupBox);
        pBUpload->setObjectName(QStringLiteral("pBUpload"));
        pBUpload->setGeometry(QRect(500, 20, 280, 140));
        pBManager = new QPushButton(groupBox);
        pBManager->setObjectName(QStringLiteral("pBManager"));
        pBManager->setGeometry(QRect(960, 20, 280, 140));
        cBSettings = new QComboBox(TeacherClass);
        cBSettings->setObjectName(QStringLiteral("cBSettings"));
        cBSettings->setGeometry(QRect(1180, 10, 101, 31));
        QFont font;
        font.setPointSize(12);
        cBSettings->setFont(font);
        lcdNClock = new QLCDNumber(TeacherClass);
        lcdNClock->setObjectName(QStringLiteral("lcdNClock"));
        lcdNClock->setGeometry(QRect(20, 10, 91, 31));

        retranslateUi(TeacherClass);

        QMetaObject::connectSlotsByName(TeacherClass);
    } // setupUi

    void retranslateUi(QWidget *TeacherClass)
    {
        TeacherClass->setWindowTitle(QApplication::translate("TeacherClass", "Teacher", 0));
        groupBox->setTitle(QString());
        pBHomeWork->setText(QApplication::translate("TeacherClass", "Home Work Tool", 0));
        pBUpload->setText(QApplication::translate("TeacherClass", "Upload/Download", 0));
        pBManager->setText(QApplication::translate("TeacherClass", "Class Manager", 0));
        cBSettings->clear();
        cBSettings->insertItems(0, QStringList()
         << QApplication::translate("TeacherClass", "Settings", 0)
         << QApplication::translate("TeacherClass", "Admistration", 0)
         << QApplication::translate("TeacherClass", "Add Subject", 0)
         << QApplication::translate("TeacherClass", "ShutDown", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class TeacherClass: public Ui_TeacherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
