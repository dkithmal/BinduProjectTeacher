#ifndef NEWMCQPAPER_H
#define NEWMCQPAPER_H

#include <QDialog>
#include <QMainWindow>
#include <QTableWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QRadioButton>
#include <QLabel>
#include <QtGui>


namespace Ui {
class NewMcqPaper;
}

class NewMcqPaper : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewMcqPaper(QDialog *parent = 0,QString filePath=NULL);
    ~NewMcqPaper();
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
     QFrame *mcqFrames[25];
     QGridLayout  *questionLayout[5];
     QLabel *qusestionLables[50];
     QTextEdit *qusestionEdit[50];


    
private slots:
     void on_cBNoOfChoises_currentIndexChanged(int index);

     void on_pBAddMcq_clicked();

     void on_tWPaperCreation_currentChanged(int index);

     void on_pBPrivious_clicked();

     void on_pBNext_clicked();

     void on_pBEPrivious_clicked();

     void on_pBENext_clicked();

     void on_pBCClose_clicked();

     void on_pBEClose_clicked();

private:
    Ui::NewMcqPaper *ui;
};

#endif // NEWMCQPAPER_H
