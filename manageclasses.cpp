#include "manageclasses.h"
#include "ui_manageclasses.h"

ManageClasses::ManageClasses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManageClasses)
{
    ui->setupUi(this);
    ui->tWManage->setCurrentIndex(0);
    //filepath means config filepath
    filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
    basicPath="D:/dk work/Motarola/Bindu New/Teacher/";

}

ManageClasses::~ManageClasses()
{
    delete ui;
}

void ManageClasses::on_pBAddGrade_clicked()
{
    int x=0;
    if(ui->lEGradeName->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Enter Grade");
        x=1;
    }

    if(x==0)
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
                root = document.createElement("Administration");
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

                //creating new dirctry for grade
                QString creatingHWGradePath=basicPath;
                QString creatingNoteGradePath=basicPath;
                QString creatingAnswerGradePath=basicPath;


                //creating directry to Grade in Homework
                creatingHWGradePath.append("HomeWork");
                if(QDir(creatingHWGradePath).exists())
                {
                    creatingHWGradePath.append("/");
                    creatingHWGradePath.append(ui->lEGradeName->text());
                    QDir().mkdir(creatingHWGradePath);


                }
                else
                {
                     QDir().mkdir(creatingHWGradePath);
                     creatingHWGradePath.append("/");
                     creatingHWGradePath.append(ui->lEGradeName->text());
                     QDir().mkdir(creatingHWGradePath);


                }

                //creading directriy to Grade in Note
                creatingNoteGradePath.append("Note");
                if(QDir(creatingNoteGradePath).exists())
                {
                    creatingNoteGradePath.append("/");
                    creatingNoteGradePath.append(ui->lEGradeName->text());
                    QDir().mkdir(creatingNoteGradePath);


                }
                else
                {
                     QDir().mkdir(creatingNoteGradePath);
                     creatingNoteGradePath.append("/");
                     creatingNoteGradePath.append(ui->lEGradeName->text());
                     QDir().mkdir(creatingNoteGradePath);


                }


                //creating directry to Grade in Answers
                creatingAnswerGradePath.append("Answers");
                if(QDir(creatingAnswerGradePath).exists())
                {
                    creatingAnswerGradePath.append("/");
                    creatingAnswerGradePath.append(ui->lEGradeName->text());
                    QDir().mkdir(creatingAnswerGradePath);


                }
                else
                {
                     QDir().mkdir(creatingAnswerGradePath);
                     creatingAnswerGradePath.append("/");
                     creatingAnswerGradePath.append(ui->lEGradeName->text());
                     QDir().mkdir(creatingAnswerGradePath);


                }


               // newGradepath.append(ui->lEGradeName->text());
               // QDir().mkdir(newGradepath);
                ui->lEGradeName->clear();

                QMessageBox::information(this,"Success","New Grade Created");



            }



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
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");

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

  if(index==3)
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

          ui->cBSelectGrade->clear();
          for(int i=0;i<grades.count();i++)
          {
              QDomNode itemNode = grades.at(i);

              if(itemNode.isElement())
              {

                  //gradeList.append(itemNode.toElement().attribute("GradeName"));
                  ui->cBSelectGrade->addItem(itemNode.toElement().attribute("GradeName"));


          }


      }


     }

  }

   if(index==4)
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

           ui->cBSelectGradeForRClass->clear();
           for(int i=0;i<grades.count();i++)
           {
               QDomNode itemNode = grades.at(i);

               if(itemNode.isElement())
               {

                   //gradeList.append(itemNode.toElement().attribute("GradeName"));
                   ui->cBSelectGradeForRClass->addItem(itemNode.toElement().attribute("GradeName"));

                   if(i==0)
                   {
                       QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");

                       ui->cBSelectClassForRClass->clear();
                       for(int j=0;j<classList.count();j++)
                       {
                           QDomNode itemNodeClass = classList.at(j);
                            ui->cBSelectClassForRClass->addItem(itemNodeClass.toElement().attribute("ClassName"));

                       }

                   }


               }




          }


      }
   }

    if(index==5)
    {
        ui->cBSelectStudentFRStudent->clear();
        ui->cBSelectClassFRStudent->clear();
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

            ui->cBSelectGradeFRStudent->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {

                    //gradeList.append(itemNode.toElement().attribute("GradeName"));
                    ui->cBSelectGradeFRStudent->addItem(itemNode.toElement().attribute("GradeName"));

                    if(i==0)
                    {
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");

                        ui->cBSelectClassFRStudent->clear();
                        for(int j=0;j<classList.count();j++)
                        {
                            QDomNode itemNodeClass = classList.at(j);
                             ui->cBSelectClassFRStudent->addItem(itemNodeClass.toElement().attribute("ClassName"));
                             if(j==0&&i==0)
                             {
                                 QDomNodeList studentList=itemNodeClass.toElement().elementsByTagName("students");
                                 QDomNode students=studentList.at(0);
                                 QString studentNameList=students.firstChild().nodeValue();
                                // qDebug()<<studentNameList<<"student NameList";
                                 QStringList studentNameSplitedList=studentNameList.split(",");

                                 ui->cBSelectStudentFRStudent->clear();
                                 foreach (QString studentName, studentNameSplitedList)
                                 {
                                     ui->cBSelectStudentFRStudent->addItem(studentName);

                                 }


                             }



                        }

                    }


                }




           }


       }

    }

}


