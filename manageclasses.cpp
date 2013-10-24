#include "manageclasses.h"
#include "ui_manageclasses.h"

ManageClasses::ManageClasses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageClasses)
{
    ui->setupUi(this);
    ui->tWManage->setCurrentIndex(0);
    filepath ="D:/dk work/Motarola/Bindu/Administration/GradesAndClassManage/GradesAndClassManage.xml";
}

ManageClasses::~ManageClasses()
{
    delete ui;
}

void ManageClasses::on_pBAddGrade_clicked()
{

    QFile newConfigFile(filepath);
    if(!newConfigFile.open(QFile::ReadWrite| QIODevice::Text))
    {

    }
    else
    {
        QDomDocument document;
        QDomElement root;


        if(newConfigFile.size()==0)
        {
            root = document.createElement("GradesAndClasses");
            QDomElement grade= document.createElement("Grade");
            grade.setAttribute("GradeName",ui->lEGradeName->text());
            root.appendChild(grade);


        }
        else
        {
            document.setContent(&newConfigFile);
            root= document.firstChildElement();


            QDomElement grade= document.createElement("Grade");
            grade.setAttribute("GradeName",ui->lEGradeName->text());
            root.appendChild(grade);





        }



        document.appendChild(root);
        newConfigFile.close();

        if(!newConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
        {

        }
        else
        {
            QTextStream stream(&newConfigFile);
            stream <<document.toString();
            newConfigFile.close();

            QMessageBox::information(this,"Success","New Grade Created");
            ui->lEGradeName->clear();

        }



    }


}

void ManageClasses::on_tWManage_currentChanged(int index)
{
    if(index==1)
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

            ui->cBSelectGrade_2->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {

                    //gradeList.append(itemNode.toElement().attribute("GradeName"));
                    ui->cBSelectGrade_2->addItem(itemNode.toElement().attribute("GradeName"));


            }


        }


       }
    }




    if(index==2)
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

            ui->cBSelectGrade_3->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {

                    //gradeList.append(itemNode.toElement().attribute("GradeName"));
                    ui->cBSelectGrade_3->addItem(itemNode.toElement().attribute("GradeName"));

                    if(i==0)
                    {
                        QDomNodeList classList= itemNode.childNodes();

                        ui->cBSelectClass->clear();
                        for(int j=0;j<classList.count();j++)
                        {
                            QDomNode itemNodeClass = classList.at(j);
                             ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));

                        }

                    }


                }




           }


       }
    }

}


void ManageClasses::on_pBCreateClass_clicked()
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



                if(!itemNode.toElement().attribute("GradeName").compare(ui->cBSelectGrade_2->currentText()))
                {
                    qDebug() <<itemNode.toElement().attribute("GradeName");
                    qDebug() <<ui->cBSelectGrade_2->currentText();

                    QDomElement sClass= document.createElement("Class");
                    sClass.setAttribute("ClassName",ui->lEClassName->text());


                    QDomElement students=document.createElement("students");
                    students.appendChild(document.createTextNode(ui->tEStudents->document()->toPlainText()));
                    sClass.appendChild(students);

                    itemNode.appendChild(sClass);
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

            QMessageBox::information(this,"Success","New Class Created");
            ui->lEGradeName->clear();


            ui->lEClassName->clear();
            ui->tEStudents->clear();

        }

    }





}

void ManageClasses::on_cBSelectGrade_3_currentIndexChanged(const QString &arg1)
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

            ui->cBSelectGrade_2->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {
                    if(ui->cBSelectGrade_3->currentText()==itemNode.toElement().attribute("GradeName"))
                    {
                        QDomNodeList classList= itemNode.childNodes();

                        ui->cBSelectClass->clear();
                        for(int j=0;j<classList.count();j++)
                        {
                            QDomNode itemNodeClass = classList.at(j);
                             ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));

                        }

                    }

//                    //gradeList.append(itemNode.toElement().attribute("GradeName"));
//                    ui->cBSelectGrade_3->addItem(itemNode.toElement().attribute("GradeName"));

//                    if(i==0)
//                    {


//                    }


                }




           }


       }


}

void ManageClasses::on_pBAddStudent_clicked()
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


        for(int i=0;i<grades.count();i++)
        {
            QDomNode itemNode = grades.at(i);

            if(itemNode.isElement())
            {
                if(ui->cBSelectGrade_3->currentText()==itemNode.toElement().attribute("GradeName"))
                {
                    QDomNodeList classList= itemNode.childNodes();


                    for(int j=0;j<classList.count();j++)
                    {
                        QDomNode itemNodeClass = classList.at(j);
                        // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                        if(ui->cBSelectClass->currentText()==itemNodeClass.toElement().attribute("ClassName"))
                        {
                            QDomElement students=itemNodeClass.toElement();
                            QDomNode studentNames=students.elementsByTagName("students").at(0);
                           // qDebug()<<studentNames.firstChild().nodeValue();
                            QString newStudents=studentNames.firstChild().nodeValue();
                            newStudents.append(",");
                            newStudents.append(ui->lEStudentName->text());
                            QDomElement newstudents = document.createElement(QString("students"));
                            newstudents.appendChild(document.createTextNode(newStudents));
                            students.replaceChild(newstudents,studentNames);


                            openConfigFile.close();

                            if(!openConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
                            {

                            }
                            else
                            {
                                QTextStream stream(&openConfigFile);
                                stream <<document.toString();
                                openConfigFile.close();

                                QMessageBox::information(this,"Success","New Student Added");
                                ui->lEStudentName->clear();


                            }





                        }

                    }

                }


            }

        }
     }


}
