/********************************************************************************
** Form generated from reading UI file 'selectpaperformark.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPAPERFORMARK_H
#define UI_SELECTPAPERFORMARK_H

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

class Ui_SelectPaperForMark
{
public:
    QTreeWidget *tWSelectSubject;
    QListWidget *lWSelectPaper;
    QPushButton *pBClose;
    QPushButton *pBMarkPaper;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *SelectPaperForMark)
    {
        if (SelectPaperForMark->objectName().isEmpty())
            SelectPaperForMark->setObjectName(QStringLiteral("SelectPaperForMark"));
        SelectPaperForMark->resize(473, 493);
        tWSelectSubject = new QTreeWidget(SelectPaperForMark);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectSubject->setHeaderItem(__qtreewidgetitem);
        tWSelectSubject->setObjectName(QStringLiteral("tWSelectSubject"));
        tWSelectSubject->setGeometry(QRect(0, 30, 261, 361));
        QFont font;
        font.setPointSize(12);
        tWSelectSubject->setFont(font);
        tWSelectSubject->header()->setVisible(false);
        tWSelectSubject->header()->setCascadingSectionResizes(false);
        tWSelectSubject->header()->setHighlightSections(false);
        lWSelectPaper = new QListWidget(SelectPaperForMark);
        lWSelectPaper->setObjectName(QStringLiteral("lWSelectPaper"));
        lWSelectPaper->setGeometry(QRect(280, 30, 181, 361));
        lWSelectPaper->setFont(font);
        pBClose = new QPushButton(SelectPaperForMark);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(380, 450, 81, 31));
        pBMarkPaper = new QPushButton(SelectPaperForMark);
        pBMarkPaper->setObjectName(QStringLiteral("pBMarkPaper"));
        pBMarkPaper->setGeometry(QRect(120, 410, 211, 51));
        label = new QLabel(SelectPaperForMark);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 2, 111, 21));
        label->setFont(font);
        label_2 = new QLabel(SelectPaperForMark);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(280, 5, 111, 21));
        label_2->setFont(font);
        QWidget::setTabOrder(tWSelectSubject, lWSelectPaper);
        QWidget::setTabOrder(lWSelectPaper, pBMarkPaper);
        QWidget::setTabOrder(pBMarkPaper, pBClose);

        retranslateUi(SelectPaperForMark);
        QObject::connect(pBClose, SIGNAL(clicked()), SelectPaperForMark, SLOT(close()));

        QMetaObject::connectSlotsByName(SelectPaperForMark);
    } // setupUi

    void retranslateUi(QDialog *SelectPaperForMark)
    {
        SelectPaperForMark->setWindowTitle(QApplication::translate("SelectPaperForMark", "Select Paper For Mark", 0));
        pBClose->setText(QApplication::translate("SelectPaperForMark", "Close", 0));
        pBMarkPaper->setText(QApplication::translate("SelectPaperForMark", "Mark Paper", 0));
        label->setText(QApplication::translate("SelectPaperForMark", "Select Subject", 0));
        label_2->setText(QApplication::translate("SelectPaperForMark", "Select Paper", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectPaperForMark: public Ui_SelectPaperForMark {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPAPERFORMARK_H
