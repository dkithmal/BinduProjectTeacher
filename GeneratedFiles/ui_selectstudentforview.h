/********************************************************************************
** Form generated from reading UI file 'selectstudentforview.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSTUDENTFORVIEW_H
#define UI_SELECTSTUDENTFORVIEW_H

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

class Ui_SelectStudentForView
{
public:
    QLabel *label;
    QPushButton *pushButton_2;
    QListWidget *lWStudent;
    QPushButton *pBViewStudent;
    QLabel *label_2;
    QTreeWidget *tWSelectClass;

    void setupUi(QDialog *SelectStudentForView)
    {
        if (SelectStudentForView->objectName().isEmpty())
            SelectStudentForView->setObjectName(QStringLiteral("SelectStudentForView"));
        SelectStudentForView->resize(500, 589);
        label = new QLabel(SelectStudentForView);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 111, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        pushButton_2 = new QPushButton(SelectStudentForView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 540, 71, 31));
        lWStudent = new QListWidget(SelectStudentForView);
        lWStudent->setObjectName(QStringLiteral("lWStudent"));
        lWStudent->setGeometry(QRect(320, 30, 171, 451));
        lWStudent->setFont(font);
        pBViewStudent = new QPushButton(SelectStudentForView);
        pBViewStudent->setObjectName(QStringLiteral("pBViewStudent"));
        pBViewStudent->setGeometry(QRect(140, 490, 201, 51));
        label_2 = new QLabel(SelectStudentForView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 0, 101, 31));
        label_2->setFont(font);
        tWSelectClass = new QTreeWidget(SelectStudentForView);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectClass->setHeaderItem(__qtreewidgetitem);
        tWSelectClass->setObjectName(QStringLiteral("tWSelectClass"));
        tWSelectClass->setGeometry(QRect(20, 30, 281, 451));
        tWSelectClass->setFont(font);
        tWSelectClass->header()->setVisible(false);
        QWidget::setTabOrder(tWSelectClass, lWStudent);
        QWidget::setTabOrder(lWStudent, pBViewStudent);
        QWidget::setTabOrder(pBViewStudent, pushButton_2);

        retranslateUi(SelectStudentForView);
        QObject::connect(pushButton_2, SIGNAL(clicked()), SelectStudentForView, SLOT(close()));

        QMetaObject::connectSlotsByName(SelectStudentForView);
    } // setupUi

    void retranslateUi(QDialog *SelectStudentForView)
    {
        SelectStudentForView->setWindowTitle(QApplication::translate("SelectStudentForView", "Select Student To View", 0));
        label->setText(QApplication::translate("SelectStudentForView", "Select Class", 0));
        pushButton_2->setText(QApplication::translate("SelectStudentForView", "Close", 0));
        pBViewStudent->setText(QApplication::translate("SelectStudentForView", "ViewStudent", 0));
        label_2->setText(QApplication::translate("SelectStudentForView", "Select Student", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectStudentForView: public Ui_SelectStudentForView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSTUDENTFORVIEW_H
