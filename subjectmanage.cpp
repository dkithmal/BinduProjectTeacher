#include "subjectmanage.h"
#include "ui_subjectmanage.h"

SubjectManage::SubjectManage(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::SubjectManage)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
     filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
     basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
     ui->tWSubjectManage->setCurrentIndex(0);
     ui->tWSubjectManage->setTabIcon(0,QIcon(":/binduTeacher/new/imgs/addsubject.png"));
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


            if(i==0)
            {
                QDomNodeList classList=itemNode.toElement().elementsByTagName("Class");

                 ui->cBSelectClass->clear();
                for(int k=0;k<classList.size();k++)
                {
                    QDomNode classItemNode = classList.at(k);

                    ui->cBSelectClass->addItem(classItemNode.toElement().attribute("ClassName"));

                }

            }


     }


   }


}

void SubjectManage::on_pBAddSubject_clicked()
{
    int x=0;
    if(ui->cBSelectGradeAdd->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Grade");
        x=1;

    }
    if(ui->lESubjectName->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Enter Subject Name");
        x=1;

    }

    if(ui->cBSelectClass->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Class to add subject");
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




                    if(!itemNode.toElement().attribute("GradeName").compare(ui->cBSelectGradeAdd->currentText()))
                    {
                        QDomNodeList subjectList=itemNode.toElement().elementsByTagName("Subject");
                    int itemExist=0;
                        for(int e=0;e<subjectList.size();e++)
                        {
                            QDomNode itemNodeSubject=subjectList.at(e);

                            if(itemNodeSubject.toElement().attribute("SubjectName")==ui->lESubjectName->text())
                            {
                                itemExist=1;
                                break;

                            }

                        }

                        if(itemExist==0)
                        {
                            QDomElement subject= document.createElement("Subject");
                            subject.setAttribute("SubjectName",ui->lESubjectName->text());
                            itemNode.appendChild(subject);

                        }


                        QDomNodeList classListForCheck = itemNode.toElement().elementsByTagName("Class");


                         int itemExistSubject=0;
                        for(int f=0;f<classListForCheck.size();f++)
                        {
                            QDomNode itemNodeClass=classListForCheck.at(f);

                            if(itemNodeClass.toElement().attribute("ClassName")==ui->cBSelectClass->currentText())
                            {
                                QDomNodeList subjectListForClass=itemNodeClass.toElement().elementsByTagName("CSubject");


                                for(int u=0;u<subjectListForClass.size();u++)
                                {
                                    QDomNode itemNodeCSubject=subjectListForClass.at(u);

                                    if(itemNodeCSubject.toElement().attribute("SubjectName")==ui->lESubjectName->text())
                                    {itemExistSubject=1;
                                        QMessageBox::information(this,"Error","This Subject Already exist in this class");
                                       return;

                                    }

                                }


                            }

                        }

                        if(itemExistSubject==0)
                        {
                            //root.appendChild(itemNode)

                            //create subject eliment in classs element
                            QDomNodeList classList=itemNode.toElement().elementsByTagName("Class");

                            for(int z=0;z<classList.size();z++)
                            {
                                if(classList.at(z).toElement().attribute("ClassName")==ui->cBSelectClass->currentText())
                                {
                                    QDomElement subjectToClass= document.createElement("CSubject");
                                    subjectToClass.setAttribute("SubjectName",ui->lESubjectName->text());
                                    classList.at(z).appendChild(subjectToClass);

                                }

                            }

                        }





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

                //creating new dirctrys
                QString newSubjectPathForHomework=basicPath;
                QString newSubjectPathForNote=basicPath;

                //creating new directry in homework directry
                newSubjectPathForHomework.append("HomeWork/");
                newSubjectPathForHomework.append(ui->cBSelectGradeAdd->currentText());
                newSubjectPathForHomework.append("/");
                newSubjectPathForHomework.append(ui->lESubjectName->text());
                if(!QDir(newSubjectPathForHomework).exists())
                {
                    QDir().mkdir(newSubjectPathForHomework);


                }

                //creating new directry in homework directry
                newSubjectPathForNote.append("Note/");
                newSubjectPathForNote.append(ui->cBSelectGradeAdd->currentText());
                newSubjectPathForNote.append("/");
                newSubjectPathForNote.append(ui->lESubjectName->text());
                if(!QDir(newSubjectPathForNote).exists())
                {
                    QDir().mkdir(newSubjectPathForNote);


                }




                QMessageBox::information(this,"Success","New Subject Created");
                ui->lESubjectName->clear();


            }

        }

    }


}

void SubjectManage::on_tWSubjectManage_currentChanged(int index)
{
    if(index==0)
    {
        setDefaultCB();

    }
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

            ui->cBSelectGradeRemove->clear();
            for(int i=0;i<grades.count();i++)
            {
                QDomNode itemNode = grades.at(i);

                if(itemNode.isElement())
                {

                    //gradeList.append(itemNode.toElement().attribute("GradeName"));
                    ui->cBSelectGradeRemove->addItem(itemNode.toElement().attribute("GradeName"));

                    if(i==0)
                    {
                        QDomNodeList classList=itemNode.toElement().elementsByTagName("Class");

                        ui->cBSelectClassToRSub->clear();
                        for(int l=0;l<classList.size();l++)
                        {
                            QDomNode itemNodeClass = classList.at(l);
                             ui->cBSelectClassToRSub->addItem(itemNodeClass.toElement().attribute("ClassName"));

                             if(l==0)
                             {

                                     QDomNodeList classList=itemNode.toElement().elementsByTagName("Class");

                                     for(int k=0;k<classList.size();k++)
                                     {
                                         QDomNode classItemNode = classList.at(k);

                                         ui->cBSelectClass->addItem(classItemNode.toElement().attribute("ClassName"));

                                     }



                                 QDomNodeList subjctList= itemNodeClass.toElement().elementsByTagName("CSubject");

                                 ui->cBSelectSubjectRemove->clear();
                                 for(int j=0;j<subjctList.count();j++)
                                 {
                                     QDomNode itemNodeSubject = subjctList.at(j);
                                      ui->cBSelectSubjectRemove->addItem(itemNodeSubject.toElement().attribute("SubjectName"));

                                 }

                             }

                        }



                    }


                }




           }


       }

    }
}

