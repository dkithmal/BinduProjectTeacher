#ifndef NEWHOMEWORK_H
#define NEWHOMEWORK_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "newmixpaper.h"

namespace Ui {
class NewHomeWork;
}

class NewHomeWork : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewHomeWork(QWidget *parent = 0);
    ~NewHomeWork();
    void setSubjetToTree();
    QString filepath;
    NewMixPaper *newMixPaper;
    QString qPaperSavefilepath;
    
private slots:
    void on_pBCreatePaper_clicked();

private:
    Ui::NewHomeWork *ui;
};

#endif // NEWHOMEWORK_H
