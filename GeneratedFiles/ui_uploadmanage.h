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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadManage
{
public:

    void setupUi(QWidget *UploadManage)
    {
        if (UploadManage->objectName().isEmpty())
            UploadManage->setObjectName(QStringLiteral("UploadManage"));
        UploadManage->resize(665, 421);

        retranslateUi(UploadManage);

        QMetaObject::connectSlotsByName(UploadManage);
    } // setupUi

    void retranslateUi(QWidget *UploadManage)
    {
        UploadManage->setWindowTitle(QApplication::translate("UploadManage", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadManage: public Ui_UploadManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADMANAGE_H