void ManageClasses::on_pBCreateClass_clicked()
{
    int x=0;
    if(ui->cBSelectGrade_2->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Grade");
        x=1;

    }
    if(ui->lEClassName->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Enter Class name");
        x=1;

    }
    if(ui->tEStudents->document()->toPlainText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Enter atleast one studnet");
        x=1;

    }

    if(x==0)
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



                //creating class directry in Answer directry
                QString creatingClassInAnswerDirectry=basicPath;
                creatingClassInAnswerDirectry.append("Answers/");
                creatingClassInAnswerDirectry.append(ui->cBSelectGrade_2->currentText());
                creatingClassInAnswerDirectry.append("/");
                creatingClassInAnswerDirectry.append(ui->lEClassName->text());
                QDir().mkdir(creatingClassInAnswerDirectry);


                QMessageBox::information(this,"Success","New Class Created");
                ui->lEGradeName->clear();


                ui->lEClassName->clear();
                ui->tEStudents->clear();

            }

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

            //ui->cBSelectGrade_2->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {
                    if(ui->cBSelectGrade_3->currentText()==itemNode.toElement().attribute("GradeName"))
                    {
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");
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

void ManageClasses::on_pBAddStudent_clicked()
{
    int x=0;

    if(ui->cBSelectGrade_3->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Grade");
        x=1;

    }
    if(ui->cBSelectClass->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Class name");
        x=1;

    }
    if(ui->lEStudentName->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Enter student name");
        x=1;

    }

    if(x==0)
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
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");


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


}

void ManageClasses::on_cBSelectGradeForRClass_currentIndexChanged(int index)
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

       // ui->cBSelectGrade_2->clear();
        for(int i=0;i<grades.count();i++)
        {
            QDomNode itemNode = grades.at(i);

            if(itemNode.isElement())
            {
                if(ui->cBSelectGradeForRClass->currentText()==itemNode.toElement().attribute("GradeName"))
                {
                    QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");
                    ui->cBSelectClassForRClass->clear();
                    for(int j=0;j<classList.count();j++)
                    {
                        QDomNode itemNodeClass = classList.at(j);
                         ui->cBSelectClassForRClass->addItem(itemNodeClass.toElement().attribute("ClassName"));

                    }

                }


               // break;

            }




       }


   }

}


