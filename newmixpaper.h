#ifndef NEWMIXPAPER_H
#define NEWMIXPAPER_H

#include <QMainWindow>
#include <QDialog>
#include <QTableWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include <QtWidgets>
#include <QtGui>

namespace Ui {
class NewMixPaper;
}

class NewMixPaper : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewMixPaper(QDialog *parent = 0,QString filePath=NULL);
    ~NewMixPaper();
    void drowHeader(QDomElement root);
    void drowEditQuestions(QDomElement root);
    void drowQuestions(QDomElement root);
    void toCreatePaperLayout();
    void saveAnswers();
    void saveEditedQuestions();
    void setQuestionNo();
    QString paperCrationPath;

    int qustionNo;
    int mcqNo;
    int essayNO;
    int totalNoOfQuestions;
    int indexofTabWidget;

     QVBoxLayout *paperHeaderLayout;
     QVBoxLayout *paperQuestionsLayout;

     QRadioButton *rBMcqAnswers[25][4];
     QLineEdit *lEMcqAnswers[25][4];
     //QFrame *mcqFrames[25];
     QGridLayout  *questionLayout[5];
     QLabel *qusestionLables[50];
     QTextEdit *qusestionEdit[50];
     QTextEdit *essayAnswers[25];
    QLineEdit *essayMarks[25];

     //QVBoxLayout  *essayQuestionLayout[5];
    
private slots:
    void on_cBNoOfChoises_currentIndexChanged(int index);

    void on_pBAddMcq_clicked();

    void on_pBAddEssayQuestion_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tWPaperCreation_currentChanged(int index);

    void on_pBPrivious_clicked();

    void on_pBNext_clicked();

    void on_pBEPrivious_clicked();

    void on_pBENext_clicked();

    void on_pushButton_2_clicked();

    void on_pBEClose_clicked();

private:
    Ui::NewMixPaper *ui;
};

#endif // NEWMIXPAPER_H
