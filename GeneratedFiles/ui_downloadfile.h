/********************************************************************************
** Form generated from reading UI file 'downloadfile.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADFILE_H
#define UI_DOWNLOADFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloadFile
{
public:
    QTreeWidget *tWSelectHomeWork;
    QGroupBox *gBSelectStudent;
    QLabel *label;
    QComboBox *cBSelectStudent;
    QTreeWidget *tWSelectClass;
    QFrame *line;
    QLabel *label_2;
    QPushButton *pBClose;
    QLabel *label_3;
    QPushButton *pBDownload;

    void setupUi(QWidget *DownloadFile)
    {
        if (DownloadFile->objectName().isEmpty())
            DownloadFile->setObjectName(QStringLiteral("DownloadFile"));
        DownloadFile->resize(673, 603);
        QFont font;
        font.setPointSize(12);
        DownloadFile->setFont(font);
        tWSelectHomeWork = new QTreeWidget(DownloadFile);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectHomeWork->setHeaderItem(__qtreewidgetitem);
        tWSelectHomeWork->setObjectName(QStringLiteral("tWSelectHomeWork"));
        tWSelectHomeWork->setGeometry(QRect(360, 40, 301, 371));
        tWSelectHomeWork->setFont(font);
        tWSelectHomeWork->setSortingEnabled(true);
        tWSelectHomeWork->header()->setVisible(false);
        gBSelectStudent = new QGroupBox(DownloadFile);
        gBSelectStudent->setObjectName(QStringLiteral("gBSelectStudent"));
        gBSelectStudent->setGeometry(QRect(10, 420, 311, 91));
        label = new QLabel(gBSelectStudent);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 33, 111, 31));
        cBSelectStudent = new QComboBox(gBSelectStudent);
        cBSelectStudent->setObjectName(QStringLiteral("cBSelectStudent"));
        cBSelectStudent->setGeometry(QRect(140, 30, 161, 31));
        tWSelectClass = new QTreeWidget(DownloadFile);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        tWSelectClass->setHeaderItem(__qtreewidgetitem1);
        tWSelectClass->setObjectName(QStringLiteral("tWSelectClass"));
        tWSelectClass->setGeometry(QRect(10, 40, 311, 371));
        tWSelectClass->setFont(font);
        tWSelectClass->setSortingEnabled(false);
        tWSelectClass->header()->setVisible(false);
        line = new QFrame(DownloadFile);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(330, 0, 20, 541));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(DownloadFile);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 91, 21));
        pBClose = new QPushButton(DownloadFile);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(580, 550, 81, 31));
        label_3 = new QLabel(DownloadFile);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 10, 141, 21));
        pBDownload = new QPushButton(DownloadFile);
        pBDownload->setObjectName(QStringLiteral("pBDownload"));
        pBDownload->setGeometry(QRect(230, 530, 231, 51));
        QWidget::setTabOrder(tWSelectClass, cBSelectStudent);
        QWidget::setTabOrder(cBSelectStudent, tWSelectHomeWork);
        QWidget::setTabOrder(tWSelectHomeWork, pBDownload);
        QWidget::setTabOrder(pBDownload, pBClose);

        retranslateUi(DownloadFile);
        QObject::connect(pBClose, SIGNAL(clicked()), DownloadFile, SLOT(close()));

        QMetaObject::connectSlotsByName(DownloadFile);
    } // setupUi

    void retranslateUi(QWidget *DownloadFile)
    {
        DownloadFile->setWindowTitle(QApplication::translate("DownloadFile", "Select File For Download", 0));
        gBSelectStudent->setTitle(QApplication::translate("DownloadFile", "Select Specific Student", 0));
        label->setText(QApplication::translate("DownloadFile", "Select Student", 0));
        label_2->setText(QApplication::translate("DownloadFile", "Select Class", 0));
        pBClose->setText(QApplication::translate("DownloadFile", "Cancel", 0));
        label_3->setText(QApplication::translate("DownloadFile", "Select Home Work", 0));
        pBDownload->setText(QApplication::translate("DownloadFile", "Download Home Work", 0));
    } // retranslateUi

};

namespace Ui {
    class DownloadFile: public Ui_DownloadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADFILE_H
