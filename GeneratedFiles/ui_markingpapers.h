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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MarkingPapers
{
public:
    QPushButton *pBSaveMarks;
    QPushButton *pBPrivious;
    QLabel *lPageNo;
    QGroupBox *gBQuestions;
    QFrame *fQuestion1;
    QFrame *fQuestion2;
    QFrame *fQuestion3;
    QFrame *fQuestion4;
    QFrame *fQuestion5;
    QLabel *lAnswer1TMark;
    QLineEdit *lEAnswer1Marks;
    QLabel *lAnswer2TMarks;
    QLineEdit *lEAnswer2Marks;
    QLineEdit *lEAnswer3Marks;
    QLabel *lAnswer3TMarks;
    QLabel *lAnswer5TMarks;
    QLineEdit *lEAnswer5Marks;
    QLabel *lAnswer4TMarks;
    QLineEdit *lEAnswer4Marks;
    QPushButton *pBNext;
    QGroupBox *gBHeader;
    QLabel *label_6;
    QLineEdit *lETotalMarks;
    QLabel *label;
    QLabel *lStudentName;

    void setupUi(QDialog *MarkingPapers)
    {
        if (MarkingPapers->objectName().isEmpty())
            MarkingPapers->setObjectName(QStringLiteral("MarkingPapers"));
        MarkingPapers->resize(1117, 627);
        pBSaveMarks = new QPushButton(MarkingPapers);
        pBSaveMarks->setObjectName(QStringLiteral("pBSaveMarks"));
        pBSaveMarks->setGeometry(QRect(964, 580, 141, 31));
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
        fQuestion1->setGeometry(QRect(0, 0, 1001, 100));
        fQuestion1->setFrameShape(QFrame::StyledPanel);
        fQuestion1->setFrameShadow(QFrame::Raised);
        fQuestion2 = new QFrame(gBQuestions);
        fQuestion2->setObjectName(QStringLiteral("fQuestion2"));
        fQuestion2->setGeometry(QRect(0, 100, 1001, 100));
        fQuestion2->setFrameShape(QFrame::StyledPanel);
        fQuestion2->setFrameShadow(QFrame::Raised);
        fQuestion3 = new QFrame(gBQuestions);
        fQuestion3->setObjectName(QStringLiteral("fQuestion3"));
        fQuestion3->setGeometry(QRect(0, 200, 1001, 100));
        fQuestion3->setFrameShape(QFrame::StyledPanel);
        fQuestion3->setFrameShadow(QFrame::Raised);
        fQuestion4 = new QFrame(gBQuestions);
        fQuestion4->setObjectName(QStringLiteral("fQuestion4"));
        fQuestion4->setGeometry(QRect(0, 300, 1001, 100));
        fQuestion4->setFrameShape(QFrame::StyledPanel);
        fQuestion4->setFrameShadow(QFrame::Raised);
        fQuestion5 = new QFrame(gBQuestions);
        fQuestion5->setObjectName(QStringLiteral("fQuestion5"));
        fQuestion5->setGeometry(QRect(0, 400, 1001, 100));
        fQuestion5->setFrameShape(QFrame::StyledPanel);
        fQuestion5->setFrameShadow(QFrame::Raised);
        lAnswer1TMark = new QLabel(gBQuestions);
        lAnswer1TMark->setObjectName(QStringLiteral("lAnswer1TMark"));
        lAnswer1TMark->setGeometry(QRect(1060, 30, 46, 31));
        lEAnswer1Marks = new QLineEdit(gBQuestions);
        lEAnswer1Marks->setObjectName(QStringLiteral("lEAnswer1Marks"));
        lEAnswer1Marks->setEnabled(true);
        lEAnswer1Marks->setGeometry(QRect(1000, 30, 61, 31));
        lEAnswer1Marks->setEchoMode(QLineEdit::Normal);
        lAnswer2TMarks = new QLabel(gBQuestions);
        lAnswer2TMarks->setObjectName(QStringLiteral("lAnswer2TMarks"));
        lAnswer2TMarks->setGeometry(QRect(1060, 130, 46, 31));
        lEAnswer2Marks = new QLineEdit(gBQuestions);
        lEAnswer2Marks->setObjectName(QStringLiteral("lEAnswer2Marks"));
        lEAnswer2Marks->setGeometry(QRect(1000, 130, 61, 31));
        lEAnswer3Marks = new QLineEdit(gBQuestions);
        lEAnswer3Marks->setObjectName(QStringLiteral("lEAnswer3Marks"));
        lEAnswer3Marks->setGeometry(QRect(1000, 240, 61, 31));
        lAnswer3TMarks = new QLabel(gBQuestions);
        lAnswer3TMarks->setObjectName(QStringLiteral("lAnswer3TMarks"));
        lAnswer3TMarks->setGeometry(QRect(1060, 240, 46, 31));
        lAnswer5TMarks = new QLabel(gBQuestions);
        lAnswer5TMarks->setObjectName(QStringLiteral("lAnswer5TMarks"));
        lAnswer5TMarks->setGeometry(QRect(1060, 430, 46, 31));
        lEAnswer5Marks = new QLineEdit(gBQuestions);
        lEAnswer5Marks->setObjectName(QStringLiteral("lEAnswer5Marks"));
        lEAnswer5Marks->setGeometry(QRect(1000, 430, 61, 31));
        lAnswer4TMarks = new QLabel(gBQuestions);
        lAnswer4TMarks->setObjectName(QStringLiteral("lAnswer4TMarks"));
        lAnswer4TMarks->setGeometry(QRect(1060, 330, 46, 31));
        lEAnswer4Marks = new QLineEdit(gBQuestions);
        lEAnswer4Marks->setObjectName(QStringLiteral("lEAnswer4Marks"));
        lEAnswer4Marks->setGeometry(QRect(1000, 330, 61, 31));
        fQuestion1->raise();
        fQuestion2->raise();
        fQuestion3->raise();
        fQuestion4->raise();
        fQuestion5->raise();
        lAnswer1TMark->raise();
        lEAnswer1Marks->raise();
        lAnswer2TMarks->raise();
        lEAnswer2Marks->raise();
        lAnswer3TMarks->raise();
        lEAnswer3Marks->raise();
        lEAnswer3Marks->raise();
        lAnswer3TMarks->raise();
        lAnswer5TMarks->raise();
        lEAnswer5Marks->raise();
        lAnswer4TMarks->raise();
        lEAnswer4Marks->raise();
        pBNext = new QPushButton(MarkingPapers);
        pBNext->setObjectName(QStringLiteral("pBNext"));
        pBNext->setGeometry(QRect(580, 582, 75, 31));
        gBHeader = new QGroupBox(MarkingPapers);
        gBHeader->setObjectName(QStringLiteral("gBHeader"));
        gBHeader->setGeometry(QRect(0, 0, 1111, 81));
        QFont font2;
        font2.setPointSize(12);
        gBHeader->setFont(font2);
        label_6 = new QLabel(gBHeader);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(920, 40, 91, 31));
        lETotalMarks = new QLineEdit(gBHeader);
        lETotalMarks->setObjectName(QStringLiteral("lETotalMarks"));
        lETotalMarks->setGeometry(QRect(1020, 40, 91, 31));
        QFont font3;
        font3.setPointSize(15);
        lETotalMarks->setFont(font3);
        label = new QLabel(gBHeader);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(855, 13, 101, 20));
        lStudentName = new QLabel(gBHeader);
        lStudentName->setObjectName(QStringLiteral("lStudentName"));
        lStudentName->setGeometry(QRect(970, 10, 131, 21));

        retranslateUi(MarkingPapers);

        QMetaObject::connectSlotsByName(MarkingPapers);
    } // setupUi

    void retranslateUi(QDialog *MarkingPapers)
    {
        MarkingPapers->setWindowTitle(QApplication::translate("MarkingPapers", "Dialog", 0));
        pBSaveMarks->setText(QApplication::translate("MarkingPapers", "Save All Marks And Close", 0));
        pBPrivious->setText(QApplication::translate("MarkingPapers", "Privious", 0));
        lPageNo->setText(QApplication::translate("MarkingPapers", "1", 0));
        gBQuestions->setTitle(QString());
        lAnswer1TMark->setText(QString());
        lAnswer2TMarks->setText(QString());
        lAnswer3TMarks->setText(QString());
        lAnswer5TMarks->setText(QString());
        lAnswer4TMarks->setText(QString());
        pBNext->setText(QApplication::translate("MarkingPapers", "Next", 0));
        gBHeader->setTitle(QString());
        label_6->setText(QApplication::translate("MarkingPapers", "Total Marks", 0));
        label->setText(QApplication::translate("MarkingPapers", "student Name", 0));
        lStudentName->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MarkingPapers: public Ui_MarkingPapers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKINGPAPERS_H
