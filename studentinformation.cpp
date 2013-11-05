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
    filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
    basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
    ui->tabWidget->setCurrentIndex(0);

    //ui->tWMarksSummery->setFrameShape(QFrame::NoFrame);

    setStudentDetails();
    setStudentMarks();
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

void StudentInformation::setStudentMarks()
{
    QString createAnswerPaperPathForClass=basicPath;

    createAnswerPaperPathForClass.append("Answers/");
    createAnswerPaperPathForClass.append(grade);
    createAnswerPaperPathForClass.append("/");
    createAnswerPaperPathForClass.append(className);
    createAnswerPaperPathForClass.append("/");

    //qDebug()<<createAnswerPaperPathForClass<<"number of diretrys";
    QStringList all_dirs;
    all_dirs << createAnswerPaperPathForClass;
    QDirIterator directories(createAnswerPaperPathForClass, QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

    while(directories.hasNext()){
    directories.next();
   // qDebug()<<directories.filePath();

    QFile newPaperXml(directories.filePath().append("/paper.xml"));

    if(newPaperXml.exists())
    {
        
        QDomDocument document;
        QDomElement root;

        document.setContent(&newPaperXml);
        root= document.firstChildElement();

        QDomNodeList headernode = root.elementsByTagName("Header");

        int desition=0;
        if(!subjectList.isEmpty())
        foreach (QString subjectitem, subjectList)
        {

            if(subjectitem==headernode.at(0).toElement().attribute("subject"))
                desition=1;


        }

        if(desition==0)
        {
			ui->tWMarksSummery->insertRow(ui->tWMarksSummery->rowCount());
            ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,0,new QTableWidgetItem(headernode.at(0).toElement().attribute("subject")));
            subjectList.append(headernode.at(0).toElement().attribute("subject"));

        }

            QDomNodeList studentList = root.elementsByTagName("student");


            int x=0;
            for(int i=0;i<studentList.count();i++)
            {


                QDomNode itemNode = studentList.at(i);
                if(itemNode.toElement().attribute("StudentName")==studentName)
                {
                     ui->tWMarksSummery->insertRow(ui->tWMarksSummery->rowCount());
                     ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,1,new QTableWidgetItem(headernode.at(0).toElement().attribute("PaperName")));
                     ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,2,new QTableWidgetItem(itemNode.toElement().attribute("Marks")));
                     ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,3,new QTableWidgetItem(itemNode.toElement().attribute("MarkState")));
                     ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,4,new QTableWidgetItem(headernode.at(0).toElement().attribute("type")));
                     x=1;

                }

            }
            if(x==0)
            {
                ui->tWMarksSummery->insertRow(ui->tWMarksSummery->rowCount());
                ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,1,new QTableWidgetItem(headernode.at(0).toElement().attribute("PaperName")));
                ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,2,new QTableWidgetItem("-"));
                ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,3,new QTableWidgetItem("NotDoneByStudent"));
                ui->tWMarksSummery->setItem(ui->tWMarksSummery->rowCount()-1,4,new QTableWidgetItem(headernode.at(0).toElement().attribute("type")));

            }


   // all_dirs << directories.filePath();
    }





}
}















