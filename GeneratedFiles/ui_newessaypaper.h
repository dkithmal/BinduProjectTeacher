/********************************************************************************
** Form generated from reading UI file 'newessaypaper.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWESSAYPAPER_H
#define UI_NEWESSAYPAPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewEssayPaper
{
public:
    QTabWidget *tWPaperCreation;
    QWidget *tab;
    QPushButton *pBClose;
    QGroupBox *gBEssay;
    QLabel *lEssayQusesion;
    QLineEdit *lEEssayQuestion;
    QPushButton *pBAddEssayQuestion;
    QWidget *tab_2;
    QGroupBox *gBHeader;
    QGroupBox *gBQuestions;
    QFrame *fQuestion1;
    QFrame *fQuestion2;
    QFrame *fQuestion3;
    QFrame *fQuestion4;
    QFrame *fQuestion5;
    QPushButton *pushButton_2;
    QPushButton *pBPrivious;
    QPushButton *pBNext;
    QLabel *lPageNo;
    QWidget *tab_3;
    QGroupBox *gBEHeader;
    QGroupBox *gBEQuestions;
    QFrame *fEQuestion1;
    QFrame *fEQuestion2;
    QFrame *fEQuestion3;
    QFrame *fEQuestion4;
    QFrame *fEQuestion5;
    QLabel *lEPageNo;
    QPushButton *pBEClose;
    QPushButton *pBENext;
    QPushButton *pBEPrivious;

    void setupUi(QWidget *NewEssayPaper)
    {
        if (NewEssayPaper->objectName().isEmpty())
            NewEssayPaper->setObjectName(QStringLiteral("NewEssayPaper"));
        NewEssayPaper->resize(1122, 641);
        tWPaperCreation = new QTabWidget(NewEssayPaper);
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
        gBEssay = new QGroupBox(tab);
        gBEssay->setObjectName(QStringLiteral("gBEssay"));
        gBEssay->setGeometry(QRect(0, 160, 1111, 191));
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
        QFont font1;
        font1.setPointSize(12);
        gBHeader->setFont(font1);
        gBQuestions = new QGroupBox(tab_2);
        gBQuestions->setObjectName(QStringLiteral("gBQuestions"));
        gBQuestions->setGeometry(QRect(0, 80, 1111, 501));
        QFont font2;
        font2.setPointSize(11);
        gBQuestions->setFont(font2);
        fQuestion1 = new QFrame(gBQuestions);
        fQuestion1->setObjectName(QStringLiteral("fQuestion1"));
        fQuestion1->setGeometry(QRect(0, 0, 1110, 100));
        fQuestion1->setFrameShape(QFrame::StyledPanel);
        fQuestion1->setFrameShadow(QFrame::Raised);
        fQuestion2 = new QFrame(gBQuestions);
        fQuestion2->setObjectName(QStringLiteral("fQuestion2"));
        fQuestion2->setGeometry(QRect(0, 100, 1110, 100));
        fQuestion2->setFrameShape(QFrame::StyledPanel);
        fQuestion2->setFrameShadow(QFrame::Raised);
        fQuestion3 = new QFrame(gBQuestions);
        fQuestion3->setObjectName(QStringLiteral("fQuestion3"));
        fQuestion3->setGeometry(QRect(0, 200, 1110, 100));
        fQuestion3->setFrameShape(QFrame::StyledPanel);
        fQuestion3->setFrameShadow(QFrame::Raised);
        fQuestion4 = new QFrame(gBQuestions);
        fQuestion4->setObjectName(QStringLiteral("fQuestion4"));
        fQuestion4->setGeometry(QRect(0, 300, 1110, 100));
        fQuestion4->setFrameShape(QFrame::StyledPanel);
        fQuestion4->setFrameShadow(QFrame::Raised);
        fQuestion5 = new QFrame(gBQuestions);
        fQuestion5->setObjectName(QStringLiteral("fQuestion5"));
        fQuestion5->setGeometry(QRect(0, 400, 1110, 100));
        fQuestion5->setFrameShape(QFrame::StyledPanel);
        fQuestion5->setFrameShadow(QFrame::Raised);
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
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        lPageNo->setFont(font3);
        tWPaperCreation->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gBEHeader = new QGroupBox(tab_3);
        gBEHeader->setObjectName(QStringLiteral("gBEHeader"));
        gBEHeader->setGeometry(QRect(0, 0, 1111, 81));
        gBEHeader->setFont(font1);
        gBEQuestions = new QGroupBox(tab_3);
        gBEQuestions->setObjectName(QStringLiteral("gBEQuestions"));
        gBEQuestions->setGeometry(QRect(0, 80, 1111, 501));
        gBEQuestions->setFont(font2);
        fEQuestion1 = new QFrame(gBEQuestions);
        fEQuestion1->setObjectName(QStringLiteral("fEQuestion1"));
        fEQuestion1->setGeometry(QRect(0, 0, 1110, 100));
        fEQuestion1->setFrameShape(QFrame::StyledPanel);
        fEQuestion1->setFrameShadow(QFrame::Raised);
        fEQuestion2 = new QFrame(gBEQuestions);
        fEQuestion2->setObjectName(QStringLiteral("fEQuestion2"));
        fEQuestion2->setGeometry(QRect(0, 100, 1110, 100));
        fEQuestion2->setFrameShape(QFrame::StyledPanel);
        fEQuestion2->setFrameShadow(QFrame::Raised);
        fEQuestion3 = new QFrame(gBEQuestions);
        fEQuestion3->setObjectName(QStringLiteral("fEQuestion3"));
        fEQuestion3->setGeometry(QRect(0, 200, 1110, 100));
        fEQuestion3->setFrameShape(QFrame::StyledPanel);
        fEQuestion3->setFrameShadow(QFrame::Raised);
        fEQuestion4 = new QFrame(gBEQuestions);
        fEQuestion4->setObjectName(QStringLiteral("fEQuestion4"));
        fEQuestion4->setGeometry(QRect(0, 300, 1110, 100));
        fEQuestion4->setFrameShape(QFrame::StyledPanel);
        fEQuestion4->setFrameShadow(QFrame::Raised);
        fEQuestion5 = new QFrame(gBEQuestions);
        fEQuestion5->setObjectName(QStringLiteral("fEQuestion5"));
        fEQuestion5->setGeometry(QRect(0, 400, 1110, 100));
        fEQuestion5->setFrameShape(QFrame::StyledPanel);
        fEQuestion5->setFrameShadow(QFrame::Raised);
        lEPageNo = new QLabel(tab_3);
        lEPageNo->setObjectName(QStringLiteral("lEPageNo"));
        lEPageNo->setGeometry(QRect(540, 590, 21, 16));
        lEPageNo->setFont(font3);
        pBEClose = new QPushButton(tab_3);
        pBEClose->setObjectName(QStringLiteral("pBEClose"));
        pBEClose->setGeometry(QRect(1030, 580, 75, 31));
        pBENext = new QPushButton(tab_3);
        pBENext->setObjectName(QStringLiteral("pBENext"));
        pBENext->setGeometry(QRect(570, 580, 75, 31));
        pBEPrivious = new QPushButton(tab_3);
        pBEPrivious->setObjectName(QStringLiteral("pBEPrivious"));
        pBEPrivious->setGeometry(QRect(450, 580, 75, 31));
        tWPaperCreation->addTab(tab_3, QString());

        retranslateUi(NewEssayPaper);

        tWPaperCreation->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(NewEssayPaper);
    } // setupUi

    void retranslateUi(QWidget *NewEssayPaper)
    {
        NewEssayPaper->setWindowTitle(QApplication::translate("NewEssayPaper", "Form", 0));
        pBClose->setText(QApplication::translate("NewEssayPaper", "Close", 0));
        gBEssay->setTitle(QApplication::translate("NewEssayPaper", "Add Essay Question", 0));
        lEssayQusesion->setText(QApplication::translate("NewEssayPaper", "Question :", 0));
        pBAddEssayQuestion->setText(QApplication::translate("NewEssayPaper", "Add Essay Question", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab), QApplication::translate("NewEssayPaper", "Add qustions", 0));
        gBHeader->setTitle(QString());
        gBQuestions->setTitle(QString());
        pushButton_2->setText(QApplication::translate("NewEssayPaper", "Close", 0));
        pBPrivious->setText(QApplication::translate("NewEssayPaper", "Privious", 0));
        pBNext->setText(QApplication::translate("NewEssayPaper", "Next", 0));
        lPageNo->setText(QApplication::translate("NewEssayPaper", "1", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab_2), QApplication::translate("NewEssayPaper", "Create Answers", 0));
        gBEHeader->setTitle(QString());
        gBEQuestions->setTitle(QString());
        lEPageNo->setText(QApplication::translate("NewEssayPaper", "1", 0));
        pBEClose->setText(QApplication::translate("NewEssayPaper", "Close", 0));
        pBENext->setText(QApplication::translate("NewEssayPaper", "Next", 0));
        pBEPrivious->setText(QApplication::translate("NewEssayPaper", "Privious", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab_3), QApplication::translate("NewEssayPaper", "Edit Questions", 0));
    } // retranslateUi

};

namespace Ui {
    class NewEssayPaper: public Ui_NewEssayPaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWESSAYPAPER_H