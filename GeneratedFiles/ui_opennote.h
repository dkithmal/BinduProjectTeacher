/********************************************************************************
** Form generated from reading UI file 'opennote.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENNOTE_H
#define UI_OPENNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OpenNote
{
public:
    QTreeWidget *tWSelectSubject;
    QListWidget *lWHomeWorks;
    QPushButton *pBOpen;
    QLabel *lSelectSubject;
    QPushButton *pBClose;
    QPushButton *pBDeleteNote;
    QLabel *label;

    void setupUi(QWidget *OpenNote)
    {
        if (OpenNote->objectName().isEmpty())
            OpenNote->setObjectName(QStringLiteral("OpenNote"));
        OpenNote->resize(760, 457);
        QFont font;
        font.setPointSize(12);
        OpenNote->setFont(font);
        tWSelectSubject = new QTreeWidget(OpenNote);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectSubject->setHeaderItem(__qtreewidgetitem);
        tWSelectSubject->setObjectName(QStringLiteral("tWSelectSubject"));
        tWSelectSubject->setGeometry(QRect(10, 40, 361, 411));
        tWSelectSubject->setFont(font);
        tWSelectSubject->setSortingEnabled(false);
        tWSelectSubject->header()->setVisible(false);
        lWHomeWorks = new QListWidget(OpenNote);
        lWHomeWorks->setObjectName(QStringLiteral("lWHomeWorks"));
        lWHomeWorks->setGeometry(QRect(390, 40, 361, 331));
        lWHomeWorks->setFont(font);
        lWHomeWorks->setSortingEnabled(true);
        pBOpen = new QPushButton(OpenNote);
        pBOpen->setObjectName(QStringLiteral("pBOpen"));
        pBOpen->setGeometry(QRect(590, 380, 161, 31));
        lSelectSubject = new QLabel(OpenNote);
        lSelectSubject->setObjectName(QStringLiteral("lSelectSubject"));
        lSelectSubject->setGeometry(QRect(10, 10, 121, 21));
        lSelectSubject->setFont(font);
        pBClose = new QPushButton(OpenNote);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(670, 420, 75, 31));
        pBDeleteNote = new QPushButton(OpenNote);
        pBDeleteNote->setObjectName(QStringLiteral("pBDeleteNote"));
        pBDeleteNote->setGeometry(QRect(390, 380, 151, 31));
        label = new QLabel(OpenNote);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(390, 10, 81, 16));
        QWidget::setTabOrder(tWSelectSubject, lWHomeWorks);
        QWidget::setTabOrder(lWHomeWorks, pBOpen);
        QWidget::setTabOrder(pBOpen, pBDeleteNote);
        QWidget::setTabOrder(pBDeleteNote, pBClose);

        retranslateUi(OpenNote);
        QObject::connect(pBClose, SIGNAL(clicked()), OpenNote, SLOT(close()));

        QMetaObject::connectSlotsByName(OpenNote);
    } // setupUi

    void retranslateUi(QWidget *OpenNote)
    {
        OpenNote->setWindowTitle(QApplication::translate("OpenNote", "Slect Note To Open", 0));
        pBOpen->setText(QApplication::translate("OpenNote", "Open", 0));
        lSelectSubject->setText(QApplication::translate("OpenNote", "Select Subject", 0));
        pBClose->setText(QApplication::translate("OpenNote", "Close", 0));
        pBDeleteNote->setText(QApplication::translate("OpenNote", "Delete Note", 0));
        label->setText(QApplication::translate("OpenNote", "Select Note", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenNote: public Ui_OpenNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENNOTE_H
