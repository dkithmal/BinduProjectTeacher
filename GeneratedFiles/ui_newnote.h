/********************************************************************************
** Form generated from reading UI file 'newnote.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWNOTE_H
#define UI_NEWNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewNote
{
public:
    QLabel *lSelectSubject;
    QLabel *lNoteName;
    QLineEdit *lineEdit;
    QPushButton *pBCreateNote;
    QPushButton *pBClose;
    QTreeWidget *tWSelectSubject;

    void setupUi(QWidget *NewNote)
    {
        if (NewNote->objectName().isEmpty())
            NewNote->setObjectName(QStringLiteral("NewNote"));
        NewNote->resize(714, 438);
        QFont font;
        font.setPointSize(12);
        NewNote->setFont(font);
        lSelectSubject = new QLabel(NewNote);
        lSelectSubject->setObjectName(QStringLiteral("lSelectSubject"));
        lSelectSubject->setGeometry(QRect(20, 5, 101, 21));
        lSelectSubject->setFont(font);
        lNoteName = new QLabel(NewNote);
        lNoteName->setObjectName(QStringLiteral("lNoteName"));
        lNoteName->setGeometry(QRect(390, 10, 101, 16));
        lNoteName->setFont(font);
        lineEdit = new QLineEdit(NewNote);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(380, 30, 321, 31));
        pBCreateNote = new QPushButton(NewNote);
        pBCreateNote->setObjectName(QStringLiteral("pBCreateNote"));
        pBCreateNote->setGeometry(QRect(380, 80, 321, 31));
        pBClose = new QPushButton(NewNote);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(630, 380, 75, 31));
        tWSelectSubject = new QTreeWidget(NewNote);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectSubject->setHeaderItem(__qtreewidgetitem);
        tWSelectSubject->setObjectName(QStringLiteral("tWSelectSubject"));
        tWSelectSubject->setGeometry(QRect(10, 30, 361, 381));
        tWSelectSubject->setFont(font);
        tWSelectSubject->header()->setVisible(false);

        retranslateUi(NewNote);
        QObject::connect(pBClose, SIGNAL(clicked()), NewNote, SLOT(close()));

        QMetaObject::connectSlotsByName(NewNote);
    } // setupUi

    void retranslateUi(QWidget *NewNote)
    {
        NewNote->setWindowTitle(QApplication::translate("NewNote", "Form", 0));
        lSelectSubject->setText(QApplication::translate("NewNote", "Select Subject", 0));
        lNoteName->setText(QApplication::translate("NewNote", "Note Name", 0));
        pBCreateNote->setText(QApplication::translate("NewNote", "Create Note", 0));
        pBClose->setText(QApplication::translate("NewNote", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class NewNote: public Ui_NewNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWNOTE_H
