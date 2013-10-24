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
    QString paperCrationPath;

    int qustionNo;
    int mcqNo;
    int essayNO;
    
private slots:
    void on_cBNoOfChoises_currentIndexChanged(int index);

    void on_pBAddMcq_clicked();

    void on_pBAddEssayQuestion_clicked();

private:
    Ui::NewMixPaper *ui;
};

#endif // NEWMIXPAPER_H
