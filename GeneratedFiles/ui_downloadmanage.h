/********************************************************************************
** Form generated from reading UI file 'downloadmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADMANAGE_H
#define UI_DOWNLOADMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadManage
{
public:
    QPushButton *pBDownloadClose;
    QTableWidget *tWDownlodingtate;

    void setupUi(QWidget *DownloadManage)
    {
        if (DownloadManage->objectName().isEmpty())
            DownloadManage->setObjectName(QStringLiteral("DownloadManage"));
        DownloadManage->resize(315, 520);
        QFont font;
        font.setPointSize(12);
        DownloadManage->setFont(font);
        pBDownloadClose = new QPushButton(DownloadManage);
        pBDownloadClose->setObjectName(QStringLiteral("pBDownloadClose"));
        pBDownloadClose->setGeometry(QRect(230, 470, 75, 31));
        tWDownlodingtate = new QTableWidget(DownloadManage);
        if (tWDownlodingtate->columnCount() < 2)
            tWDownlodingtate->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tWDownlodingtate->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tWDownlodingtate->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tWDownlodingtate->setObjectName(QStringLiteral("tWDownlodingtate"));
        tWDownlodingtate->setGeometry(QRect(20, 20, 261, 431));
        tWDownlodingtate->setFont(font);
        tWDownlodingtate->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tWDownlodingtate->setShowGrid(false);
        tWDownlodingtate->setCornerButtonEnabled(true);
        tWDownlodingtate->horizontalHeader()->setDefaultSectionSize(120);
        tWDownlodingtate->horizontalHeader()->setHighlightSections(true);
        QWidget::setTabOrder(tWDownlodingtate, pBDownloadClose);

        retranslateUi(DownloadManage);
        QObject::connect(pBDownloadClose, SIGNAL(clicked()), DownloadManage, SLOT(close()));

        QMetaObject::connectSlotsByName(DownloadManage);
    } // setupUi

    void retranslateUi(QWidget *DownloadManage)
    {
        DownloadManage->setWindowTitle(QApplication::translate("DownloadManage", "Downloading State", 0));
        pBDownloadClose->setText(QApplication::translate("DownloadManage", "Close", 0));
        QTableWidgetItem *___qtablewidgetitem = tWDownlodingtate->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DownloadManage", "Student Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tWDownlodingtate->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DownloadManage", "State", 0));
    } // retranslateUi

};

namespace Ui {
    class DownloadManage: public Ui_DownloadManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADMANAGE_H
