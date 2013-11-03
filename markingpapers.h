#ifndef MARKINGPAPERS_H
#define MARKINGPAPERS_H

#include <QMainWindow>
#include <QTableWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include <QtWidgets>
#include <QtGui>

namespace Ui {
class MarkingPapers;
}

class MarkingPapers : public QDialog
{
    Q_OBJECT
    
public:
    explicit MarkingPapers(QWidget *parent = 0,QString filePath=NULL);
    ~MarkingPapers();
    void toCreatePaperLayout();
    void drowHeader(QDomElement root);
    void drowQuestions(QDomElement root);
    void saveAnswers();


    QString paperOpenPath;


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
    
private slots:
    void on_pBPrivious_clicked();

    void on_pBNext_clicked();

private:
    Ui::MarkingPapers *ui;
};

#endif // MARKINGPAPERS_H
