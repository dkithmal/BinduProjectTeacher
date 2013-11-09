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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassManage
{
public:
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pBStudentProgress;
    QPushButton *pBMarkPapers;
    QPushButton *pBEditStudent;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ClassManage)
    {
        if (ClassManage->objectName().isEmpty())
            ClassManage->setObjectName(QStringLiteral("ClassManage"));
        ClassManage->resize(805, 270);
        QFont font;
        font.setPointSize(15);
        ClassManage->setFont(font);
        pushButton = new QPushButton(ClassManage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(720, 230, 75, 31));
        QFont font1;
        font1.setPointSize(10);
        pushButton->setFont(font1);
        layoutWidget = new QWidget(ClassManage);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 741, 202));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 6, 1, 1);

        pBStudentProgress = new QPushButton(layoutWidget);
        pBStudentProgress->setObjectName(QStringLiteral("pBStudentProgress"));
        pBStudentProgress->setMinimumSize(QSize(220, 200));

        gridLayout->addWidget(pBStudentProgress, 0, 3, 1, 1);

        pBMarkPapers = new QPushButton(layoutWidget);
        pBMarkPapers->setObjectName(QStringLiteral("pBMarkPapers"));
        pBMarkPapers->setMinimumSize(QSize(220, 200));

        gridLayout->addWidget(pBMarkPapers, 0, 1, 1, 1);

        pBEditStudent = new QPushButton(layoutWidget);
        pBEditStudent->setObjectName(QStringLiteral("pBEditStudent"));
        pBEditStudent->setMinimumSize(QSize(220, 200));

        gridLayout->addWidget(pBEditStudent, 0, 5, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        QWidget::setTabOrder(pBMarkPapers, pBStudentProgress);
        QWidget::setTabOrder(pBStudentProgress, pBEditStudent);
        QWidget::setTabOrder(pBEditStudent, pushButton);

        retranslateUi(ClassManage);
        QObject::connect(pushButton, SIGNAL(clicked()), ClassManage, SLOT(close()));

        QMetaObject::connectSlotsByName(ClassManage);
    } // setupUi

    void retranslateUi(QDialog *ClassManage)
    {
        ClassManage->setWindowTitle(QApplication::translate("ClassManage", "Class Manage ", 0));
        pushButton->setText(QApplication::translate("ClassManage", "Close", 0));
        pBStudentProgress->setText(QApplication::translate("ClassManage", "View Student Progress", 0));
        pBMarkPapers->setText(QApplication::translate("ClassManage", "Mark Papers", 0));
        pBEditStudent->setText(QApplication::translate("ClassManage", "Edit Student Details", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassManage: public Ui_ClassManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSMANAGE_H
