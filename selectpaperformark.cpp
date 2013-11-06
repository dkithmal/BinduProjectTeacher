#include "selectpaperformark.h"
#include "ui_selectpaperformark.h"

SelectPaperForMark::SelectPaperForMark(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectPaperForMark)
{
    ui->setupUi(this);
        filepath ="D:/dk work/Motarola/Bindu New/Administration/Admin.xml";
         basicPath="D:/dk work/Motarola/Bindu New/Teacher/";

         //this is for essay and essaymcq papers
         totleMarksOfPaper=0;
         totleMarksOfStudent=0;

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


                     QDomNodeList subjecList= itemNodeClass.toElement().elementsByTagName("CSubject");

                  // QDomNodeList subjecList= itemNode.toElement().elementsByTagName("Subject");

                    for(int j=0;j<subjecList.count();j++)
                    {

                    QDomNode itemNodeSubject = subjecList.at(j);
                     // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                     QTreeWidgetItem *subjectItem= new QTreeWidgetItem(classItem);
                    subjectItem->setText(0,itemNodeSubject.toElement().attribute("SubjectName"));
                    }

                }


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

		if(type!="error")
		{
			if(type=="Mcq")
			{

				// to auto making the answers
                if(toMarkMcqPaper(creatingAnswerPapersPath)!="error")
                {
                    papersummary= new Papersummary(0,creatingAnswerPapersPath);
                    papersummary->setModal(false);
                    papersummary->exec();

                }

			}
            if(type=="EssayMcq")
			{
                if(toMarkEssayMcqPaper(creatingAnswerPapersPath)!="error")
                {
                    papersummary= new Papersummary(0,creatingAnswerPapersPath);
                    papersummary->setModal(false);
                    papersummary->exec();

                }

			}

            if(type=="Essay")
            {
                if(toMarkEssayPaper(creatingAnswerPapersPath)!="error")
                {
                    papersummary= new Papersummary(0,creatingAnswerPapersPath);
                    papersummary->setModal(false);
                    papersummary->exec();

                }

            }



		}



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
		return "error";
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



QString SelectPaperForMark::toMarkMcqPaper(QString paperXmlPath)
{

    QStringList teachrAnswerList;
    teachrAnswerList =getTeacherAnswers(paperXmlPath);

    if(teachrAnswerList.at(teachrAnswerList.size()-1)=="Error")
    {
        //this->close();
        return  "error";
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
                                 QDomElement newStudentActivity=mcqQustionNode.toElement();
                                 newStudentActivity.setAttribute("Mark","ture");
                                 root.replaceChild(newStudentActivity ,mcqQustionNode.toElement());
                                 studentMarks++;

                             }

                         }



                         //update maks in papwerxml
                         QString finalStudentMarks=QString::number(studentMarks).append("/").append(QString::number(teachrAnswerList.size()));

                         toUpdateMarksInPaperXml(paperXmlFilePath,studentName,finalStudentMarks);

                         //toupdate  marks in studetn answer xml
                         QDomElement oldheader=root.elementsByTagName("Header").at(0).toElement();
                         QDomElement newheaderNode=oldheader;

                         if(oldheader.elementsByTagName("TotalMarks").at(0).firstChild().nodeValue().isEmpty())
                         {
                             QDomElement markNode=document.createElement("TotalMarks");
                             markNode.appendChild(document.createTextNode(finalStudentMarks));
                             newheaderNode.appendChild(markNode);


                         }
                         else
                         {
                            QDomElement totleMarkNode=oldheader.elementsByTagName("TotalMarks").at(0).toElement();

                             QDomElement newTotleMark=document.createElement("TotalMarks");
                             newTotleMark.appendChild(document.createTextNode(finalStudentMarks));

                             newheaderNode.replaceChild(newTotleMark,totleMarkNode);
                         }
                          root.replaceChild(newheaderNode,oldheader);




                         studentDocument.appendChild(root);
                         studentPaper.close();

                         if(!studentPaper.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
                         {

                         }
                         else
                         {
                             QTextStream stream(&studentPaper);
                             stream <<studentDocument.toString();
                             studentPaper.close();

                         }






                    }





                }

            }


        }


   }


    return "success";

}



