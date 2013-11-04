#ifndef STUDENTINFORMATION_H
#define STUDENTINFORMATION_H

#include <QDialog>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
namespace Ui {
class StudentInformation;
}

class StudentInformation : public QDialog
{
    Q_OBJECT
    
public:
    explicit StudentInformation(QWidget *parent = 0,QString studentName=NULL,QString grade=NULL,QString className=NULL,QString studentInfoPath=NULL);
    ~StudentInformation();
    void setStudentDetails();
    QString studentName;
    QString grade;
    QString className;
    QString studentInfoFilePath;
    
private:
    Ui::StudentInformation *ui;
};

#endif // STUDENTINFORMATION_H
