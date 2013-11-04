#ifndef ADDSTUDENTINFROMATION_H
#define ADDSTUDENTINFROMATION_H


#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class AddStudentInfromation;
}

class AddStudentInfromation : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddStudentInfromation(QWidget *parent = 0,QString studentName=NULL,QString sInfoFilePath=NULL);
    ~AddStudentInfromation();
    void setStudentDetails();
    QString studentName;
    QString studentInfoFilePath;
    
private slots:
    void on_pBSubmit_clicked();

private:
    Ui::AddStudentInfromation *ui;
};

#endif // ADDSTUDENTINFROMATION_H
