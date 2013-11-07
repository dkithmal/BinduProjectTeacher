#include "uploadfile.h"
#include "ui_uploadfile.h"

UploadFile::UploadFile(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::UploadFile)
{
    ui->setupUi(this);
        filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
        basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
        //setFileList();
        setClassList();
}

UploadFile::~UploadFile()
{
    delete ui;
}

void UploadFile::setFileList()
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
                QTreeWidgetItem *grade= new QTreeWidgetItem(ui->tWSelectHomeWork);
                grade->setText(0,itemNode.toElement().attribute("GradeName"));
                grade->setIcon(0,QIcon(":/binduTeacher/new/imgs/grade.png"));


                QDomNodeList subjecList= itemNode.toElement().elementsByTagName("Subject");

                    for(int j=0;j<subjecList.count();j++)
                    {

                        QDomNode itemNodeSubject = subjecList.at(j);
                        // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                         QTreeWidgetItem *subjectItem= new QTreeWidgetItem(grade);
                         subjectItem->setText(0,itemNodeSubject.toElement().attribute("SubjectName"));
                         subjectItem->setIcon(0,QIcon(":/binduTeacher/new/imgs/subject.png"));

                         if(itemNodeSubject.isElement())
                         {
                             QDomNodeList homeWorkList= itemNodeSubject.toElement().elementsByTagName("HomeWork");
                             QDomNodeList noteList= itemNodeSubject.toElement().elementsByTagName("Note");


                             for(int k=0;k<homeWorkList.count();k++)
                             {
                                 QDomNode itemNodehomeWork = homeWorkList.at(k);
                                 QTreeWidgetItem *homeWorkItem= new QTreeWidgetItem(subjectItem);
                                 homeWorkItem->setText(0,itemNodehomeWork.toElement().attribute("HomeWorkName"));


                             }
                             for(int l=0;l<noteList.count();l++)
                             {
                                 QDomNode itemNodeNote = noteList.at(l);
                                 QTreeWidgetItem *noteItem= new QTreeWidgetItem(subjectItem);
                                 noteItem->setText(0,itemNodeNote.toElement().attribute("NoteName"));


                             }


                         }

                    }




              ui->tWSelectHomeWork->addTopLevelItem(grade);


            }




       }


   }


}

void UploadFile::setClassList()
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
                QTreeWidgetItem *grade= new QTreeWidgetItem(ui->tWSelectClass);
                grade->setText(0,itemNode.toElement().attribute("GradeName"));
                grade->setIcon(0,QIcon(":/binduTeacher/new/imgs/grade.png"));


                QDomNodeList classeList= itemNode.toElement().elementsByTagName("Class");

                    for(int j=0;j<classeList.count();j++)
                    {
                        QDomNode itemNodeClass = classeList.at(j);
                        QTreeWidgetItem *classItem= new QTreeWidgetItem(grade);
                        classItem->setText(0,itemNodeClass.toElement().attribute("ClassName"));
                        classItem->setIcon(0,QIcon(":/binduTeacher/new/imgs/class.png"));



                    }




              ui->tWSelectClass->addTopLevelItem(grade);


            }




       }


   }

}

void UploadFile::on_rBSelectHomeWork_clicked()
{
    ui->gBSelectOtherFile->setEnabled(false);
    ui->tWSelectHomeWork->setEnabled(true);

}

void UploadFile::on_rBSelectOtherFile_clicked()
{
    ui->gBSelectOtherFile->setEnabled(true);
    ui->tWSelectHomeWork->setEnabled(false);

}

void UploadFile::on_pushButton_3_clicked()
{

    QString newFileName = QFileDialog::getOpenFileName(this, tr("Open a Movie"),"D:/dk work/Motarola");
    Otherfilepath=newFileName;
    //fileName.lastIndexOf("/");
    ui->lEFileName->setText(newFileName.mid(newFileName.lastIndexOf("/")+1,newFileName.length()));
}