// this method return teacher mcq answers list
QStringList SelectPaperForMark::getTeacherAnswers(QString answerPapersPath)
{

    QStringList filePathInfo=answerPapersPath.split("/");
    QString paperName=filePathInfo.at(filePathInfo.size()-1);
    QString subject=filePathInfo.at(filePathInfo.size()-2);
    QString className=filePathInfo.at(filePathInfo.size()-3);
    QString grade=filePathInfo.at(filePathInfo.size()-4);

   // qDebug()<<paperName<<" "<<subject<<" "<<className<<" "<<grade;

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

            QDomNodeList ActivityNodes= root.elementsByTagName("Activity");

            for(int i=0;i<ActivityNodes.size();i++)
            {
                QDomNode questionNode=ActivityNodes.at(i);

                if(questionNode.toElement().attribute("Type")=="Mcq")
                {
                    if(questionNode.toElement().elementsByTagName("TeacherAnswer").at(0).firstChild().nodeValue().isEmpty())
                    {
                        QMessageBox::information(this,"Error","Please Create All answers to paper first");
                        teachrAnswerList.append("Error");
                        return teachrAnswerList;


                    }
                    else
                    {
                        teachrAnswerList.append(questionNode.toElement().elementsByTagName("TeacherAnswer").at(0).firstChild().nodeValue());
                        totleMarksOfPaper++;

                    }

                }
                if(questionNode.toElement().attribute("Type")=="Essay")
                {
                     if(questionNode.toElement().elementsByTagName("TeacharMarks").at(0).firstChild().nodeValue().isEmpty())
                     {
                         QMessageBox::information(this,"Error","Please Set Defalt Marks For the All EssayQuestions");
                         teachrAnswerList.append("Error");
                         return teachrAnswerList;
                     }
                     else
                     {
                         int teacherMarksForEssay=questionNode.toElement().elementsByTagName("TeacharMarks").at(0).firstChild().nodeValue().toInt();

                         totleMarksOfPaper=totleMarksOfPaper+teacherMarksForEssay;

                     }

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



QString  SelectPaperForMark::toMarkEssayMcqPaper(QString paperXmlPath)
{
    QStringList teachrAnswerList;
    teachrAnswerList =getTeacherAnswers(paperXmlPath);

    if(teachrAnswerList.last()=="Error")
    {
        //this->close();
        return "error";
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

                       // QDomNodeList questionNode=root.elementsByTagName("Activity");


                        QDomNodeList ActivityNodes= root.elementsByTagName("Activity");

                        int mcqCount=0;
                        for(int i=0;i<ActivityNodes.size();i++)
                        {
                            QDomNode questionNode=ActivityNodes.at(i);

                            if(questionNode.toElement().attribute("Type")=="Mcq")
                            {

                               if(questionNode.toElement().elementsByTagName("StudentAnswer").at(0).firstChild().nodeValue()==teachrAnswerList.at(mcqCount))
                                {
                                 QDomElement newStudentActivity=questionNode.toElement();
                                  newStudentActivity.setAttribute("Mark","ture");
                                  root.replaceChild(newStudentActivity ,questionNode.toElement());
                                  studentMarks++;

                                }

                                mcqCount++;

                            }
                            if(questionNode.toElement().attribute("Type")=="Essay")
                            {
                                //if paper already marked to add essay marks to student mark
                                if(!questionNode.toElement().attribute("Mark").isEmpty())
                                {
                                    int marksforEssay=questionNode.toElement().attribute("Mark").toInt();
                                    studentMarks=studentMarks+marksforEssay;

                                }



                            }
                        }




                         //update maks in paperxml
                         QString finalStudentMarks=QString::number(studentMarks).append("/").append(QString::number(totleMarksOfPaper));

                         toUpdateMarksInPaperXml(paperXmlFilePath,studentName,finalStudentMarks);

                         //toupdate  marks in studetn answer xml
                         QDomElement oldheader=root.elementsByTagName("Header").at(0).toElement();
                         QDomElement newheaderNode=oldheader;

                         if(oldheader.elementsByTagName("TotalMarks").at(0).firstChild().nodeValue().isEmpty())
                         {
                             QDomElement markNode=document.createElement("TotalMarks");
                             markNode.appendChild(document.createTextNode(finalStudentMarks));
                             newheaderNode.appendChild(markNode);


                         }
                         else
                         {

                             QDomElement totleMarkNode=oldheader.elementsByTagName("TotalMarks").at(0).toElement();

                             QDomElement newTotleMark=document.createElement("TotalMarks");
                             newTotleMark.appendChild(document.createTextNode(finalStudentMarks));

                             newheaderNode.replaceChild(newTotleMark,totleMarkNode);
                         }
                          root.replaceChild(newheaderNode,oldheader);




                         studentDocument.appendChild(root);
                         studentPaper.close();

                         if(!studentPaper.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
                         {

                         }
                         else
                         {
                             QTextStream stream(&studentPaper);
                             stream <<studentDocument.toString();
                             studentPaper.close();

                         }


                         totleMarksOfPaper=0;




                    }





                }

            }


        }


   }


    return "success";



}




