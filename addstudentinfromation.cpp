#include "addstudentinfromation.h"
#include "ui_addstudentinfromation.h"

AddStudentInfromation::AddStudentInfromation(QWidget *parent,QString studentName,QString sInfoFilePath) :
    QDialog(parent),
    ui(new Ui::AddStudentInfromation)
{

    this->studentName=studentName;
    this->studentInfoFilePath=sInfoFilePath;
    ui->setupUi(this);

    ui->lEStudentName->setText(studentName);

    setStudentDetails();


}

AddStudentInfromation::~AddStudentInfromation()
{
    delete ui;
}

void AddStudentInfromation::setStudentDetails()
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
            ui->lEStudentFullName->setText(stdentFullName.firstChild().nodeValue());
            QDomNode studentDateOfBirth=root.elementsByTagName("SDateOfBirth").at(0);
             ui->lEStudentBDate->setText(studentDateOfBirth.firstChild().nodeValue());
            QDomNode studentFatherFullName=root.elementsByTagName("SFatherName").at(0);
             ui->lEStudentFatherName->setText(studentFatherFullName.firstChild().nodeValue());
            QDomNode studentFatherOccupation=root.elementsByTagName("SFatherOccupation").at(0);
             ui->lEStudentFOcupation->setText(studentFatherOccupation.firstChild().nodeValue());
            QDomNode studentFatherTelNo=root.elementsByTagName("SFatherTelNo").at(0);
             ui->lEStudentFTelNo->setText(studentFatherTelNo.firstChild().nodeValue());
            QDomNode studentMotherFullName=root.elementsByTagName("SMotherName").at(0);
             ui->lEMotherFullName->setText(studentMotherFullName.firstChild().nodeValue());
            QDomNode studentMotherOccupation=root.elementsByTagName("SMotherOccupation").at(0);
             ui->lEMotherOccupation->setText(studentMotherOccupation.firstChild().nodeValue());
            QDomNode studentMotherTelNo=root.elementsByTagName("SMotherTelNo").at(0);
             ui->lEMotherTelNo->setText(studentMotherTelNo.firstChild().nodeValue());
            QDomNode studentHomeAddress=root.elementsByTagName("SHomeAddress").at(0);
             ui->lEStudentHomeAddress->setText(studentHomeAddress.firstChild().nodeValue());
            QDomNode studentHomeTelNo=root.elementsByTagName("SHomeTelNo").at(0);
             ui->lEStudentHomeTelNo->setText(studentHomeTelNo.firstChild().nodeValue());
            QDomNode studentDiscription=root.elementsByTagName("SDiscription").at(0);
             ui->TEStudentDiscription->setText(studentDiscription.firstChild().nodeValue());
        }
        }

}

