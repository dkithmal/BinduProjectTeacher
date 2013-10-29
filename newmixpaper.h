#ifndef NEWMIXPAPER_H
#define NEWMIXPAPER_H

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
class NewMixPaper;
}

class NewMixPaper : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewMixPaper(QWidget *parent = 0,QString filePath=NULL);
    ~NewMixPaper();
    void drowHeader(QDomElement root);
    void drowQuestions(QDomElement root);
    void toCreatePaperLayout();
    QString paperCrationPath;

    int qustionNo;
    int mcqNo;
    int essayNO;

     QVBoxLayout *paperHeaderLayout;
     QVBoxLayout *paperQuestionsLayout;

     QRadioButton *rBMcqAnswers[25][4];
     QFrame *mcqFrames[25];
     QVBoxLayout  *mcqQuestionLayout[5];
     QLabel *qusestionLables[50];
     QLineEdit *essayAnswers[25];
     QVBoxLayout  *essayQuestionLayout[5];
    
private slots:
    void on_cBNoOfChoises_currentIndexChanged(int index);

    void on_pBAddMcq_clicked();

    void on_pBAddEssayQuestion_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tWPaperCreation_currentChanged(int index);

private:
    Ui::NewMixPaper *ui;
};

#endif // NEWMIXPAPER_H