QString  SelectPaperForMark::toMarkEssayPaper(QString paperXmlPath)
{



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

                       // QDomNodeList questionNode=root.elementsByTagName("Activity");


                        QDomNodeList ActivityNodes= root.elementsByTagName("Activity");


                        for(int i=0;i<ActivityNodes.size();i++)
                        {
                            QDomNode questionNode=ActivityNodes.at(i);


                            if(questionNode.toElement().attribute("Type")=="Essay")
                            {
                                if(questionNode.toElement().elementsByTagName("TeacharMarks").at(0).firstChild().nodeValue().isEmpty())
                                {
                                    QMessageBox::information(this,"Error","Please Set Defalt Marks For the All EssayQuestions");

                                    return "error";
                                }
                                else
                                {
                                    int teacherMarksForEssay=questionNode.toElement().elementsByTagName("TeacharMarks").at(0).firstChild().nodeValue().toInt();

                                    totleMarksOfPaper=totleMarksOfPaper+teacherMarksForEssay;

                                }

                                //if paper already marked to add essay marks to student mark
                                if(!questionNode.toElement().attribute("Mark").isEmpty())
                                {
                                    int marksforEssay=questionNode.toElement().attribute("Mark").toInt();
                                    studentMarks=studentMarks+marksforEssay;

                                }



                            }
                        }




                         //update maks in paperxml
                         QString finalStudentMarks=QString::number(studentMarks).append("/").append(QString::number(totleMarksOfPaper));

                         toUpdateMarksInPaperXml(paperXmlFilePath,studentName,finalStudentMarks);

                         //toupdate  marks in studetn answer xml
                         QDomElement oldheader=root.elementsByTagName("Header").at(0).toElement();
                         QDomElement newheaderNode=oldheader;

                         if(oldheader.elementsByTagName("TotalMarks").at(0).firstChild().nodeValue().isEmpty())
                         {
                             QDomElement markNode=document.createElement("TotalMarks");
                             markNode.appendChild(document.createTextNode(finalStudentMarks));
                             newheaderNode.appendChild(markNode);


                         }
                         else
                         {

                             QDomElement totleMarkNode=oldheader.elementsByTagName("TotalMarks").at(0).toElement();

                             QDomElement newTotleMark=document.createElement("TotalMarks");
                             newTotleMark.appendChild(document.createTextNode(finalStudentMarks));

                             newheaderNode.replaceChild(newTotleMark,totleMarkNode);
                         }
                          root.replaceChild(newheaderNode,oldheader);




                         studentDocument.appendChild(root);
                         studentPaper.close();

                         if(!studentPaper.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
                         {

                         }
                         else
                         {
                             QTextStream stream(&studentPaper);
                             stream <<studentDocument.toString();
                             studentPaper.close();

                         }






                    }





                }

            }


        }


   }


    return "success";



}


