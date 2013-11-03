/********************************************************************************
** Form generated from reading UI file 'markingpapers.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKINGPAPERS_H
#define UI_MARKINGPAPERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MarkingPapers
{
public:
    QPushButton *pushButton_2;
    QPushButton *pBPrivious;
    QLabel *lPageNo;
    QGroupBox *gBQuestions;
    QFrame *fQuestion1;
    QFrame *fQuestion2;
    QFrame *fQuestion3;
    QFrame *fQuestion4;
    QFrame *fQuestion5;
    QPushButton *pBNext;
    QGroupBox *gBHeader;

    void setupUi(QDialog *MarkingPapers)
    {
        if (MarkingPapers->objectName().isEmpty())
            MarkingPapers->setObjectName(QStringLiteral("MarkingPapers"));
        MarkingPapers->resize(1117, 627);
        pushButton_2 = new QPushButton(MarkingPapers);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1030, 580, 75, 31));
        pBPrivious = new QPushButton(MarkingPapers);
        pBPrivious->setObjectName(QStringLiteral("pBPrivious"));
        pBPrivious->setGeometry(QRect(450, 582, 75, 31));
        lPageNo = new QLabel(MarkingPapers);
        lPageNo->setObjectName(QStringLiteral("lPageNo"));
        lPageNo->setGeometry(QRect(550, 590, 21, 16));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        lPageNo->setFont(font);
        gBQuestions = new QGroupBox(MarkingPapers);
        gBQuestions->setObjectName(QStringLiteral("gBQuestions"));
        gBQuestions->setGeometry(QRect(0, 80, 1111, 501));
        QFont font1;
        font1.setPointSize(11);
        gBQuestions->setFont(font1);
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
        pBNext = new QPushButton(MarkingPapers);
        pBNext->setObjectName(QStringLiteral("pBNext"));
        pBNext->setGeometry(QRect(580, 582, 75, 31));
        gBHeader = new QGroupBox(MarkingPapers);
        gBHeader->setObjectName(QStringLiteral("gBHeader"));
        gBHeader->setGeometry(QRect(0, 0, 1111, 81));
        QFont font2;
        font2.setPointSize(12);
        gBHeader->setFont(font2);

        retranslateUi(MarkingPapers);

        QMetaObject::connectSlotsByName(MarkingPapers);
    } // setupUi

    void retranslateUi(QDialog *MarkingPapers)
    {
        MarkingPapers->setWindowTitle(QApplication::translate("MarkingPapers", "Dialog", 0));
        pushButton_2->setText(QApplication::translate("MarkingPapers", "Close", 0));
        pBPrivious->setText(QApplication::translate("MarkingPapers", "Privious", 0));
        lPageNo->setText(QApplication::translate("MarkingPapers", "1", 0));
        gBQuestions->setTitle(QString());
        pBNext->setText(QApplication::translate("MarkingPapers", "Next", 0));
        gBHeader->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MarkingPapers: public Ui_MarkingPapers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKINGPAPERS_H
