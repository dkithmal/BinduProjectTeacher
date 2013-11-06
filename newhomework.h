#ifndef NEWHOMEWORK_H
#define NEWHOMEWORK_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "newmixpaper.h"
#include "newmcqpaper.h"
#include "newessaypaper.h"

namespace Ui {
class NewHomeWork;
}

class NewHomeWork : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewHomeWork(QDialog *parent = 0);
    ~NewHomeWork();
    void setSubjetToTree();
    QString filepath;
    QString basicPath;
    NewMixPaper *newMixPaper;
    NewMcqPaper *newMcqPaper;
    NewEssayPaper *newEssayPaper;

    
private slots:
    void on_pBCreatePaper_clicked();

private:
    Ui::NewHomeWork *ui;
};

#endif // NEWHOMEWORK_H