void SubjectManage::on_cBSelectGradeRemove_currentIndexChanged(int index)
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
                if(ui->cBSelectGradeRemove->currentText()==itemNode.toElement().attribute("GradeName"))
                {
                    QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");
                    ui->cBSelectClassToRSub->clear();
                    for(int j=0;j<classList.count();j++)
                    {
                        QDomNode itemNodeSubject = classList.at(j);
                         ui->cBSelectClassToRSub->addItem(itemNodeSubject.toElement().attribute("ClassName"));

                    }

                }



            }




       }


   }
}

void SubjectManage::on_pBRemove_clicked()
{
    int x=0;
    if(ui->cBSelectGradeRemove->currentText().isEmpty())
    {
         QMessageBox::information(this,"Error","Please Select Grade");
        x=1;
    }
    if(ui->cBSelectSubjectRemove->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Subject");
        x=1;
    }

    if(ui->cBSelectClassToRSub->currentText().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Select Class To Remove");
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
                    if(ui->cBSelectGradeRemove->currentText()==itemNode.toElement().attribute("GradeName"))
                    {
                         QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");

                         for(int k=0;k<classList.size();k++)
                         {
                             QDomNode itemNodeClass= classList.at(k);

                             if(itemNodeClass.toElement().attribute("ClassName")==ui->cBSelectClassToRSub->currentText())
                             {
                                 QDomNodeList ClassSubjectList= itemNode.toElement().elementsByTagName("CSubject");
                               //  ui->cBSelectClassFRStudent->clear();
                                 for(int z=0;z<ClassSubjectList.count();z++)
                                 {
                                     QDomNode itemNodeSubject= ClassSubjectList.at(z);
                                     if(itemNodeSubject.toElement().attribute("SubjectName")==ui->cBSelectSubjectRemove->currentText())
                                     {
                                         itemNodeClass.toElement().removeChild(itemNodeSubject);


                                     }
                                     // ui->cBSelectClassFRStudent->addItem(itemNodeClass.toElement().attribute("ClassName"));

                                 }

                             }

                         }




                        QDomNodeList subjectList= itemNode.toElement().elementsByTagName("Subject");
                      //  ui->cBSelectClassFRStudent->clear();
                        for(int j=0;j<subjectList.count();j++)
                        {
                            QDomNode itemNodeSubject= subjectList.at(j);
                            if(itemNodeSubject.toElement().attribute("SubjectName")==ui->cBSelectSubjectRemove->currentText())
                            {
                                itemNode.toElement().removeChild(itemNodeSubject);


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
                QString removeingSubjectInHomWordDirectry=basicPath;
                removeingSubjectInHomWordDirectry.append("HomeWork/");
                removeingSubjectInHomWordDirectry.append(ui->cBSelectGradeRemove->currentText());
                removeingSubjectInHomWordDirectry.append("/");
                removeingSubjectInHomWordDirectry.append(ui->cBSelectSubjectRemove->currentText());

                if(QDir(removeingSubjectInHomWordDirectry).exists())
                {
                    bool a=removeDir(removeingSubjectInHomWordDirectry);

                }

                qDebug()<<removeingSubjectInHomWordDirectry<<"delete file path";
                //creating class directry in Answer directry
                QString removeingSubjectInNoteDirectry=basicPath;
                removeingSubjectInNoteDirectry.append("Note/");
                removeingSubjectInNoteDirectry.append(ui->cBSelectGradeRemove->currentText());
                removeingSubjectInNoteDirectry.append("/");
                removeingSubjectInNoteDirectry.append(ui->cBSelectSubjectRemove->currentText());

                qDebug()<<removeingSubjectInNoteDirectry<<"delete file path 2";

                if(QDir(removeingSubjectInNoteDirectry).exists())
                {
                    bool a=removeDir(removeingSubjectInNoteDirectry);

                }



            }



       }

        on_tWSubjectManage_currentChanged(1);

    }



}

bool SubjectManage::removeDir(const QString &dirName)
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

void SubjectManage::on_cBSelectGradeAdd_currentIndexChanged(int index)
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
                if(ui->cBSelectGradeAdd->currentText()==itemNode.toElement().attribute("GradeName"))
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

void SubjectManage::on_cBSelectClassToRSub_currentIndexChanged(int index)
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
                if(ui->cBSelectGradeRemove->currentText()==itemNode.toElement().attribute("GradeName"))
                {
                    QDomNodeList classList=itemNode.toElement().elementsByTagName("Class");


                    for(int k=0;k<classList.size();k++)
                    {
                        if(classList.at(k).toElement().attribute("ClassName")==ui->cBSelectClassToRSub->currentText())
                        {
                            QDomNodeList subjectList= classList.at(k).toElement().elementsByTagName("CSubject");
                            ui->cBSelectSubjectRemove->clear();
                            for(int j=0;j<subjectList.count();j++)
                            {
                                QDomNode itemNodeSubject = subjectList.at(j);
                                 ui->cBSelectSubjectRemove->addItem(itemNodeSubject.toElement().attribute("SubjectName"));

                            }

                        }
                    }



                }



            }




       }


   }
}