void UploadFile::on_tWSelectClass_clicked(const QModelIndex &index)
{
    int itemicon=0;
    ui->cBSelectStudent->clear();
    ui->cBSelectStudent->addItem("All");
    ui->cBSelectStudent->setItemIcon(itemicon,QIcon(":/binduTeacher/new/imgs/student.jpg"));
    itemicon++;

    if(ui->tWSelectClass->currentIndex().parent().isValid())
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
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectClass->currentItem()->parent()->text(0))
                    {
                        QDomNodeList classeList= itemNode.toElement().elementsByTagName("Class");

                            for(int j=0;j<classeList.count();j++)
                            {
                                QDomNode itemNodeClass = classeList.at(j);
                                if(itemNodeClass.toElement().attribute("ClassName")==ui->tWSelectClass->currentItem()->text(0))
                                {
                                    QDomNodeList studentList=itemNodeClass.toElement().elementsByTagName("students");
                                    QDomNode students=studentList.at(0);
                                    QString studentNameList=students.firstChild().nodeValue();
                                   // qDebug()<<studentNameList<<"student NameList";
                                    QStringList studentNameSplitedList=studentNameList.split(",");

                                    foreach (QString studentName, studentNameSplitedList)
                                    {
                                        ui->cBSelectStudent->addItem(studentName);
                                        ui->cBSelectStudent->setItemIcon(itemicon,QIcon(":/binduTeacher/new/imgs/student.jpg"));
                                       // ui->cBSelectStudent->addItem(new (QIcon(":/binduTeacher/new/F:/download/student.jpg"), studentName));


                                        itemicon++;
                                    }



                                    break;

                                }




                            }
                            break;

                    }


                  //ui->tWSelectClass->addTopLevelItem(grade);


                }




           }


       }

        //set content of subjects and notes and homeworks
        QFile openConfigFile2(filepath);
        if(!openConfigFile2.open(QFile::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QDomDocument document;

            document.setContent(&openConfigFile2);
            QDomElement root= document.firstChildElement();

            QDomNodeList grades = root.elementsByTagName("Grade");


            for(int i=0;i<grades.count();i++)
            {

                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectClass->currentItem()->parent()->text(0))
                    {
                        QDomNodeList classeList= itemNode.toElement().elementsByTagName("Class");

                            for(int j=0;j<classeList.count();j++)
                            {
                                QDomNode itemNodeClass = classeList.at(j);
                                if(itemNodeClass.toElement().attribute("ClassName")==ui->tWSelectClass->currentItem()->text(0))
                                {
                                    QDomNodeList subjectList= itemNodeClass.toElement().elementsByTagName("CSubject");

                                    ui->tWSelectHomeWork->clear();
                                    for(int k=0;k<subjectList.size();k++)
                                    {
                                        QTreeWidgetItem *subject= new QTreeWidgetItem(ui->tWSelectHomeWork);
                                        subject->setText(0,subjectList.at(k).toElement().attribute("SubjectName"));
                                        subject->setIcon(0,QIcon(":/binduTeacher/new/imgs/subject.png"));

                                        QDomNodeList subjectListForGetHomeWork=itemNode.toElement().elementsByTagName("Subject");

                                        for(int l=0;l<subjectListForGetHomeWork.size();l++)
                                        {
                                            if(subjectListForGetHomeWork.at(l).toElement().attribute("SubjectName")==subjectList.at(k).toElement().attribute("SubjectName"))
                                            {
                                                QDomNodeList homeWorkList= subjectListForGetHomeWork.at(l).toElement().elementsByTagName("HomeWork");
                                                QDomNodeList noteList= subjectListForGetHomeWork.at(l).toElement().elementsByTagName("Note");


                                                for(int m=0;m<homeWorkList.count();m++)
                                                {
                                                    QDomNode itemNodehomeWork = homeWorkList.at(m);
                                                    QTreeWidgetItem *homeWorkItem= new QTreeWidgetItem(subject);
                                                    homeWorkItem->setText(0,itemNodehomeWork.toElement().attribute("HomeWorkName"));
                                                    homeWorkItem->setIcon(0,QIcon(":/binduTeacher/new/imgs/paper.png"));


                                                }
                                                for(int n=0;n<noteList.count();n++)
                                                {
                                                    QDomNode itemNodeNote = noteList.at(n);
                                                    QTreeWidgetItem *noteItem= new QTreeWidgetItem(subject);
                                                    noteItem->setText(0,itemNodeNote.toElement().attribute("NoteName"));
                                                    noteItem->setIcon(0,QIcon(":/binduTeacher/new/imgs/note.png"));


                                                }

                                            }
                                        }

                                         ui->tWSelectHomeWork->addTopLevelItem(subject);

                                    }


                                }


                            }


                    }
                }
            }
        }


    }




}


