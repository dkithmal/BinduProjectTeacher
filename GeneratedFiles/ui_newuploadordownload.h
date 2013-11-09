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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewUploadOrDownload
{
public:
    QPushButton *pBClose;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pBDownload;
    QPushButton *pBUpload;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *NewUploadOrDownload)
    {
        if (NewUploadOrDownload->objectName().isEmpty())
            NewUploadOrDownload->setObjectName(QStringLiteral("NewUploadOrDownload"));
        NewUploadOrDownload->resize(488, 265);
        QFont font;
        font.setPointSize(12);
        NewUploadOrDownload->setFont(font);
        pBClose = new QPushButton(NewUploadOrDownload);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(400, 220, 81, 31));
        layoutWidget = new QWidget(NewUploadOrDownload);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 10, 414, 202));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pBDownload = new QPushButton(layoutWidget);
        pBDownload->setObjectName(QStringLiteral("pBDownload"));
        pBDownload->setMinimumSize(QSize(200, 200));
        QFont font1;
        font1.setPointSize(15);
        pBDownload->setFont(font1);

        gridLayout->addWidget(pBDownload, 0, 2, 1, 1);

        pBUpload = new QPushButton(layoutWidget);
        pBUpload->setObjectName(QStringLiteral("pBUpload"));
        pBUpload->setMinimumSize(QSize(200, 200));
        pBUpload->setFont(font1);

        gridLayout->addWidget(pBUpload, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        QWidget::setTabOrder(pBUpload, pBDownload);
        QWidget::setTabOrder(pBDownload, pBClose);

        retranslateUi(NewUploadOrDownload);
        QObject::connect(pBClose, SIGNAL(clicked()), NewUploadOrDownload, SLOT(close()));

        QMetaObject::connectSlotsByName(NewUploadOrDownload);
    } // setupUi

    void retranslateUi(QWidget *NewUploadOrDownload)
    {
        NewUploadOrDownload->setWindowTitle(QApplication::translate("NewUploadOrDownload", "Upload and Download", 0));
        pBClose->setText(QApplication::translate("NewUploadOrDownload", "Close", 0));
        pBDownload->setText(QApplication::translate("NewUploadOrDownload", "Download File", 0));
        pBUpload->setText(QApplication::translate("NewUploadOrDownload", "Upload File", 0));
    } // retranslateUi

};

namespace Ui {
    class NewUploadOrDownload: public Ui_NewUploadOrDownload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUPLOADORDOWNLOAD_H
