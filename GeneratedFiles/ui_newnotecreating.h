/********************************************************************************
** Form generated from reading UI file 'newnotecreating.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWNOTECREATING_H
#define UI_NEWNOTECREATING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewNoteCreating
{
public:
    QTextEdit *tEText;
    QPushButton *pBSaveAndClose;

    void setupUi(QWidget *NewNoteCreating)
    {
        if (NewNoteCreating->objectName().isEmpty())
            NewNoteCreating->setObjectName(QStringLiteral("NewNoteCreating"));
        NewNoteCreating->resize(844, 533);
        tEText = new QTextEdit(NewNoteCreating);
        tEText->setObjectName(QStringLiteral("tEText"));
        tEText->setGeometry(QRect(0, 0, 851, 491));
        QFont font;
        font.setPointSize(12);
        tEText->setFont(font);
        pBSaveAndClose = new QPushButton(NewNoteCreating);
        pBSaveAndClose->setObjectName(QStringLiteral("pBSaveAndClose"));
        pBSaveAndClose->setGeometry(QRect(720, 490, 121, 41));
        pBSaveAndClose->setFont(font);

        retranslateUi(NewNoteCreating);

        QMetaObject::connectSlotsByName(NewNoteCreating);
    } // setupUi

    void retranslateUi(QWidget *NewNoteCreating)
    {
        NewNoteCreating->setWindowTitle(QApplication::translate("NewNoteCreating", "Create New Note", 0));
        pBSaveAndClose->setText(QApplication::translate("NewNoteCreating", "Save And Close", 0));
    } // retranslateUi

};

namespace Ui {
    class NewNoteCreating: public Ui_NewNoteCreating {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWNOTECREATING_H
