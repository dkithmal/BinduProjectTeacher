/********************************************************************************
** Form generated from reading UI file 'selectstuforadddetails.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSTUFORADDDETAILS_H
#define UI_SELECTSTUFORADDDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectStuForAddDetails
{
public:
    QTreeWidget *tWSelectClass;
    QListWidget *lWStudent;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pBAddDetails;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SelectStuForAddDetails)
    {
        if (SelectStuForAddDetails->objectName().isEmpty())
            SelectStuForAddDetails->setObjectName(QStringLiteral("SelectStuForAddDetails"));
        SelectStuForAddDetails->resize(493, 573);
        tWSelectClass = new QTreeWidget(SelectStuForAddDetails);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectClass->setHeaderItem(__qtreewidgetitem);
        tWSelectClass->setObjectName(QStringLiteral("tWSelectClass"));
        tWSelectClass->setGeometry(QRect(10, 30, 281, 451));
        QFont font;
        font.setPointSize(12);
        tWSelectClass->setFont(font);
        tWSelectClass->header()->setVisible(false);
        lWStudent = new QListWidget(SelectStuForAddDetails);
        lWStudent->setObjectName(QStringLiteral("lWStudent"));
        lWStudent->setGeometry(QRect(310, 30, 171, 451));
        lWStudent->setFont(font);
        label = new QLabel(SelectStuForAddDetails);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 111, 31));
        label->setFont(font);
        label_2 = new QLabel(SelectStuForAddDetails);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(320, 0, 101, 31));
        label_2->setFont(font);
        pBAddDetails = new QPushButton(SelectStuForAddDetails);
        pBAddDetails->setObjectName(QStringLiteral("pBAddDetails"));
        pBAddDetails->setGeometry(QRect(170, 490, 171, 51));
        pushButton_2 = new QPushButton(SelectStuForAddDetails);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(410, 530, 71, 31));
        QWidget::setTabOrder(tWSelectClass, lWStudent);
        QWidget::setTabOrder(lWStudent, pBAddDetails);
        QWidget::setTabOrder(pBAddDetails, pushButton_2);

        retranslateUi(SelectStuForAddDetails);
        QObject::connect(pushButton_2, SIGNAL(clicked()), SelectStuForAddDetails, SLOT(close()));

        QMetaObject::connectSlotsByName(SelectStuForAddDetails);
    } // setupUi

    void retranslateUi(QDialog *SelectStuForAddDetails)
    {
        SelectStuForAddDetails->setWindowTitle(QApplication::translate("SelectStuForAddDetails", "Select Student to Add details", 0));
        label->setText(QApplication::translate("SelectStuForAddDetails", "Select Class", 0));
        label_2->setText(QApplication::translate("SelectStuForAddDetails", "Select Student", 0));
        pBAddDetails->setText(QApplication::translate("SelectStuForAddDetails", "Add Details", 0));
        pushButton_2->setText(QApplication::translate("SelectStuForAddDetails", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectStuForAddDetails: public Ui_SelectStuForAddDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSTUFORADDDETAILS_H
