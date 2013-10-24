#include "subjectmanage.h"
#include "ui_subjectmanage.h"

SubjectManage::SubjectManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectManage)
{
    ui->setupUi(this);
     filepath ="D:/dk work/Motarola/Bindu/Administration/GradesAndClassManage/GradesAndClassManage.xml";
     newGradeFolderPath="D:/dk work/Motarola/Bindu/HomeWorkTool/HomeWork/Papers/";
     ui->tWSubjectManage->setCurrentIndex(0);
    setDefaultCB();
}

SubjectManage::~SubjectManage()
{
    delete ui;
}

void SubjectManage::setDefaultCB()
{
    QFile openConfigFile(filepath);
    if(!openConfigFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&openConfigFile);
        QDomElement root= document.firstChildElement();

        QDomNodeList grades = root.elementsByTagName("Grade");

        ui->cBSelectGradeAdd->clear();
        for(int i=0;i<grades.count();i++)
        {
            QDomNode itemNode = grades.at(i);

            if(itemNode.isElement())
            {

                //gradeList.append(itemNode.toElement().attribute("GradeName"));
                ui->cBSelectGradeAdd->addItem(itemNode.toElement().attribute("GradeName"));


        }


    }


   }


}

void SubjectManage::on_pBAddSubject_clicked()
{
    QFile newConfigFile(filepath);
    if(!newConfigFile.open(QFile::ReadWrite| QIODevice::Text))
    {

    }
    else
    {

        QDomDocument document;
        QDomElement root;

        document.setContent(&newConfigFile);
        root= document.firstChildElement();

        QDomNodeList grades = root.elementsByTagName("Grade");

        for(int i=0;i<grades.count();i++)
        {
            QDomNode itemNode = grades.at(i);

            if(itemNode.isElement())
            {



                if(!itemNode.toElement().attribute("GradeName").compare(ui->cBSelectGradeAdd->currentText()))
                {


                    QDomElement subject= document.createElement("Subject");
                    subject.setAttribute("SubjectName",ui->lESubjectName->text());
                    itemNode.appendChild(subject);
                    root.appendChild(itemNode);
                    break;

                }

                }



        }

        newConfigFile.close();

        if(!newConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
        {

        }
        else
        {
            QTextStream stream(&newConfigFile);
            stream <<document.toString();
            newConfigFile.close();

            //creating new dirctry for subjet
            QString newClassPath=newGradeFolderPath;
            newClassPath.append(ui->cBSelectGradeAdd->currentText());
            newClassPath.append("/");
            newClassPath.append(ui->lESubjectName->text());
            QDir().mkdir(newClassPath);


            QMessageBox::information(this,"Success","New Subject Created");
            ui->lESubjectName->clear();


        }

    }

}
