#include "selectpaperformark.h"
#include "ui_selectpaperformark.h"

SelectPaperForMark::SelectPaperForMark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectPaperForMark)
{
    ui->setupUi(this);
        filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
         basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
    setSubjectToTree();
}

SelectPaperForMark::~SelectPaperForMark()
{
    delete ui;
}


void SelectPaperForMark::setSubjectToTree()
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
                QTreeWidgetItem *grade= new QTreeWidgetItem(ui->tWSelectSubject);
                grade->setText(0,itemNode.toElement().attribute("GradeName"));

                QDomNodeList classList= itemNode.toElement().elementsByTagName("Class");

                for(int j=0;j<classList.count();j++)
                {
                    QDomNode itemNodeClass = classList.at(j);
                    QTreeWidgetItem *classItem= new QTreeWidgetItem(grade);
                    classItem->setText(0,itemNodeClass.toElement().attribute("ClassName"));



                   QDomNodeList subjecList= itemNode.toElement().elementsByTagName("Subject");

                    for(int j=0;j<subjecList.count();j++)
                    {

                    QDomNode itemNodeSubject = subjecList.at(j);
                     // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                     QTreeWidgetItem *subjectItem= new QTreeWidgetItem(classItem);
                    subjectItem->setText(0,itemNodeSubject.toElement().attribute("SubjectName"));
                    }

                }




//                QDomNodeList subjecList= itemNode.toElement().elementsByTagName("Subject");

//                    for(int j=0;j<subjecList.count();j++)
//                    {

//                        QDomNode itemNodeSubject = subjecList.at(j);
//                        // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
//                         QTreeWidgetItem *subjectItem= new QTreeWidgetItem(grade);
//                         subjectItem->setText(0,itemNodeSubject.toElement().attribute("SubjectName"));

//                         if(itemNodeSubject.isElement())
//                         {
//                             QDomNodeList homeWorkList= itemNodeSubject.toElement().elementsByTagName("HomeWork");
//                             QDomNodeList noteList= itemNodeSubject.toElement().elementsByTagName("Note");


//                             for(int k=0;k<homeWorkList.count();k++)
//                             {
//                                 QDomNode itemNodehomeWork = homeWorkList.at(k);
//                                 QTreeWidgetItem *homeWorkItem= new QTreeWidgetItem(subjectItem);
//                                 homeWorkItem->setText(0,itemNodehomeWork.toElement().attribute("HomeWorkName"));


//                             }


//                         }

//                    }




              ui->tWSelectSubject->addTopLevelItem(grade);


            }




       }


   }


}

void SelectPaperForMark::on_tWSelectSubject_clicked(const QModelIndex &index)
{
    int x=0;
    if(ui->tWSelectSubject->currentIndex().parent().parent().isValid())
    {
        ui->lWSelectPaper->clear();
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
                    if(itemNode.toElement().attribute("GradeName")==ui->tWSelectSubject->currentItem()->parent()->parent()->text(0))
                    {
                        QDomNodeList subjectList= itemNode.toElement().elementsByTagName("Subject");

                        for(int j=0;j<subjectList.count();j++)
                        {
                             QDomNode itemNodeSubject = subjectList.at(j);
                             if(itemNodeSubject.toElement().attribute("SubjectName")==ui->tWSelectSubject->currentItem()->text(0))
                             {
                                 QDomNodeList HomeWorkList=itemNodeSubject.toElement().elementsByTagName("HomeWork");

                                 for(int z=0;z<HomeWorkList.count();z++)
                                 {
                                     //qDebug()<<"ddddddddddddddddddddddddddddddddddddd";
                                     QDomNode itemNodeHomeWork= HomeWorkList.at(z);

                                     ui->lWSelectPaper->addItem(itemNodeHomeWork.toElement().attribute("HomeWorkName"));
                                    // qDebug()<<itemNodeHomeWork.toElement().attribute("HomeWorkName");


                                 }



                             }

                        }



                    }



                }




           }


       }
    }


}