void ManageClasses::on_cBSelectGradeFRStudent_currentIndexChanged(int index)
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

       // ui->cBSelectGrade_2->clear();
        for(int i=0;i<grades.count();i++)
        {
            QDomNode itemNode = grades.at(i);

            if(itemNode.isElement())
            {
                if(ui->cBSelectGradeFRStudent->currentText()==itemNode.toElement().attribute("GradeName"))
                {
                    QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");
                    ui->cBSelectClassFRStudent->clear();
                    for(int j=0;j<classList.count();j++)
                    {
                        QDomNode itemNodeClass = classList.at(j);
                         ui->cBSelectClassFRStudent->addItem(itemNodeClass.toElement().attribute("ClassName"));

                    }

                }


               // break;

            }




       }


   }

}

void ManageClasses::on_cBSelectClassFRStudent_currentIndexChanged(int index)
{
    ui->cBSelectStudentFRStudent->clear();
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

       // ui->cBSelectGrade_2->clear();
        for(int i=0;i<grades.count();i++)
        {
            QDomNode itemNode = grades.at(i);

            if(itemNode.isElement())
            {
                if(ui->cBSelectGradeFRStudent->currentText()==itemNode.toElement().attribute("GradeName"))
                {
                    QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");
                  //  ui->cBSelectClassFRStudent->clear();
                    for(int j=0;j<classList.count();j++)
                    {
                        QDomNode itemNodeClass = classList.at(j);
                        if(itemNodeClass.toElement().attribute("ClassName")==ui->cBSelectClassFRStudent->currentText())
                        {
                            QDomNodeList studentList=itemNodeClass.toElement().elementsByTagName("students");
                            QDomNode students=studentList.at(0);
                            QString studentNameList=students.firstChild().nodeValue();
                           // qDebug()<<studentNameList<<"student NameList";
                            QStringList studentNameSplitedList=studentNameList.split(",");
                           ui->cBSelectStudentFRStudent->clear();
                            foreach (QString studentName, studentNameSplitedList)
                            {
                                ui->cBSelectStudentFRStudent->addItem(studentName);

                            }

                        }
                        // ui->cBSelectClassFRStudent->addItem(itemNodeClass.toElement().attribute("ClassName"));

                    }

                }


               // break;

            }




       }


   }

}

void ManageClasses::on_pBRemoveGrade_clicked()
{
    int x=0;
    if(ui->cBSelectGrade->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Grade");
        x=1;

    }

    if(x==0)
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

           // ui->cBSelectGrade_2->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {
                    if(ui->cBSelectGrade->currentText()==itemNode.toElement().attribute("GradeName"))
                    {
                        root.removeChild(itemNode);


                    }


                   // break;

                }




           }

            document.appendChild(root);
            openConfigFile.close();

            if(!openConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
            {

            }
            else
            {
                QTextStream stream(&openConfigFile);
                stream <<document.toString();
                openConfigFile.close();

                QString creatingHWGradePath=basicPath;
                QString creatingNoteGradePath=basicPath;
                QString creatingAnswerGradePath=basicPath;


                //creating path to delete directry form homeWork
                creatingHWGradePath.append("HomeWork/");
                creatingHWGradePath.append(ui->cBSelectGrade->currentText());
                if(QDir(creatingHWGradePath).exists())
                {
                    bool a=removeDir(creatingHWGradePath);

                }

                //creating path to delete directry form Note
                creatingNoteGradePath.append("Note/");
                creatingNoteGradePath.append(ui->cBSelectGrade->currentText());
                if(QDir(creatingNoteGradePath).exists())
                {
                    bool a=removeDir(creatingNoteGradePath);

                }

                //creating path to delete diretry from Anserts
                creatingAnswerGradePath.append("Answers/");
                creatingAnswerGradePath.append(ui->cBSelectGrade->currentText());
                if(QDir(creatingAnswerGradePath).exists())
                {
                    bool a=removeDir(creatingAnswerGradePath);

                }

              }


            }

            on_tWManage_currentChanged(3);
    }


 }

bool ManageClasses::removeDir(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeDir(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }

    return result;
}




