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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherClass
{
public:
    QGridLayout *gridLayout;
    QWidget *wMainWidget;
    QGridLayout *gridLayout_4;
    QWidget *wHeader;
    QGridLayout *gridLayout_5;
    QComboBox *cBSettings;
    QLabel *lClock;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_8;
    QWidget *wBody;
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QPushButton *pBManager;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pBUpload;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pBHomeWork;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *TeacherClass)
    {
        if (TeacherClass->objectName().isEmpty())
            TeacherClass->setObjectName(QStringLiteral("TeacherClass"));
        TeacherClass->resize(1202, 658);
        QFont font;
        font.setPointSize(20);
        TeacherClass->setFont(font);
        gridLayout = new QGridLayout(TeacherClass);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        wMainWidget = new QWidget(TeacherClass);
        wMainWidget->setObjectName(QStringLiteral("wMainWidget"));
        gridLayout_4 = new QGridLayout(wMainWidget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        wHeader = new QWidget(wMainWidget);
        wHeader->setObjectName(QStringLiteral("wHeader"));
        wHeader->setMinimumSize(QSize(1200, 40));
        wHeader->setMaximumSize(QSize(16777215, 40));
        QFont font1;
        font1.setPointSize(12);
        wHeader->setFont(font1);
        gridLayout_5 = new QGridLayout(wHeader);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        cBSettings = new QComboBox(wHeader);
        cBSettings->setObjectName(QStringLiteral("cBSettings"));
        cBSettings->setMinimumSize(QSize(150, 40));
        cBSettings->setMaximumSize(QSize(150, 40));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setWeight(50);
        cBSettings->setFont(font2);
        cBSettings->setLayoutDirection(Qt::RightToLeft);
        cBSettings->setSizeAdjustPolicy(QComboBox::AdjustToMinimumContentsLengthWithIcon);

        gridLayout_5->addWidget(cBSettings, 0, 3, 1, 1);

        lClock = new QLabel(wHeader);
        lClock->setObjectName(QStringLiteral("lClock"));
        lClock->setMinimumSize(QSize(50, 40));
        lClock->setMaximumSize(QSize(50, 40));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        lClock->setFont(font3);

        gridLayout_5->addWidget(lClock, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 0, 0, 1, 1);


        gridLayout_4->addWidget(wHeader, 0, 0, 1, 1);

        wBody = new QWidget(wMainWidget);
        wBody->setObjectName(QStringLiteral("wBody"));
        QFont font4;
        font4.setPointSize(15);
        wBody->setFont(font4);
        gridLayout_6 = new QGridLayout(wBody);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        groupBox = new QGroupBox(wBody);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(1150, 250));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        pBManager = new QPushButton(groupBox);
        pBManager->setObjectName(QStringLiteral("pBManager"));
        pBManager->setMinimumSize(QSize(180, 200));

        gridLayout_7->addWidget(pBManager, 0, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(50, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        pBUpload = new QPushButton(groupBox);
        pBUpload->setObjectName(QStringLiteral("pBUpload"));
        pBUpload->setMinimumSize(QSize(180, 200));

        gridLayout_7->addWidget(pBUpload, 0, 3, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_6, 0, 4, 1, 1);

        pBHomeWork = new QPushButton(groupBox);
        pBHomeWork->setObjectName(QStringLiteral("pBHomeWork"));
        pBHomeWork->setMinimumSize(QSize(180, 200));

        gridLayout_7->addWidget(pBHomeWork, 0, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_7, 0, 6, 1, 1);


        gridLayout_6->addWidget(groupBox, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_6->addItem(verticalSpacer_2, 0, 1, 1, 1);


        gridLayout_4->addWidget(wBody, 1, 0, 1, 1);


        gridLayout->addWidget(wMainWidget, 0, 0, 1, 1);

        QWidget::setTabOrder(pBHomeWork, pBUpload);
        QWidget::setTabOrder(pBUpload, pBManager);
        QWidget::setTabOrder(pBManager, cBSettings);

        retranslateUi(TeacherClass);

        QMetaObject::connectSlotsByName(TeacherClass);
    } // setupUi

    void retranslateUi(QWidget *TeacherClass)
    {
        TeacherClass->setWindowTitle(QApplication::translate("TeacherClass", "Teacher", 0));
        cBSettings->clear();
        cBSettings->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("TeacherClass", "Administration", 0)
         << QApplication::translate("TeacherClass", "Add Subject", 0)
         << QApplication::translate("TeacherClass", "Shut Down", 0)
        );
        lClock->setText(QApplication::translate("TeacherClass", "12:30", 0));
        groupBox->setTitle(QString());
        pBManager->setText(QString());
        pBUpload->setText(QString());
        pBHomeWork->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TeacherClass: public Ui_TeacherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHER_H
