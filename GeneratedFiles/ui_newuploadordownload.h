/********************************************************************************
** Form generated from reading UI file 'newuploadordownload.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUPLOADORDOWNLOAD_H
#define UI_NEWUPLOADORDOWNLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewUploadOrDownload
{
public:
    QPushButton *pBUpload;
    QPushButton *pBDownload;
    QPushButton *pBClose;

    void setupUi(QWidget *NewUploadOrDownload)
    {
        if (NewUploadOrDownload->objectName().isEmpty())
            NewUploadOrDownload->setObjectName(QStringLiteral("NewUploadOrDownload"));
        NewUploadOrDownload->resize(488, 265);
        pBUpload = new QPushButton(NewUploadOrDownload);
        pBUpload->setObjectName(QStringLiteral("pBUpload"));
        pBUpload->setGeometry(QRect(10, 10, 181, 191));
        pBDownload = new QPushButton(NewUploadOrDownload);
        pBDownload->setObjectName(QStringLiteral("pBDownload"));
        pBDownload->setGeometry(QRect(260, 10, 191, 191));
        pBClose = new QPushButton(NewUploadOrDownload);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(384, 212, 81, 31));

        retranslateUi(NewUploadOrDownload);
        QObject::connect(pBClose, SIGNAL(clicked()), NewUploadOrDownload, SLOT(close()));

        QMetaObject::connectSlotsByName(NewUploadOrDownload);
    } // setupUi

    void retranslateUi(QWidget *NewUploadOrDownload)
    {
        NewUploadOrDownload->setWindowTitle(QApplication::translate("NewUploadOrDownload", "Form", 0));
        pBUpload->setText(QApplication::translate("NewUploadOrDownload", "Upload File", 0));
        pBDownload->setText(QApplication::translate("NewUploadOrDownload", "Download File", 0));
        pBClose->setText(QApplication::translate("NewUploadOrDownload", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class NewUploadOrDownload: public Ui_NewUploadOrDownload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUPLOADORDOWNLOAD_H
