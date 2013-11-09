/********************************************************************************
** Form generated from reading UI file 'papersummary.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAPERSUMMARY_H
#define UI_PAPERSUMMARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Papersummary
{
public:
    QTableWidget *tWStudentPaperSummery;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *lGrade;
    QLabel *label_5;
    QLabel *lClass;
    QLabel *label;
    QLabel *lPaperName;
    QLabel *label_2;
    QLabel *lPaperType;

    void setupUi(QDialog *Papersummary)
    {
        if (Papersummary->objectName().isEmpty())
            Papersummary->setObjectName(QStringLiteral("Papersummary"));
        Papersummary->resize(643, 533);
        tWStudentPaperSummery = new QTableWidget(Papersummary);
        if (tWStudentPaperSummery->columnCount() < 4)
            tWStudentPaperSummery->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tWStudentPaperSummery->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tWStudentPaperSummery->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tWStudentPaperSummery->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tWStudentPaperSummery->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tWStudentPaperSummery->setObjectName(QStringLiteral("tWStudentPaperSummery"));
        tWStudentPaperSummery->setGeometry(QRect(10, 60, 621, 431));
        QFont font;
        font.setPointSize(12);
        tWStudentPaperSummery->setFont(font);
        tWStudentPaperSummery->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tWStudentPaperSummery->horizontalHeader()->setDefaultSectionSize(150);
        pushButton = new QPushButton(Papersummary);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 500, 75, 31));
        layoutWidget = new QWidget(Papersummary);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 591, 44));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        lGrade = new QLabel(layoutWidget);
        lGrade->setObjectName(QStringLiteral("lGrade"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        lGrade->setFont(font2);

        gridLayout->addWidget(lGrade, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        lClass = new QLabel(layoutWidget);
        lClass->setObjectName(QStringLiteral("lClass"));
        lClass->setFont(font2);

        gridLayout->addWidget(lClass, 0, 3, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lPaperName = new QLabel(layoutWidget);
        lPaperName->setObjectName(QStringLiteral("lPaperName"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        lPaperName->setFont(font3);

        gridLayout->addWidget(lPaperName, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        lPaperType = new QLabel(layoutWidget);
        lPaperType->setObjectName(QStringLiteral("lPaperType"));
        lPaperType->setFont(font3);

        gridLayout->addWidget(lPaperType, 1, 3, 1, 1);


        retranslateUi(Papersummary);
        QObject::connect(pushButton, SIGNAL(clicked()), Papersummary, SLOT(close()));

        QMetaObject::connectSlotsByName(Papersummary);
    } // setupUi

    void retranslateUi(QDialog *Papersummary)
    {
        Papersummary->setWindowTitle(QApplication::translate("Papersummary", "Summery Of paper", 0));
        QTableWidgetItem *___qtablewidgetitem = tWStudentPaperSummery->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Papersummary", "Student Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tWStudentPaperSummery->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Papersummary", "Marks", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tWStudentPaperSummery->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Papersummary", "State", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tWStudentPaperSummery->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Papersummary", " View Paper", 0));
        pushButton->setText(QApplication::translate("Papersummary", "Close", 0));
        label_3->setText(QApplication::translate("Papersummary", "Grade ", 0));
        lGrade->setText(QString());
        label_5->setText(QApplication::translate("Papersummary", "Class", 0));
        lClass->setText(QString());
        label->setText(QApplication::translate("Papersummary", "Paper Name", 0));
        lPaperName->setText(QString());
        label_2->setText(QApplication::translate("Papersummary", "Type", 0));
        lPaperType->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Papersummary: public Ui_Papersummary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAPERSUMMARY_H
