/********************************************************************************
** Form generated from reading UI file 'uploadmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADMANAGE_H
#define UI_UPLOADMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadManage
{
public:
    QPushButton *pBUpdateClose;
    QTableWidget *tWUplodingState;

    void setupUi(QWidget *UploadManage)
    {
        if (UploadManage->objectName().isEmpty())
            UploadManage->setObjectName(QStringLiteral("UploadManage"));
        UploadManage->resize(323, 504);
        QFont font;
        font.setPointSize(12);
        UploadManage->setFont(font);
        pBUpdateClose = new QPushButton(UploadManage);
        pBUpdateClose->setObjectName(QStringLiteral("pBUpdateClose"));
        pBUpdateClose->setGeometry(QRect(240, 460, 75, 23));
        tWUplodingState = new QTableWidget(UploadManage);
        if (tWUplodingState->columnCount() < 2)
            tWUplodingState->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tWUplodingState->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tWUplodingState->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tWUplodingState->setObjectName(QStringLiteral("tWUplodingState"));
        tWUplodingState->setGeometry(QRect(20, 20, 271, 431));
        tWUplodingState->setFont(font);
        tWUplodingState->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tWUplodingState->horizontalHeader()->setDefaultSectionSize(120);

        retranslateUi(UploadManage);
        QObject::connect(pBUpdateClose, SIGNAL(clicked()), UploadManage, SLOT(close()));

        QMetaObject::connectSlotsByName(UploadManage);
    } // setupUi

    void retranslateUi(QWidget *UploadManage)
    {
        UploadManage->setWindowTitle(QApplication::translate("UploadManage", "Form", 0));
        pBUpdateClose->setText(QApplication::translate("UploadManage", "Close", 0));
        QTableWidgetItem *___qtablewidgetitem = tWUplodingState->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UploadManage", "Student Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tWUplodingState->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UploadManage", "State", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadManage: public Ui_UploadManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADMANAGE_H