void SelectPaperForMark::on_pBMarkPaper_clicked()
{
    int x=0;
    if(!ui->tWSelectSubject->currentIndex().parent().parent().isValid())
    {
         QMessageBox::information(this,"Error","Please select Subject");
         x=1;

    }
    if(!ui->lWSelectPaper->currentIndex().isValid())
    {
        QMessageBox::information(this,"Error","Please select Paper");
        x=1;

    }
    if(x==0)
    {
        QString creatingAnswerPapersPath=basicPath;
        creatingAnswerPapersPath.append("Answers/");
        creatingAnswerPapersPath.append(ui->tWSelectSubject->currentItem()->parent()->parent()->text(0));
        creatingAnswerPapersPath.append("/");
        creatingAnswerPapersPath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
        creatingAnswerPapersPath.append("/");
        creatingAnswerPapersPath.append(ui->tWSelectSubject->currentItem()->text(0));
        creatingAnswerPapersPath.append("/");
        creatingAnswerPapersPath.append(ui->lWSelectPaper->currentItem()->text());


        QString type =getPaperType(creatingAnswerPapersPath);

        if(type=="Mcq")
        {

            // to auto making the answers
            toMarkMcqPaper(creatingAnswerPapersPath);

        }
        if(type=="EssayMcq")
        {

        }
        papersummary= new Papersummary(0,creatingAnswerPapersPath);
        papersummary->setModal(false);
        papersummary->exec();

    }



}


//this method return type of the queation paper like mcq EssayMcq or Essay
QString SelectPaperForMark::getPaperType(QString paperXmlPath)
{
    QString paperXmlFilePath=paperXmlPath;
    paperXmlFilePath.append("/");
    paperXmlFilePath.append("paper.xml");


    QFile openPaperXml(paperXmlFilePath);
    if(!openPaperXml.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";
        QMessageBox::information(this,"Error","Student Answer Papers Not Available");
        //this->close();

    }
    else
    {
        if(openPaperXml.size()==0)
        {
            QMessageBox::information(this,"Error","Student Answer Papers Not Available");
            this->close();

        }
        else
        {
            QDomDocument document;

            document.setContent(&openPaperXml);
            QDomElement root= document.firstChildElement();

            QDomNodeList header = root.elementsByTagName("Header");

            return header.at(0).toElement().attribute("type");


        }


   }

}



void SelectPaperForMark::toMarkMcqPaper(QString paperXmlPath)
{

    QStringList teachrAnswerList;
    teachrAnswerList =getTeacherAnswers(paperXmlPath);

    if(teachrAnswerList.at(0)=="Error")
    {
        this->close();
    }


    QString paperXmlFilePath=paperXmlPath;
    paperXmlFilePath.append("/");
    paperXmlFilePath.append("paper.xml");





    QFile openPaperXml(paperXmlFilePath);
    if(!openPaperXml.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";
        QMessageBox::information(this,"Error","Student Answer Papers Not Available");


    }
    else
    {
        if(openPaperXml.size()==0)
        {
            QMessageBox::information(this,"Error","Student Answer Papers Not Available");
            this->close();

        }
        else
        {
            QDomDocument document;

            document.setContent(&openPaperXml);
            QDomElement root= document.firstChildElement();

            QDomNodeList header = root.elementsByTagName("Header");


            if(!(header.at(0).toElement().attribute("State")=="Marked"))
            {

                QDomNodeList studentList = root.elementsByTagName("student");

                for(int i=0;i<studentList.size();i++)
                {
                    QDomNode student=studentList.at(i);
                    QString studentName=student.toElement().attribute("StudentName");

                    QString creatingStudentPaperPath=paperXmlPath+paperXmlPath.mid(paperXmlPath.lastIndexOf("/"));
                    creatingStudentPaperPath.append("-");
                    creatingStudentPaperPath.append(studentName);
                    creatingStudentPaperPath.append(".xml");



                    //open specific student answer paper
                    int studentMarks=0;
                    QFile studentPaper(creatingStudentPaperPath);
                    if(!studentPaper.open(QFile::ReadWrite| QIODevice::Text))
                    {
                        qDebug()<<"error";


                    }
                    else
                    {
                        QDomDocument studentDocument;

                        studentDocument.setContent(&studentPaper);
                        QDomElement root= studentDocument.firstChildElement();

                        QDomNodeList mcqQuestions=root.elementsByTagName("Activity");

                         for(int j=0;j<mcqQuestions.size();j++)
                         {
                             QDomNode mcqQustionNode=mcqQuestions.at(j);




                             if(mcqQustionNode.toElement().elementsByTagName("StudentAnswer").at(0).firstChild().nodeValue()==teachrAnswerList.at(j))
                             {
                                 studentMarks++;

                             }

                         }

                    }

                    QString finalAnswer=QString::number(studentMarks).append("/").append(QString::number(teachrAnswerList.size()));

                    toUpdateMarksInPaperXml(paperXmlFilePath,studentName,finalAnswer);



                }

            }


        }


   }

}



