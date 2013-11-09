/********************************************************************************
** Form generated from reading UI file 'editnote.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITNOTE_H
#define UI_EDITNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditNote
{
public:
    QTextEdit *tEText;
    QPushButton *pBSaveAndClose;

    void setupUi(QWidget *EditNote)
    {
        if (EditNote->objectName().isEmpty())
            EditNote->setObjectName(QStringLiteral("EditNote"));
        EditNote->resize(855, 543);
        tEText = new QTextEdit(EditNote);
        tEText->setObjectName(QStringLiteral("tEText"));
        tEText->setGeometry(QRect(0, 0, 851, 491));
        QFont font;
        font.setPointSize(12);
        tEText->setFont(font);
        pBSaveAndClose = new QPushButton(EditNote);
        pBSaveAndClose->setObjectName(QStringLiteral("pBSaveAndClose"));
        pBSaveAndClose->setGeometry(QRect(730, 490, 121, 41));
        pBSaveAndClose->setFont(font);
        QWidget::setTabOrder(tEText, pBSaveAndClose);

        retranslateUi(EditNote);

        QMetaObject::connectSlotsByName(EditNote);
    } // setupUi

    void retranslateUi(QWidget *EditNote)
    {
        EditNote->setWindowTitle(QApplication::translate("EditNote", "Edit Note", 0));
        pBSaveAndClose->setText(QApplication::translate("EditNote", "Save And Close", 0));
    } // retranslateUi

};

namespace Ui {
    class EditNote: public Ui_EditNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITNOTE_H
