#include "studentinformation.h"
#include "ui_studentinformation.h"

StudentInformation::StudentInformation(QWidget *parent,QString studentName,QString grade,QString className,QString studentInfoPath) :
    QDialog(parent),
    ui(new Ui::StudentInformation)
{
    ui->setupUi(this);
    ui->lStudentName->setText(studentName);
    this->studentName=studentName;
    this->grade=grade;
    this->className=className;
    this->studentInfoFilePath=studentInfoPath;
    ui->tabWidget->setCurrentIndex(0);

    setStudentDetails();
}

StudentInformation::~StudentInformation()
{
    delete ui;
}

void StudentInformation::setStudentDetails()
{
    QFile newStudentProfile(studentInfoFilePath);

    if(newStudentProfile.size()==0)
    {

    }
    else
    {

        //QFile newStudentProfile(studentInfoFilePath);
        if(!newStudentProfile.open(QFile::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QDomDocument document;

            document.setContent(&newStudentProfile);
            QDomElement root= document.firstChildElement();




            QDomNode stdentFullName=root.elementsByTagName("SFullName").at(0);
            ui->lStudentFullName->setText(stdentFullName.firstChild().nodeValue());
            QDomNode studentDateOfBirth=root.elementsByTagName("SDateOfBirth").at(0);
             ui->lStudentDateOfBirth->setText(studentDateOfBirth.firstChild().nodeValue());
            QDomNode studentFatherFullName=root.elementsByTagName("SFatherName").at(0);
             ui->lStudentFatherFullName->setText(studentFatherFullName.firstChild().nodeValue());
            QDomNode studentFatherOccupation=root.elementsByTagName("SFatherOccupation").at(0);
             ui->lStudentFatherOccupation->setText(studentFatherOccupation.firstChild().nodeValue());
            QDomNode studentFatherTelNo=root.elementsByTagName("SFatherTelNo").at(0);
             ui->lStudentFatherTelNo->setText(studentFatherTelNo.firstChild().nodeValue());
            QDomNode studentMotherFullName=root.elementsByTagName("SMotherName").at(0);
             ui->lStudentMotherFullName->setText(studentMotherFullName.firstChild().nodeValue());
            QDomNode studentMotherOccupation=root.elementsByTagName("SMotherOccupation").at(0);
             ui->lStudentMotherOccupation->setText(studentMotherOccupation.firstChild().nodeValue());
            QDomNode studentMotherTelNo=root.elementsByTagName("SMotherTelNo").at(0);
             ui->lStudentMotherTelNo->setText(studentMotherTelNo.firstChild().nodeValue());
            QDomNode studentHomeAddress=root.elementsByTagName("SHomeAddress").at(0);
             ui->lStudentHomeAddress->setText(studentHomeAddress.firstChild().nodeValue());
            QDomNode studentHomeTelNo=root.elementsByTagName("SHomeTelNo").at(0);
             ui->lStudentHomeTelNo->setText(studentHomeTelNo.firstChild().nodeValue());
            QDomNode studentDiscription=root.elementsByTagName("SDiscription").at(0);
             ui->textEdit->setText(studentDiscription.firstChild().nodeValue());
        }
        }

}