void AddStudentInfromation::on_pBSubmit_clicked()
{
    QFile newStudentProfile(studentInfoFilePath);

    if(newStudentProfile.size()==0)
    {
        if(!newStudentProfile.open(QFile::Append| QFile::Text))
        {

        }
        else
        {
            QDomDocument document;


            QDomElement root = document.createElement("StudentInfo");


            QDomElement studentName= document.createElement("StudentName");
            studentName.appendChild(document.createTextNode(ui->lEStudentName->text()));

            QDomElement stdentFullName=document.createElement("SFullName");
            stdentFullName.appendChild(document.createTextNode(ui->lEStudentFullName->text()));

            QDomElement studentDateOfBirth=document.createElement("SDateOfBirth");
            studentDateOfBirth.appendChild(document.createTextNode(ui->lEStudentBDate->text()));

            QDomElement studentFatherFullName=document.createElement("SFatherName");
            studentFatherFullName.appendChild(document.createTextNode(ui->lEStudentFatherName->text()));


            QDomElement studentFatherOccupation=document.createElement("SFatherOccupation");
            studentFatherOccupation.appendChild(document.createTextNode(ui->lEStudentFOcupation->text()));


            QDomElement studentFatherTelNo=document.createElement("SFatherTelNo");
            studentFatherTelNo.appendChild(document.createTextNode(ui->lEStudentFTelNo->text()));


            QDomElement studentMotherFullName=document.createElement("SMotherName");
            studentMotherFullName.appendChild(document.createTextNode(ui->lEMotherFullName->text()));

            QDomElement studentMotherOccupation=document.createElement("SMotherOccupation");
            studentMotherOccupation.appendChild(document.createTextNode(ui->lEMotherOccupation->text()));


            QDomElement studentMotherTelNo=document.createElement("SMotherTelNo");
            studentMotherTelNo.appendChild(document.createTextNode(ui->lEMotherTelNo->text()));

            QDomElement studentHomeAddress=document.createElement("SHomeAddress");
            studentHomeAddress.appendChild(document.createTextNode(ui->lEStudentHomeAddress->text()));

            QDomElement studentHomeTelNo=document.createElement("SHomeTelNo");
            studentHomeTelNo.appendChild(document.createTextNode(ui->lEStudentHomeTelNo->text()));

            QDomElement studentDiscription=document.createElement("SDiscription");
            studentDiscription.appendChild(document.createTextNode(ui->TEStudentDiscription->toPlainText()));




            root.appendChild(studentName);
            root.appendChild(stdentFullName);
            root.appendChild(studentDateOfBirth);
            root.appendChild(studentFatherFullName);
            root.appendChild(studentFatherOccupation);
            root.appendChild(studentFatherTelNo);
            root.appendChild(studentMotherFullName);
            root.appendChild(studentMotherOccupation);
            root.appendChild(studentMotherTelNo);
            root.appendChild(studentHomeAddress);
            root.appendChild(studentHomeTelNo);
            root.appendChild(studentDiscription);


            document.appendChild(root);
            QTextStream stream(&newStudentProfile);
            stream <<document.toString();
            newStudentProfile.close();


            QMessageBox::information(this,"Success","StudentProfile Successfully created");
            this->close();


        }

    }
    //update student account
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
            QDomNode studentDateOfBirth=root.elementsByTagName("SDateOfBirth").at(0);
            QDomNode studentFatherFullName=root.elementsByTagName("SFatherName").at(0);
            QDomNode studentFatherOccupation=root.elementsByTagName("SFatherOccupation").at(0);
            QDomNode studentFatherTelNo=root.elementsByTagName("SFatherTelNo").at(0);
            QDomNode studentMotherFullName=root.elementsByTagName("SMotherName").at(0);
            QDomNode studentMotherOccupation=root.elementsByTagName("SMotherOccupation").at(0);
            QDomNode studentMotherTelNo=root.elementsByTagName("SMotherTelNo").at(0);
            QDomNode studentHomeAddress=root.elementsByTagName("SHomeAddress").at(0);
            QDomNode studentHomeTelNo=root.elementsByTagName("SHomeTelNo").at(0);
            QDomNode studentDiscription=root.elementsByTagName("SDiscription").at(0);



            QDomElement newstdentFullName=document.createElement("SFullName");
            newstdentFullName.appendChild(document.createTextNode(ui->lEStudentFullName->text()));

            QDomElement newstudentDateOfBirth=document.createElement("SDateOfBirth");
            newstudentDateOfBirth.appendChild(document.createTextNode(ui->lEStudentBDate->text()));

            QDomElement newstudentFatherFullName=document.createElement("SFatherName");
            newstudentFatherFullName.appendChild(document.createTextNode(ui->lEStudentFatherName->text()));


            QDomElement newstudentFatherOccupation=document.createElement("SFatherOccupation");
            newstudentFatherOccupation.appendChild(document.createTextNode(ui->lEStudentFOcupation->text()));


            QDomElement newstudentFatherTelNo=document.createElement("SFatherTelNo");
            newstudentFatherTelNo.appendChild(document.createTextNode(ui->lEStudentFTelNo->text()));


            QDomElement newstudentMotherFullName=document.createElement("SMotherName");
            newstudentMotherFullName.appendChild(document.createTextNode(ui->lEMotherFullName->text()));

            QDomElement newstudentMotherOccupation=document.createElement("SMotherOccupation");
            newstudentMotherOccupation.appendChild(document.createTextNode(ui->lEMotherOccupation->text()));


            QDomElement newstudentMotherTelNo=document.createElement("SMotherTelNo");
            newstudentMotherTelNo.appendChild(document.createTextNode(ui->lEMotherTelNo->text()));

            QDomElement newstudentHomeAddress=document.createElement("SHomeAddress");
            newstudentHomeAddress.appendChild(document.createTextNode(ui->lEStudentHomeAddress->text()));

            QDomElement newstudentHomeTelNo=document.createElement("SHomeTelNo");
            newstudentHomeTelNo.appendChild(document.createTextNode(ui->lEStudentHomeTelNo->text()));

            QDomElement newstudentDiscription=document.createElement("SDiscription");
            newstudentDiscription.appendChild(document.createTextNode(ui->TEStudentDiscription->toPlainText()));



            root.replaceChild(newstdentFullName,stdentFullName);
            root.replaceChild(newstudentDateOfBirth,studentDateOfBirth);
            root.replaceChild(newstudentFatherFullName,studentFatherFullName);
            root.replaceChild(newstudentFatherOccupation,studentFatherOccupation);
            root.replaceChild(newstudentFatherTelNo,studentFatherTelNo);
            root.replaceChild(newstudentMotherFullName,studentMotherFullName);
            root.replaceChild(newstudentMotherOccupation,studentMotherOccupation);
            root.replaceChild(newstudentMotherTelNo,studentMotherTelNo);
            root.replaceChild(newstudentHomeAddress,studentHomeAddress);
            root.replaceChild(newstudentHomeTelNo,studentHomeTelNo);
            root.replaceChild(newstudentDiscription,studentDiscription);




           //document.appendChild(root);
            newStudentProfile.close();

            if(!newStudentProfile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
            {

            }
            else
            {

                QTextStream stream(&newStudentProfile);
                stream <<document.toString();
                newStudentProfile.close();

                QMessageBox::information(this,"Success","StudentProfile Successfully modified");
                this->close();
            }






    }
    }


}
