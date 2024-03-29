#ifndef NEWESSAYPAPER_H
#define NEWESSAYPAPER_H

#include <QMainWindow>
#include <QDialog>
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
class NewEssayPaper;
}

class NewEssayPaper : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewEssayPaper(QDialog *parent = 0,QString filePath=NULL);
    ~NewEssayPaper();
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
     QGridLayout  *questionLayout[5];
     QLabel *qusestionLables[50];
     QTextEdit *qusestionEdit[50];
     QTextEdit *essayAnswers[25];
     QLineEdit *essayMarks[25];
    
private slots:
     void on_pBAddEssayQuestion_clicked();

     void on_tWPaperCreation_currentChanged(int index);

     void on_pBPrivious_clicked();

     void on_pBNext_clicked();

     void on_pBEPrivious_clicked();

     void on_pBENext_clicked();

     void on_pBCClose_clicked();

     void on_pBEClose_clicked();

private:
    Ui::NewEssayPaper *ui;
};

#endif // NEWESSAYPAPER_H
