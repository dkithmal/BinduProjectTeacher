#include "subjectmanage.h"
#include "ui_subjectmanage.h"

SubjectManage::SubjectManage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubjectManage)
{
    ui->setupUi(this);
     filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
     basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
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
                        QDomNodeList subjctList= itemNode.toElement().elementsByTagName("Subject");

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
                    QDomNodeList subjectList= itemNode.toElement().elementsByTagName("Subject");
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

void SubjectManage::on_pBRemove_clicked()
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