// this method return teacher mcq answers list
QStringList SelectPaperForMark::getTeacherAnswers(QString answerPapersPath)
{

    QStringList filePathInfo=answerPapersPath.split("/");
    QString paperName=filePathInfo.at(filePathInfo.size()-1);
    QString subject=filePathInfo.at(filePathInfo.size()-2);
    QString className=filePathInfo.at(filePathInfo.size()-3);
    QString grade=filePathInfo.at(filePathInfo.size()-4);

    qDebug()<<paperName<<" "<<subject<<" "<<className<<" "<<grade;

    QString creatingQuestionPaperPath=basicPath;
    creatingQuestionPaperPath.append("HomeWork/");
    creatingQuestionPaperPath.append(grade);
    creatingQuestionPaperPath.append("/");
    creatingQuestionPaperPath.append(subject);
    creatingQuestionPaperPath.append("/");
    creatingQuestionPaperPath.append(paperName);
    creatingQuestionPaperPath.append(".xml");


    QStringList teachrAnswerList;

    QFile openTeacherPaper(creatingQuestionPaperPath);
    if(!openTeacherPaper.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";
        QMessageBox::information(this,"Error","Teacher Answer paper Not availble");
        this->close();

    }
    else
    {

            QDomDocument document;

            document.setContent(&openTeacherPaper);
            QDomElement root= document.firstChildElement();

            QDomNodeList mcqQuestions= root.elementsByTagName("Activity");

            for(int i=0;i<mcqQuestions.size();i++)
            {
                QDomNode mcqNode=mcqQuestions.at(i);

                if(mcqNode.toElement().elementsByTagName("TeacherAnswer").at(0).firstChild().nodeValue().isEmpty())
                {
                    QMessageBox::information(this,"Error","Please Create All answers to paper first");
                    teachrAnswerList.append("Error");
                    return teachrAnswerList;


                }
                else
                {
                    teachrAnswerList.append(mcqNode.toElement().elementsByTagName("TeacherAnswer").at(0).firstChild().nodeValue());

                }

            }


   }



    return teachrAnswerList;

}



//this method update marks in Paper.xml in spsific dirctry and modify student marks
void SelectPaperForMark::toUpdateMarksInPaperXml(QString paperXmlpath, QString studentName,QString marks)
{
    QFile openPaperXml(paperXmlpath);
    if(!openPaperXml.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";
        //QMessageBox::information(this,"Error","Student Answer Papers Not Available");
        //this->close();

    }
    else
    {
            QDomDocument document;

            document.setContent(&openPaperXml);
            QDomElement root= document.firstChildElement();

            QDomNodeList studentList = root.elementsByTagName("student");

            for(int i=0;i<studentList.size();i++)
            {
                if(studentList.at(i).toElement().attribute("StudentName")==studentName)
                {
                    QDomElement newStudent=document.createElement("student");
                    newStudent.setAttribute("StudentName",studentName);
                    newStudent.setAttribute("Marks",marks);
                    newStudent.setAttribute("MarkState","Marked");

                    root.replaceChild(newStudent,studentList.at(i).toElement());
                }

                }


            document.appendChild(root);
            openPaperXml.close();

            if(!openPaperXml.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
            {

            }
            else
            {
                QTextStream stream(&openPaperXml);
                stream <<document.toString();
                openPaperXml.close();

            }


            }

}


