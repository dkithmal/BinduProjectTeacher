#include "downloadfile.h"
#include "ui_downloadfile.h"

DownloadFile::DownloadFile(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::DownloadFile)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    filepath ="E:/dk work/Motarola/Project Location/Teacher Path/Administration/Admin.xml";
    basicPath="E:/dk work/Motarola/Project Location/Teacher Path/Teacher/";
  //  setFileList();
    setClassList();
}

DownloadFile::~DownloadFile()
{
    delete ui;
}

void DownloadFile::setFileList()
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


                         }

                    }




              ui->tWSelectHomeWork->addTopLevelItem(grade);


            }




       }


   }


}

void DownloadFile::setClassList()
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

void DownloadFile::on_tWSelectClass_clicked(const QModelIndex &index)
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

void DownloadFile::on_pBDownload_clicked()
{int x=0;
    if(!ui->tWSelectHomeWork->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Please select Home Work");
       x=1;
    }

    if(!ui->tWSelectClass->currentIndex().parent().isValid())
    {
        QMessageBox::information(this,"Error","Please select Class");
       x=1;

    }

    if(x==0)
    {
        QString creatingFullFilePathToSave;
        QString creatingCommand;
        QString creatingstudentList;

        //creatingFullFilePathToDownload=basicPath;
       // creatingFullFilePathToDownload.append("")

        creatingCommand="Download ";
        creatingCommand.append(ui->tWSelectHomeWork->currentItem()->parent()->text(0));
        creatingCommand.append("/Answer/");
        creatingCommand.append(ui->tWSelectHomeWork->currentItem()->text(0));


        //creating directry to subject and paper name
        QString creatingDirectries=basicPath;
        creatingDirectries.append("Answers/");
        creatingDirectries.append(ui->tWSelectClass->currentItem()->parent()->text(0));
        creatingDirectries.append("/");
        creatingDirectries.append(ui->tWSelectClass->currentItem()->text(0));
        creatingDirectries.append("/");
        creatingDirectries.append(ui->tWSelectHomeWork->currentItem()->parent()->text(0));

        if(QDir(creatingDirectries).exists())
        {
            creatingDirectries.append("/");
            creatingDirectries.append(ui->tWSelectHomeWork->currentItem()->text(0));
            if(!QDir(creatingDirectries).exists())
            {
              QDir().mkdir(creatingDirectries);
            }



        }
        else
        {
            QDir().mkdir(creatingDirectries);

            creatingDirectries.append("/");
            creatingDirectries.append(ui->tWSelectHomeWork->currentItem()->text(0));
            if(!QDir(creatingDirectries).exists())
            {
              QDir().mkdir(creatingDirectries);
            }

        }

        //finally two paths are became equil so give path
      creatingFullFilePathToSave=creatingDirectries;
      creatingFullFilePathToSave.append("/");



        if(ui->cBSelectStudent->currentText()=="All")
        {
            creatingstudentList=getSelectedClassStudents();

        }
        else
        {
            creatingstudentList=ui->cBSelectStudent->currentText();

        }

        downloadManage=new DownloadManage(0,creatingCommand,creatingFullFilePathToSave,creatingstudentList);
        downloadManage->show();

        this->close();

    }




}

QString DownloadFile::getSelectedClassStudents()
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