void UploadFile::on_pBUpload_clicked()
{
    int x=0;
    if(ui->rBSelectHomeWork->isChecked())
    {
        if(!ui->tWSelectHomeWork->currentIndex().parent().isValid())
        {
            QMessageBox::information(this,"Error","Please Select paper or note");
            x=1;
        }
    }

    if(ui->rBSelectOtherFile->isChecked())
    {
        if(ui->lEFileName->text().isEmpty())
        {
             QMessageBox::information(this,"Error","Please select Other file");
            x=1;
        }
    }

    if(!ui->tWSelectClass->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Please select class");
       x=1;

    }

    if(x==0)
    {
        //creating file path
        QString creatingFullFilePath;
        QString creatingCommand;
        if(ui->rBSelectHomeWork->isChecked())
        {
           creatingFullFilePath=basicPath;
//            creatingFullFilePath.append(ui->tWSelectHomeWork->currentItem()->parent()->parent()->text(0));
//            creatingFullFilePath.append("/");
//            creatingFullFilePath.append(ui->tWSelectHomeWork->currentItem()->parent()->text(0));
//            creatingFullFilePath.append("/");
//            creatingFullFilePath.append(ui->tWSelectHomeWork->currentItem()->text(0));


            creatingCommand="Upload ";
            creatingCommand.append(ui->tWSelectHomeWork->currentItem()->parent()->text(0));

            if(getSelecteHomeWorkType()=="HomeWork")
            {
                creatingFullFilePath.append("HomeWork/");
                creatingFullFilePath.append(ui->tWSelectClass->currentItem()->parent()->text(0));
                creatingFullFilePath.append("/");
                creatingFullFilePath.append(ui->tWSelectHomeWork->currentItem()->parent()->text(0));
                creatingFullFilePath.append("/");
                creatingFullFilePath.append(ui->tWSelectHomeWork->currentItem()->text(0));
                creatingFullFilePath.append(".xml");

                creatingCommand.append("/HomeWork/");
                creatingCommand.append(ui->tWSelectHomeWork->currentItem()->text(0));
                creatingCommand.append(".xml");


            }
            if(getSelecteHomeWorkType()=="Note")
            {
                creatingFullFilePath.append("Note/");
                creatingFullFilePath.append(ui->tWSelectClass->currentItem()->parent()->text(0));
                creatingFullFilePath.append("/");
                creatingFullFilePath.append(ui->tWSelectHomeWork->currentItem()->parent()->text(0));
                creatingFullFilePath.append("/");
                creatingFullFilePath.append(ui->tWSelectHomeWork->currentItem()->text(0));
                creatingFullFilePath.append(".txt");

                creatingCommand.append("/Note/");
                creatingCommand.append(ui->tWSelectHomeWork->currentItem()->text(0));
                creatingCommand.append(".txt");

            }






        }
        else
        {
            creatingFullFilePath=Otherfilepath;
            //creatingCommand=ui->tWSelectHomeWork->currentItem()->parent()->text(0);
			creatingCommand="Upload ";
//			creatingCommand.append(ui->tWSelectHomeWork->currentItem()->parent()->text(0));
            creatingCommand.append("/Other/");
            creatingCommand.append(ui->lEFileName->text());



        }


        //crating studentlist
        QString creatingstudentList;
        if(ui->cBSelectStudent->currentText()=="All")
        {
            creatingstudentList=getSelectedClassStudents();

        }
        else
        {
            creatingstudentList=ui->cBSelectStudent->currentText();

        }


		qDebug()<<creatingCommand<<"creating command";
        uploadManage= new UploadManage(0,creatingCommand,creatingFullFilePath,creatingstudentList);
        uploadManage->show();
        this->close();
       //uploadManage->getuploadReqest(creatingFullFilePath,creatingSubjetAndType,creatingstudentList);


    }

}

QString UploadFile::getSelectedClassStudents()
{
    if(ui->tWSelectClass->currentIndex().parent().isValid())
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
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectClass->currentItem()->parent()->text(0))
                    {
                        QDomNodeList classeList= itemNode.toElement().elementsByTagName("Class");

                            for(int j=0;j<classeList.count();j++)
                            {
                                QDomNode itemNodeClass = classeList.at(j);
                                if(itemNodeClass.toElement().attribute("ClassName")==ui->tWSelectClass->currentItem()->text(0))
                                {
                                    QDomNodeList studentList=itemNodeClass.toElement().elementsByTagName("students");
                                    QDomNode students=studentList.at(0);
                                    QString studentNameList=students.firstChild().nodeValue();

                                        return studentNameList;

                                    break;

                                }




                            }
                            break;

                    }


                  //ui->tWSelectClass->addTopLevelItem(grade);


                }




           }


       }


    }

}

QString UploadFile::getSelecteHomeWorkType()
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

                if(itemNode.toElement().attribute("GradeName")==ui->tWSelectClass->currentItem()->parent()->text(0))
                {
                    QDomNodeList subjecList= itemNode.toElement().elementsByTagName("Subject");

                        for(int j=0;j<subjecList.count();j++)
                        {
                            QDomNode itemNodeSubject = subjecList.at(j);
                            if(itemNodeSubject.toElement().attribute("SubjectName")==ui->tWSelectHomeWork->currentItem()->parent()->text(0))
                            {
                                if(itemNodeSubject.isElement())
                                {
                                    QDomNodeList homeWorkList= itemNodeSubject.toElement().elementsByTagName("HomeWork");
                                    QDomNodeList noteList= itemNodeSubject.toElement().elementsByTagName("Note");


                                    for(int k=0;k<homeWorkList.count();k++)
                                    {

                                        QDomNode itemNodehomeWork = homeWorkList.at(k);

                                        if(itemNodehomeWork.toElement().attribute("HomeWorkName")==ui->tWSelectHomeWork->currentItem()->text(0))
                                        {
                                            return "HomeWork";
                                        }


                                    }
                                    for(int l=0;l<noteList.count();l++)
                                    {
                                        QDomNode itemNodeNote = noteList.at(l);

                                        if(itemNodeNote.toElement().attribute("NoteName")==ui->tWSelectHomeWork->currentItem()->text(0))
                                        {
                                            return "Note";
                                        }


                                    }


                                }

                            }






                        }

                }





              //ui->tWSelectHomeWork->addTopLevelItem(grade);


            }




       }


   }

}
