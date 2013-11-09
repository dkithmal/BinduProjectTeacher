/********************************************************************************
** Form generated from reading UI file 'newmcqpaper.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMCQPAPER_H
#define UI_NEWMCQPAPER_H

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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewMcqPaper
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
    QWidget *tab_2;
    QGroupBox *gBHeader;
    QGroupBox *gBQuestions;
    QFrame *fQuestion1;
    QFrame *fQuestion2;
    QFrame *fQuestion3;
    QFrame *fQuestion4;
    QFrame *fQuestion5;
    QPushButton *pBCClose;
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

    void setupUi(QWidget *NewMcqPaper)
    {
        if (NewMcqPaper->objectName().isEmpty())
            NewMcqPaper->setObjectName(QStringLiteral("NewMcqPaper"));
        NewMcqPaper->resize(1122, 641);
        tWPaperCreation = new QTabWidget(NewMcqPaper);
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
        pBCClose = new QPushButton(tab_2);
        pBCClose->setObjectName(QStringLiteral("pBCClose"));
        pBCClose->setGeometry(QRect(984, 580, 131, 31));
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
        pBEClose->setGeometry(QRect(974, 580, 131, 31));
        pBENext = new QPushButton(tab_3);
        pBENext->setObjectName(QStringLiteral("pBENext"));
        pBENext->setGeometry(QRect(570, 580, 75, 31));
        pBEPrivious = new QPushButton(tab_3);
        pBEPrivious->setObjectName(QStringLiteral("pBEPrivious"));
        pBEPrivious->setGeometry(QRect(450, 580, 75, 31));
        tWPaperCreation->addTab(tab_3, QString());
        QWidget::setTabOrder(tWPaperCreation, lEMcqQuestion);
        QWidget::setTabOrder(lEMcqQuestion, cBNoOfChoises);
        QWidget::setTabOrder(cBNoOfChoises, lEAnswer1);
        QWidget::setTabOrder(lEAnswer1, lEAnswer2);
        QWidget::setTabOrder(lEAnswer2, lEAnswer3);
        QWidget::setTabOrder(lEAnswer3, lEAnswer4);
        QWidget::setTabOrder(lEAnswer4, pBAddMcq);
        QWidget::setTabOrder(pBAddMcq, pBClose);
        QWidget::setTabOrder(pBClose, pBPrivious);
        QWidget::setTabOrder(pBPrivious, pBNext);
        QWidget::setTabOrder(pBNext, pBCClose);
        QWidget::setTabOrder(pBCClose, pBEPrivious);
        QWidget::setTabOrder(pBEPrivious, pBENext);
        QWidget::setTabOrder(pBENext, pBEClose);

        retranslateUi(NewMcqPaper);
        QObject::connect(pBClose, SIGNAL(clicked()), NewMcqPaper, SLOT(close()));

        tWPaperCreation->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(NewMcqPaper);
    } // setupUi

    void retranslateUi(QWidget *NewMcqPaper)
    {
        NewMcqPaper->setWindowTitle(QApplication::translate("NewMcqPaper", "Niew Mcq Paper", 0));
        pBClose->setText(QApplication::translate("NewMcqPaper", "Close", 0));
        gBMcq->setTitle(QApplication::translate("NewMcqPaper", "Add MCQ question", 0));
        lMcqQuestion->setText(QApplication::translate("NewMcqPaper", "Question :", 0));
        lNoOfChoises->setText(QApplication::translate("NewMcqPaper", "No of Choises :", 0));
        cBNoOfChoises->clear();
        cBNoOfChoises->insertItems(0, QStringList()
         << QApplication::translate("NewMcqPaper", "2", 0)
         << QApplication::translate("NewMcqPaper", "3", 0)
         << QApplication::translate("NewMcqPaper", "4", 0)
        );
        lAnswer1->setText(QApplication::translate("NewMcqPaper", "Answer 1", 0));
        lAnswer2->setText(QApplication::translate("NewMcqPaper", "Answer 2", 0));
        lAnswer3->setText(QApplication::translate("NewMcqPaper", "Answer 3", 0));
        lAnswer4->setText(QApplication::translate("NewMcqPaper", "Answer 4", 0));
        pBAddMcq->setText(QApplication::translate("NewMcqPaper", "Add MCQ Qustion", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab), QApplication::translate("NewMcqPaper", "Add qustions", 0));
        gBHeader->setTitle(QString());
        gBQuestions->setTitle(QString());
        pBCClose->setText(QApplication::translate("NewMcqPaper", "Save All and Close", 0));
        pBPrivious->setText(QApplication::translate("NewMcqPaper", "Privious", 0));
        pBNext->setText(QApplication::translate("NewMcqPaper", "Next", 0));
        lPageNo->setText(QApplication::translate("NewMcqPaper", "1", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab_2), QApplication::translate("NewMcqPaper", "Create Answers", 0));
        gBEHeader->setTitle(QString());
        gBEQuestions->setTitle(QString());
        lEPageNo->setText(QApplication::translate("NewMcqPaper", "1", 0));
        pBEClose->setText(QApplication::translate("NewMcqPaper", "Save All and Close", 0));
        pBENext->setText(QApplication::translate("NewMcqPaper", "Next", 0));
        pBEPrivious->setText(QApplication::translate("NewMcqPaper", "Privious", 0));
        tWPaperCreation->setTabText(tWPaperCreation->indexOf(tab_3), QApplication::translate("NewMcqPaper", "Edit Questions", 0));
    } // retranslateUi

};

namespace Ui {
    class NewMcqPaper: public Ui_NewMcqPaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMCQPAPER_H
