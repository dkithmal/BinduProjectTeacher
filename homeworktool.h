#ifndef HOMEWORKTOOL_H
#define HOMEWORKTOOL_H

#include <QtWidgets>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "newnote.h"
#include "newhomework.h"
#include "openhomework.h";
#include "opennote.h"

namespace Ui {
class HomeWorkTool;
}

class HomeWorkTool : public QDialog
{
    Q_OBJECT
    
public:
    explicit HomeWorkTool(QDialog *parent = 0);
    ~HomeWorkTool();
    NewHomeWork *newHomeWork;
    NewNote *newNote;
    OpenHomeWork *openHomeWork;
    OpenNote  *openNote;
    
private slots:
    void on_pBNewHomeWork_clicked();

    void on_pBOpenExistingHw_clicked();

private:
    Ui::HomeWorkTool *ui;
};

#endif // HOMEWORKTOOL_H