void ManageClasses::on_pBRemoveClass_clicked()
{
    int x=0;
    if(ui->cBSelectGradeForRClass->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Grade");
        x=1;

    }
    if(ui->cBSelectClassForRClass->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Class");
        x=1;

    }

    if(x==0)
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

           // ui->cBSelectGrade_2->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {
                    if(ui->cBSelectGradeFRStudent->currentText()==itemNode.toElement().attribute("GradeName"))
                    {
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");
                      //  ui->cBSelectClassFRStudent->clear();
                        for(int j=0;j<classList.count();j++)
                        {
                            QDomNode itemNodeClass = classList.at(j);
                            if(itemNodeClass.toElement().attribute("ClassName")==ui->cBSelectClassFRStudent->currentText())
                            {
                                itemNode.toElement().removeChild(itemNodeClass);


                            }
                            // ui->cBSelectClassFRStudent->addItem(itemNodeClass.toElement().attribute("ClassName"));

                        }

                    }


                   // break;

                }




           }

            document.appendChild(root);
            openConfigFile.close();

            if(!openConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
            {

            }
            else
            {
                QTextStream stream(&openConfigFile);
                stream <<document.toString();
                openConfigFile.close();

                //creating class directry in Answer directry
                QString creatingClassInAnswerDirectry=basicPath;
                creatingClassInAnswerDirectry.append("Answers/");
                creatingClassInAnswerDirectry.append(ui->cBSelectGradeForRClass->currentText());
                creatingClassInAnswerDirectry.append("/");
                creatingClassInAnswerDirectry.append(ui->cBSelectClassForRClass->currentText());

                if(QDir(creatingClassInAnswerDirectry).exists())
                {
                    bool a=removeDir(creatingClassInAnswerDirectry);

                }



            }



       }

        on_tWManage_currentChanged(4);

    }



}

void ManageClasses::on_pBRemoveStudent_clicked()
{
    int x=0;
    if(ui->cBSelectGradeFRStudent->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Grade");
        x=1;

    }
    if(ui->cBSelectClassFRStudent->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Class");
        x=1;
    }
    if(ui->cBSelectStudentFRStudent->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Student");
        x=1;

    }
    if(x==0)
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

           // ui->cBSelectGrade_2->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {
                    if(ui->cBSelectGradeFRStudent->currentText()==itemNode.toElement().attribute("GradeName"))
                    {
                        QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");
                      //  ui->cBSelectClassFRStudent->clear();
                        for(int j=0;j<classList.count();j++)
                        {
                            QDomNode itemNodeClass = classList.at(j);
                            if(itemNodeClass.toElement().attribute("ClassName")==ui->cBSelectClassFRStudent->currentText())
                            {
                                QDomNodeList studentList=itemNodeClass.toElement().elementsByTagName("students");
                                QDomNode students=studentList.at(0);
                                QString studentNameList=students.firstChild().nodeValue();
                                QStringList studentNameSplitedList=studentNameList.split(",");


                                QString newStudentNameList;
                                int d=0;
                                foreach (QString studentName, studentNameSplitedList)
                                {

                                    if(!(ui->cBSelectStudentFRStudent->currentText()==studentName))
                                    {
                                        newStudentNameList.append(studentName);
                                        if(d!=(studentNameSplitedList.size()-1))
                                        {
                                            newStudentNameList.append(",");

                                        }


                                    }

                                    d++;

                                }


                                QDomElement newStudentNode= document.createElement("students");
                                newStudentNode.appendChild(document.createTextNode(newStudentNameList));


                                itemNodeClass.replaceChild(newStudentNode,students);


                            }


                        }

                    }


                   // break;

                }




           }

            document.appendChild(root);
            openConfigFile.close();

            if(!openConfigFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
            {

            }
            else
            {
                QTextStream stream(&openConfigFile);
                stream <<document.toString();
                openConfigFile.close();
            }


       }

       on_tWManage_currentChanged(5);
    }
    //ui->cBSelectStudentFRStudent->clear();


}
