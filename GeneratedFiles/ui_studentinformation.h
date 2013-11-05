/********************************************************************************
** Form generated from reading UI file 'studentinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTINFORMATION_H
#define UI_STUDENTINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentInformation
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tWMarksSummery;
    QWidget *tab_2;
    QLabel *label_13;
    QTextEdit *textEdit;
    QLabel *lStudentName;
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *lStudentMotherFullName;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *lStudentFatherFullName;
    QLabel *label_5;
    QLabel *lStudentDateOfBirth;
    QLabel *lStudentFatherTelNo;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_3;
    QLabel *lStudentFullName;
    QLabel *label_2;
    QLabel *lStudentFatherOccupation;
    QLabel *label_10;
    QLabel *lStudentHomeAddress;
    QLabel *lStudentMotherOccupation;
    QLabel *label_9;
    QLabel *lStudentMotherTelNo;
    QLabel *lStudentHomeTelNo;
    QLabel *label_6;

    void setupUi(QDialog *StudentInformation)
    {
        if (StudentInformation->objectName().isEmpty())
            StudentInformation->setObjectName(QStringLiteral("StudentInformation"));
        StudentInformation->resize(594, 583);
        tabWidget = new QTabWidget(StudentInformation);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 601, 581));
        QFont font;
        font.setPointSize(12);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tWMarksSummery = new QTableWidget(tab);
        if (tWMarksSummery->columnCount() < 5)
            tWMarksSummery->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tWMarksSummery->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tWMarksSummery->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tWMarksSummery->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tWMarksSummery->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tWMarksSummery->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tWMarksSummery->setObjectName(QStringLiteral("tWMarksSummery"));
        tWMarksSummery->setGeometry(QRect(10, 20, 571, 481));
        tWMarksSummery->setFont(font);
        tWMarksSummery->setShowGrid(false);
        tWMarksSummery->setGridStyle(Qt::SolidLine);
        tWMarksSummery->horizontalHeader()->setDefaultSectionSize(110);
        tWMarksSummery->verticalHeader()->setVisible(false);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 390, 91, 21));
        textEdit = new QTextEdit(tab_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 410, 571, 91));
        textEdit->setReadOnly(true);
        lStudentName = new QLabel(tab_2);
        lStudentName->setObjectName(QStringLiteral("lStudentName"));
        lStudentName->setGeometry(QRect(200, 0, 191, 31));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        lStudentName->setFont(font1);
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(490, 512, 75, 31));
        widget = new QWidget(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 40, 521, 351));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lStudentMotherFullName = new QLabel(widget);
        lStudentMotherFullName->setObjectName(QStringLiteral("lStudentMotherFullName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lStudentMotherFullName->sizePolicy().hasHeightForWidth());
        lStudentMotherFullName->setSizePolicy(sizePolicy);
        lStudentMotherFullName->setMinimumSize(QSize(321, 21));
        lStudentMotherFullName->setMaximumSize(QSize(321, 21));
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        lStudentMotherFullName->setFont(font2);

        gridLayout->addWidget(lStudentMotherFullName, 5, 1, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        lStudentFatherFullName = new QLabel(widget);
        lStudentFatherFullName->setObjectName(QStringLiteral("lStudentFatherFullName"));
        sizePolicy.setHeightForWidth(lStudentFatherFullName->sizePolicy().hasHeightForWidth());
        lStudentFatherFullName->setSizePolicy(sizePolicy);
        lStudentFatherFullName->setMinimumSize(QSize(321, 21));
        lStudentFatherFullName->setMaximumSize(QSize(321, 21));
        lStudentFatherFullName->setFont(font2);

        gridLayout->addWidget(lStudentFatherFullName, 2, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        lStudentDateOfBirth = new QLabel(widget);
        lStudentDateOfBirth->setObjectName(QStringLiteral("lStudentDateOfBirth"));
        sizePolicy.setHeightForWidth(lStudentDateOfBirth->sizePolicy().hasHeightForWidth());
        lStudentDateOfBirth->setSizePolicy(sizePolicy);
        lStudentDateOfBirth->setMinimumSize(QSize(321, 21));
        lStudentDateOfBirth->setMaximumSize(QSize(321, 21));
        lStudentDateOfBirth->setFont(font2);

        gridLayout->addWidget(lStudentDateOfBirth, 1, 1, 1, 1);

        lStudentFatherTelNo = new QLabel(widget);
        lStudentFatherTelNo->setObjectName(QStringLiteral("lStudentFatherTelNo"));
        sizePolicy.setHeightForWidth(lStudentFatherTelNo->sizePolicy().hasHeightForWidth());
        lStudentFatherTelNo->setSizePolicy(sizePolicy);
        lStudentFatherTelNo->setMinimumSize(QSize(321, 21));
        lStudentFatherTelNo->setMaximumSize(QSize(321, 21));
        lStudentFatherTelNo->setFont(font2);

        gridLayout->addWidget(lStudentFatherTelNo, 4, 1, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lStudentFullName = new QLabel(widget);
        lStudentFullName->setObjectName(QStringLiteral("lStudentFullName"));
        sizePolicy.setHeightForWidth(lStudentFullName->sizePolicy().hasHeightForWidth());
        lStudentFullName->setSizePolicy(sizePolicy);
        lStudentFullName->setMinimumSize(QSize(321, 21));
        lStudentFullName->setMaximumSize(QSize(321, 21));
        lStudentFullName->setFont(font2);

        gridLayout->addWidget(lStudentFullName, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lStudentFatherOccupation = new QLabel(widget);
        lStudentFatherOccupation->setObjectName(QStringLiteral("lStudentFatherOccupation"));
        sizePolicy.setHeightForWidth(lStudentFatherOccupation->sizePolicy().hasHeightForWidth());
        lStudentFatherOccupation->setSizePolicy(sizePolicy);
        lStudentFatherOccupation->setMinimumSize(QSize(321, 21));
        lStudentFatherOccupation->setMaximumSize(QSize(321, 21));
        lStudentFatherOccupation->setFont(font2);

        gridLayout->addWidget(lStudentFatherOccupation, 3, 1, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        lStudentHomeAddress = new QLabel(widget);
        lStudentHomeAddress->setObjectName(QStringLiteral("lStudentHomeAddress"));
        sizePolicy.setHeightForWidth(lStudentHomeAddress->sizePolicy().hasHeightForWidth());
        lStudentHomeAddress->setSizePolicy(sizePolicy);
        lStudentHomeAddress->setMinimumSize(QSize(321, 21));
        lStudentHomeAddress->setMaximumSize(QSize(321, 21));
        lStudentHomeAddress->setFont(font2);

        gridLayout->addWidget(lStudentHomeAddress, 8, 1, 1, 1);

        lStudentMotherOccupation = new QLabel(widget);
        lStudentMotherOccupation->setObjectName(QStringLiteral("lStudentMotherOccupation"));
        sizePolicy.setHeightForWidth(lStudentMotherOccupation->sizePolicy().hasHeightForWidth());
        lStudentMotherOccupation->setSizePolicy(sizePolicy);
        lStudentMotherOccupation->setMinimumSize(QSize(321, 21));
        lStudentMotherOccupation->setMaximumSize(QSize(321, 21));
        lStudentMotherOccupation->setFont(font2);

        gridLayout->addWidget(lStudentMotherOccupation, 6, 1, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        lStudentMotherTelNo = new QLabel(widget);
        lStudentMotherTelNo->setObjectName(QStringLiteral("lStudentMotherTelNo"));
        sizePolicy.setHeightForWidth(lStudentMotherTelNo->sizePolicy().hasHeightForWidth());
        lStudentMotherTelNo->setSizePolicy(sizePolicy);
        lStudentMotherTelNo->setMinimumSize(QSize(321, 21));
        lStudentMotherTelNo->setMaximumSize(QSize(321, 21));
        lStudentMotherTelNo->setFont(font2);

        gridLayout->addWidget(lStudentMotherTelNo, 7, 1, 1, 1);

        lStudentHomeTelNo = new QLabel(widget);
        lStudentHomeTelNo->setObjectName(QStringLiteral("lStudentHomeTelNo"));
        sizePolicy.setHeightForWidth(lStudentHomeTelNo->sizePolicy().hasHeightForWidth());
        lStudentHomeTelNo->setSizePolicy(sizePolicy);
        lStudentHomeTelNo->setMinimumSize(QSize(321, 21));
        lStudentHomeTelNo->setMaximumSize(QSize(321, 21));
        lStudentHomeTelNo->setFont(font2);

        gridLayout->addWidget(lStudentHomeTelNo, 9, 1, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(StudentInformation);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StudentInformation);
    } // setupUi

    void retranslateUi(QDialog *StudentInformation)
    {
        StudentInformation->setWindowTitle(QApplication::translate("StudentInformation", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = tWMarksSummery->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("StudentInformation", "Subject", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tWMarksSummery->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("StudentInformation", "Papers", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tWMarksSummery->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("StudentInformation", "Marks", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tWMarksSummery->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("StudentInformation", "MarkState", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tWMarksSummery->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("StudentInformation", "type", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("StudentInformation", "Student Progress", 0));
        label_13->setText(QApplication::translate("StudentInformation", "Discription", 0));
        lStudentName->setText(QString());
        pushButton->setText(QApplication::translate("StudentInformation", "Close", 0));
        lStudentMotherFullName->setText(QString());
        label_8->setText(QApplication::translate("StudentInformation", "Mother Occupation", 0));
        label_4->setText(QApplication::translate("StudentInformation", "Mother Full Name", 0));
        lStudentFatherFullName->setText(QString());
        label_5->setText(QApplication::translate("StudentInformation", "Father Occupation", 0));
        lStudentDateOfBirth->setText(QString());
        lStudentFatherTelNo->setText(QString());
        label_7->setText(QApplication::translate("StudentInformation", "Father Tel No", 0));
        label_11->setText(QApplication::translate("StudentInformation", "Date of birth", 0));
        label_3->setText(QApplication::translate("StudentInformation", "Father Full Name", 0));
        lStudentFullName->setText(QString());
        label_2->setText(QApplication::translate("StudentInformation", "Student Full Name", 0));
        lStudentFatherOccupation->setText(QString());
        label_10->setText(QApplication::translate("StudentInformation", "Home TelNo", 0));
        lStudentHomeAddress->setText(QString());
        lStudentMotherOccupation->setText(QString());
        label_9->setText(QApplication::translate("StudentInformation", "Home Address ", 0));
        lStudentMotherTelNo->setText(QString());
        lStudentHomeTelNo->setText(QString());
        label_6->setText(QApplication::translate("StudentInformation", "Mother Tel No", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("StudentInformation", "Student Information", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentInformation: public Ui_StudentInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTINFORMATION_H
