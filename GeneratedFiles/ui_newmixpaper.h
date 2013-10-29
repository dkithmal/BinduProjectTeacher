/********************************************************************************
** Form generated from reading UI file 'newmixpaper.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMIXPAPER_H
#define UI_NEWMIXPAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewMixPaper
{
public:
    QTabWidget *tWPaperCreation;
    QWidget *tab;
    QPushButton *pBClose;
    QGroupBox *gBMcq;
    QLabel *lMcqQuestion;
    QLineEdit *lEMcqQuestion;
    QLabel *lNoOfChoises;
    QComboBox *cBNoOfChoises;
    QLabel *lAnswer1;
    QLineEdit *lEAnswer1;
    QLabel *lAnswer2;
    QLineEdit *lEAnswer2;
    QLabel *lAnswer3;
    QLineEdit *lEAnswer3;
    QLabel *lAnswer4;
    QLineEdit *lEAnswer4;
    QPushButton *pBAddMcq;
    QGroupBox *gBEssay;
    QLabel *lEssayQusesion;
    QLineEdit *lEEssayQuestion;
    QPushButton *pBAddEssayQuestion;
    QWidget *tab_2;
    QGroupBox *gBHeader;
    QGroupBox *gBQuestions;
    QPushButton *pushButton_2;
    QPushButton *pBPrivious;
    QPushButton *pBNext;
    QLabel *lPageNo;

    void setupUi(QWidget *NewMixPaper)
    {
        if (NewMixPaper->objectName().isEmpty())
            NewMixPaper->setObjectName(QStringLiteral("NewMixPaper"));
        NewMixPaper->resize(1123, 641);
        tWPaperCreation = new QTabWidget(NewMixPaper);
        tWPaperCreation->setObjectName(QStringLiteral("tWPaperCreation"));
        tWPaperCreation->setGeometry(QRect(0, 0, 1121, 641));
        QFont font;
        font.setPointSize(9);
        tWPaperCreation->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        pBClose = new QPushButton(tab);
        pBClose->setObjectName(QStringLiteral("pBClose"));
        pBClose->setGeometry(QRect(1020, 560, 75, 31));
        gBMcq = new QGroupBox(tab);
        gBMcq->setObjectName(QStringLiteral("gBMcq"));
        gBMcq->setGeometry(QRect(0, 0, 1141, 341));
        lMcqQuestion = new QLabel(gBMcq);
        lMcqQuestion->setObjectName(QStringLiteral("lMcqQuestion"));
        lMcqQuestion->setGeometry(QRect(50, 50, 71, 21));
        lEMcqQuestion = new QLineEdit(gBMcq);
        lEMcqQuestion->setObjectName(QStringLiteral("lEMcqQuestion"));
        lEMcqQuestion->setGeometry(QRect(160, 30, 721, 61));
        lEMcqQuestion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lNoOfChoises = new QLabel(gBMcq);
        lNoOfChoises->setObjectName(QStringLiteral("lNoOfChoises"));
        lNoOfChoises->setGeometry(QRect(50, 120, 91, 16));
        cBNoOfChoises = new QComboBox(gBMcq);
        cBNoOfChoises->setObjectName(QStringLiteral("cBNoOfChoises"));
        cBNoOfChoises->setGeometry(QRect(160, 120, 41, 31));
        lAnswer1 = new QLabel(gBMcq);
        lAnswer1->setObjectName(QStringLiteral("lAnswer1"));
        lAnswer1->setGeometry(QRect(50, 180, 61, 16));
        lEAnswer1 = new QLineEdit(gBMcq);
        lEAnswer1->setObjectName(QStringLiteral("lEAnswer1"));
        lEAnswer1->setGeometry(QRect(160, 170, 391, 31));
        lEAnswer1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lAnswer2 = new QLabel(gBMcq);
        lAnswer2->setObjectName(QStringLiteral("lAnswer2"));
        lAnswer2->setGeometry(QRect(600, 180, 81, 16));
        lEAnswer2 = new QLineEdit(gBMcq);
        lEAnswer2->setObjectName(QStringLiteral("lEAnswer2"));
        lEAnswer2->setGeometry(QRect(670, 170, 421, 31));
        lAnswer3 = new QLabel(gBMcq);
        lAnswer3->setObjectName(QStringLiteral("lAnswer3"));
        lAnswer3->setGeometry(QRect(50, 230, 61, 16));
        lEAnswer3 = new QLineEdit(gBMcq);
        lEAnswer3->setObjectName(QStringLiteral("lEAnswer3"));
        lEAnswer3->setGeometry(QRect(160, 220, 391, 31));
        lAnswer4 = new QLabel(gBMcq);
        lAnswer4->setObjectName(QStringLiteral("lAnswer4"));
        lAnswer4->setGeometry(QRect(600, 225, 61, 21));
        lEAnswer4 = new QLineEdit(gBMcq);
        lEAnswer4->setObjectName(QStringLiteral("lEAnswer4"));
        lEAnswer4->setGeometry(QRect(670, 220, 421, 31));
        pBAddMcq = new QPushButton(gBMcq);
        pBAddMcq->setObjectName(QStringLiteral("pBAddMcq"));
        pBAddMcq->setGeometry(QRect(480, 290, 231, 41));
        gBEssay = new QGroupBox(tab);
        gBEssay->setObjectName(QStringLiteral("gBEssay"));
        gBEssay->setGeometry(QRect(0, 350, 1141, 191));
        lEssayQusesion = new QLabel(gBEssay);
        lEssayQusesion->setObjectName(QStringLiteral("lEssayQusesion"));
        lEssayQusesion->setGeometry(QRect(60, 70, 81, 21));
        lEEssayQuestion = new QLineEdit(gBEssay);
        lEEssayQuestion->setObjectName(QStringLiteral("lEEssayQuestion"));
        lEEssayQuestion->setGeometry(QRect(150, 50, 711, 71));
        lEEssayQuestion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        pBAddEssayQuestion = new QPushButton(gBEssay);
        pBAddEssayQuestion->setObjectName(QStringLiteral("pBAddEssayQuestion"));
        pBAddEssayQuestion->setGeometry(QRect(480, 140, 241, 41));
        tWPaperCreation->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gBHeader = new QGroupBox(tab_2);
        gBHeader->setObjectName(QStringLiteral("gBHeader"));
        gBHeader->setGeometry(QRect(0, 0, 1111, 81));
        gBQuestions = new QGroupBox(tab_2);
        gBQuestions->setObjectName(QStringLiteral("gBQuestions"));
        gBQuestions->setGeometry(QRect(0, 80, 1111, 501));
        QFont font1;
        font1.setPointSize(8);
        gBQuestions->setFont(font1);
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1040, 580, 75, 31));
        pBPrivious = new QPushButton(tab_2);
        pBPrivious->setObjectName(QStringLiteral("pBPrivious"));
        pBPrivious->setGeometry(QRect(450, 582, 75, 31));
        pBNext = new QPushButton(tab_2);
        pBNext->setObjectName(QStringLiteral("pBNext"));
        pBNext->setGeometry(QRect(580, 582, 75, 31));
        lPageNo = new QLabel(tab_2);
        lPageNo->setObjectName(QStringLiteral("lPageNo"));
        lPageNo->setGeometry(QRect(550, 590, 21, 16));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        lPageNo->setFont(font2);
        tWPaperCreation->addTab(tab_2, QString());

        retranslateUi(NewMixPaper);
        QObject::connect(pBClose, SIGNAL(clicked()), NewMixPaper, SLOT(close()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), NewMixPaper, SLOT(close()));

        tWPaperCreation->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(NewMixPaper);
    } // setupUi

    void retranslateUi(QWidget *NewMixPaper)
    {
        NewMixPaper->setWindowTitle(QApplication::translate("NewMixPaper", "Form", 0));
        pBClose->setText(QApplication::translate("NewMixPaper", "Close", 0));
        gBMcq->setTitle(QApplication::translate("NewMixPaper", "Add MCQ question", 0));
        lMcqQuestion->setText(QApplication::translate("NewMixPaper", "Question :", 0));
        lNoOfChoises->setText(QApplication::translate("NewMixPaper", "No of Choises :", 0));
        cBNoOfChoises->clear();
        cBNoOfChoises->insertItems(0, QStringList()
         << QApplication::translate("NewMixPaper", "2", 0)
         << QApplication::translate("NewMixPaper", "3", 0)
         << QApplication::translate("NewMixPaper", "4", 0)
        );
        lAnswer1->setText(QApplication::translate("NewMixPaper", "Answer 1", 0));
        lAnswer2->setText(QApplication::translate("NewMixPaper", "Answer 2", 0));
        lAnswer3->setText(QApplication::translate("NewMixPaper", "Answer 3", 0));
        lAnswer4->setText(QApplication::translate("NewMixPaper", "Answer 4", 0));
        pBAddMcq->setText(QApplication::translate("NewMixPaper", "Add MCQ Qustion", 0));
        gBEssay->setTitle(QApplication::translate("NewMixPaper", "Add Essay Question", 0));
        lEssayQusesion->setText(QApplication::translate("NewMixPaper", "Question :", 0));
        pBAddEssayQuestion->setText(QApplication::translate("NewMixPaper", "Add Essay Question", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab), QApplication::translate("NewMixPaper", "Add qustions", 0));
        gBHeader->setTitle(QString());
        gBQuestions->setTitle(QString());
        pushButton_2->setText(QApplication::translate("NewMixPaper", "Close", 0));
        pBPrivious->setText(QApplication::translate("NewMixPaper", "Privious", 0));
        pBNext->setText(QApplication::translate("NewMixPaper", "Next", 0));
        lPageNo->setText(QApplication::translate("NewMixPaper", "1", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab_2), QApplication::translate("NewMixPaper", "View Paper", 0));
    } // retranslateUi

};

namespace Ui {
    class NewMixPaper: public Ui_NewMixPaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMIXPAPER_H
