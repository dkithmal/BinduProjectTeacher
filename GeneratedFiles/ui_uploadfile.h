/********************************************************************************
** Form generated from reading UI file 'uploadfile.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADFILE_H
#define UI_UPLOADFILE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadFile
{
public:
    QTreeWidget *tWSelectHomeWork;
    QTreeWidget *tWSelectClass;
    QLabel *label_2;
    QGroupBox *gBSelectOtherFile;
    QLineEdit *lEFileName;
    QPushButton *pushButton_3;
    QFrame *line;
    QGroupBox *gBSelectStudent;
    QLabel *label;
    QComboBox *cBSelectStudent;
    QPushButton *pBUpload;
    QPushButton *pBClose;
    QRadioButton *rBSelectHomeWork;
    QRadioButton *rBSelectOtherFile;

    void setupUi(QWidget *UploadFile)
    {
        if (UploadFile->objectName().isEmpty())
            UploadFile->setObjectName(QStringLiteral("UploadFile"));
        UploadFile->resize(752, 587);
        QFont font;
        font.setPointSize(12);
        UploadFile->setFont(font);
        tWSelectHomeWork = new QTreeWidget(UploadFile);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        tWSelectHomeWork->setHeaderItem(__qtreewidgetitem);
        tWSelectHomeWork->setObjectName(QStringLiteral("tWSelectHomeWork"));
        tWSelectHomeWork->setGeometry(QRect(10, 30, 361, 371));
        tWSelectHomeWork->setFont(font);
        tWSelectHomeWork->setSortingEnabled(true);
        tWSelectHomeWork->header()->setVisible(false);
        tWSelectClass = new QTreeWidget(UploadFile);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QStringLiteral("1"));
        tWSelectClass->setHeaderItem(__qtreewidgetitem1);
        tWSelectClass->setObjectName(QStringLiteral("tWSelectClass"));
        tWSelectClass->setGeometry(QRect(390, 30, 351, 371));
        tWSelectClass->setFont(font);
        tWSelectClass->setSortingEnabled(true);
        tWSelectClass->header()->setVisible(false);
        label_2 = new QLabel(UploadFile);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(400, 5, 91, 21));
        gBSelectOtherFile = new QGroupBox(UploadFile);
        gBSelectOtherFile->setObjectName(QStringLiteral("gBSelectOtherFile"));
        gBSelectOtherFile->setEnabled(false);
        gBSelectOtherFile->setGeometry(QRect(10, 430, 361, 81));
        lEFileName = new QLineEdit(gBSelectOtherFile);
        lEFileName->setObjectName(QStringLiteral("lEFileName"));
        lEFileName->setGeometry(QRect(10, 20, 251, 31));
        pushButton_3 = new QPushButton(gBSelectOtherFile);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 20, 81, 31));
        line = new QFrame(UploadFile);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(370, 0, 20, 541));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        gBSelectStudent = new QGroupBox(UploadFile);
        gBSelectStudent->setObjectName(QStringLiteral("gBSelectStudent"));
        gBSelectStudent->setGeometry(QRect(390, 420, 351, 91));
        label = new QLabel(gBSelectStudent);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 33, 111, 31));
        cBSelectStudent = new QComboBox(gBSelectStudent);
        cBSelectStudent->setObjectName(QStringLiteral("cBSelectStudent"));
        cBSelectStudent->setGeometry(QRect(170, 30, 121, 31));
        pBUpload = new QPushButton(UploadFile);
        pBUpload->setObjectName(QStringLiteral("pBUpload"));
        pBUpload->setGeometry(QRect(250, 530, 251, 51));
        pBClose = new QPushButton(UploadFile);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(660, 540, 81, 31));
        rBSelectHomeWork = new QRadioButton(UploadFile);
        rBSelectHomeWork->setObjectName(QStringLiteral("rBSelectHomeWork"));
        rBSelectHomeWork->setGeometry(QRect(10, 0, 221, 21));
        rBSelectHomeWork->setChecked(true);
        rBSelectOtherFile = new QRadioButton(UploadFile);
        rBSelectOtherFile->setObjectName(QStringLiteral("rBSelectOtherFile"));
        rBSelectOtherFile->setGeometry(QRect(10, 406, 141, 21));

        retranslateUi(UploadFile);
        QObject::connect(pBClose, SIGNAL(clicked()), UploadFile, SLOT(close()));

        QMetaObject::connectSlotsByName(UploadFile);
    } // setupUi

    void retranslateUi(QWidget *UploadFile)
    {
        UploadFile->setWindowTitle(QApplication::translate("UploadFile", "Form", 0));
        label_2->setText(QApplication::translate("UploadFile", "Select Class", 0));
        gBSelectOtherFile->setTitle(QString());
        pushButton_3->setText(QApplication::translate("UploadFile", "Select", 0));
        gBSelectStudent->setTitle(QApplication::translate("UploadFile", "Select Specific Student", 0));
        label->setText(QApplication::translate("UploadFile", "Select Student", 0));
        cBSelectStudent->clear();
        cBSelectStudent->insertItems(0, QStringList()
         << QApplication::translate("UploadFile", "All", 0)
        );
        pBUpload->setText(QApplication::translate("UploadFile", "Upload", 0));
        pBClose->setText(QApplication::translate("UploadFile", "Cancel", 0));
        rBSelectHomeWork->setText(QApplication::translate("UploadFile", "Select HomeWork Or Note", 0));
        rBSelectOtherFile->setText(QApplication::translate("UploadFile", "Select Other File", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadFile: public Ui_UploadFile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADFILE_H
