#ifndef OPENHOMEWORK_H
#define OPENHOMEWORK_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "newmcqpaper.h"
#include "newmixpaper.h"
#include "newessaypaper.h"

namespace Ui {
class OpenHomeWork;
}

class OpenHomeWork : public QDialog
{
    Q_OBJECT
    
public:
    explicit OpenHomeWork(QDialog *parent = 0);
    ~OpenHomeWork();
    QString filepath;
    QString basicPath;
    void setSubjetToTree();
    NewMixPaper *newMixPaper;
    NewMcqPaper *mewMcqPaper;
    NewEssayPaper *newEssayPaper;
    
private slots:
    void on_tWSelectSubject_clicked(const QModelIndex &index);

    void on_pBOpen_clicked();

    void on_pBDeleteHomeWork_clicked();

private:
    Ui::OpenHomeWork *ui;
};

#endif // OPENHOMEWORK_H
