#ifndef PAPERSUMMARY_H
#define PAPERSUMMARY_H

#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "markingpapers.h"

namespace Ui {
class Papersummary;
}

class Papersummary : public QDialog
{
    Q_OBJECT
    
public:
    explicit Papersummary(QWidget *parent = 0,QString filepath=NULL);
    ~Papersummary();
    QString paperFilepath;
    void createPaperSummary();
    MarkingPapers *markingPapers;
    
private slots:
    void on_tWStudentPaperSummery_doubleClicked(const QModelIndex &index);

private:
    Ui::Papersummary *ui;
};

#endif // PAPERSUMMARY_H
