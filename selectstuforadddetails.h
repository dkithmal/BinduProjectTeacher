#ifndef SELECTSTUFORADDDETAILS_H
#define SELECTSTUFORADDDETAILS_H


#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "addstudentinfromation.h"
namespace Ui {
class SelectStuForAddDetails;
}

class SelectStuForAddDetails : public QDialog
{
    Q_OBJECT
    
public:
    explicit SelectStuForAddDetails(QWidget *parent = 0);
    ~SelectStuForAddDetails();
    void setClassList();


    QString filepath;
    QString basicPath;
    AddStudentInfromation *addStudentInfromation;
    
private slots:
    void on_tWSelectClass_clicked(const QModelIndex &index);

    void on_pBAddDetails_clicked();

private:
    Ui::SelectStuForAddDetails *ui;
};

#endif // SELECTSTUFORADDDETAILS_H
