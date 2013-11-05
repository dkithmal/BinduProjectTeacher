#include "markingpapers.h"
#include "ui_markingpapers.h"

MarkingPapers::MarkingPapers(QWidget *parent,QString filePath) :
    QDialog(parent),
    ui(new Ui::MarkingPapers)
{
    ui->setupUi(this);

    paperOpenPath=filePath;

   studentName=paperOpenPath.mid(paperOpenPath.lastIndexOf("-")+1,paperOpenPath.lastIndexOf(".")-paperOpenPath.lastIndexOf("-")-1);

    //qDebug()<<paperOpenPath<<"ssssssssssssssssssssssss";
    qustionNo = 0;
    mcqNo=0;
    essayNO=0;
    totalNoOfQuestions=0;
    indexofTabWidget=0;

    paperHeaderLayout=0;
    paperQuestionsLayout=0;
    questionLayout[0]=0;
    questionLayout[1]=0;
    questionLayout[2]=0;
    questionLayout[3]=0;
    questionLayout[4]=0;

    ui->pBPrivious->setEnabled(false);
    ui->lEAnswer1Marks->setHidden(true);
    ui->lEAnswer2Marks->setHidden(true);
    ui->lEAnswer3Marks->setHidden(true);
    ui->lEAnswer4Marks->setHidden(true);
    ui->lEAnswer5Marks->setHidden(true);


    toCreatePaperLayout();
}

MarkingPapers::~MarkingPapers()
{
    delete ui;
}

void MarkingPapers::toCreatePaperLayout()
{

    QFile newPaperFile(paperOpenPath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&newPaperFile);
        //qDebug()<<document.toString();

        QDomElement root= document.firstChildElement();

        if(paperQuestionsLayout!=NULL)
        {
            QLayoutItem * item;
            QLayout * sublayout;
            QWidget * widget;

            while ((item = paperQuestionsLayout->takeAt(0))) {
                if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                else {delete item;}
            }

            // then finally
            delete paperQuestionsLayout;
            paperQuestionsLayout=0;

            if(questionLayout[0]!=NULL)
            {
                while ((item = questionLayout[0]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[0];
                questionLayout[0]=0;
            }
            if(questionLayout[1]!=NULL)
            {
                while ((item = questionLayout[1]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[1];
                questionLayout[1]=0;
            }
            if(questionLayout[2]!=NULL)
            {
                while ((item = questionLayout[2]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[2];
                questionLayout[2]=0;
            }
            if(questionLayout[3]!=NULL)
            {
                while ((item = questionLayout[3]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[3];
                questionLayout[3]=0;
            }
            if(questionLayout[4]!=NULL)
            {
                while ((item = questionLayout[4]->takeAt(0))) {
                    if ((sublayout = item->layout()) != 0){/* do the same for sublayout*/}
                    else if ((widget = item->widget()) != 0) {widget->hide(); delete widget;}
                    else {delete item;}
                }

                delete questionLayout[4];
                questionLayout[4]=0;
            }


               // drowHeader(root);
                drowQuestions(root);


        }
        else
        {
                drowHeader(root);
                drowQuestions(root);


        }








    }

}

void MarkingPapers::drowHeader(QDomElement root)
{
    QDomNodeList items = root.elementsByTagName("Header");

      QDomNode itemNode = items.at(0);
      QDomElement itemElement=itemNode.toElement();

      QDomNode title=itemElement.elementsByTagName("Title").at(0);
      QDomNode subject=itemElement.elementsByTagName("Subject").at(0);
      QDomNode duration=itemElement.elementsByTagName("Duration").at(0);
      QDomNode totalmarks=itemElement.elementsByTagName("TotalMarks").at(0);


      QLabel *lTitle=new QLabel("<h5>"+title.firstChild().nodeValue()+"</h5>");
      QLabel *lSubject=new QLabel("Subject :"+subject.firstChild().nodeValue());
      QLabel *lDuration=new QLabel("Duration :"+duration.firstChild().nodeValue());

      totalStudentMarks=totalmarks.firstChild().nodeValue();
      ui->lETotalMarks->setText(totalmarks.firstChild().nodeValue());
      ui->lETotalMarks->setReadOnly(true);
      ui->lStudentName->setText(studentName);

      paperHeaderLayout = new QVBoxLayout;

      paperHeaderLayout->addWidget(lTitle,0,Qt::AlignCenter);
      paperHeaderLayout->addWidget(lSubject);
      paperHeaderLayout->addWidget(lDuration);


       ui->gBHeader->setLayout(paperHeaderLayout);


}

void MarkingPapers::drowQuestions(QDomElement root)
{
    int qNoInPage=1;

    QDomNodeList activityItems = root.elementsByTagName("Activity");
    paperQuestionsLayout = new QVBoxLayout;

    totalNoOfQuestions=activityItems.count();
    if(totalNoOfQuestions<=5)
    {
        ui->pBNext->setEnabled(false);
    }
    else if(ui->lPageNo->text().toInt()==1)
    {
      ui->pBNext->setEnabled(true);
    }


    int i=0;
    int j=0;
    if(ui->lPageNo->text().toInt()==1)
    {
        j=5;

    }
    else
    {
        i=(ui->lPageNo->text().toInt()-1)*5;
        j=i+5;
    }
    for (i;i<j;i++)
    {
        QDomNode itemNode = activityItems.at(i);
         questionLayout[qNoInPage-1] = new QGridLayout;


        if(itemNode.isElement())
        {

            if(itemNode.toElement().attribute("Type")=="Mcq")
            {
                int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();
                int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();
                int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();


                QDomElement itemElement=itemNode.toElement();
                QDomNode question=itemElement.elementsByTagName("Question").at(0);
                qusestionLables[questionNo]=new QLabel(QString::number(questionNo)+")"+question.firstChild().nodeValue());

                QString marks=itemNode.toElement().attribute("Mark");
                if(qNoInPage==1)
                {
                    ui->lEAnswer1Marks->setHidden(false);
                    if(!marks.isEmpty())
                        ui->lEAnswer1Marks->setText("correct");
                    else
                    {
                        ui->lEAnswer1Marks->setText("wrong");

                    }
                    ui->lEAnswer1Marks->setReadOnly(true);

                }

                if(qNoInPage==2)
                {
                    ui->lEAnswer2Marks->setHidden(false);
                    if(!marks.isEmpty())
                        ui->lEAnswer2Marks->setText("correct");
                    else
                    {
                        ui->lEAnswer2Marks->setText("wrong");

                    }
                    ui->lEAnswer2Marks->setReadOnly(true);


                }
                if(qNoInPage==3)
                {
                    ui->lEAnswer3Marks->setHidden(false);
                    if(!marks.isEmpty())
                        ui->lEAnswer3Marks->setText("correct");
                    else
                    {
                        ui->lEAnswer3Marks->setText("wrong");

                    }
                    ui->lEAnswer3Marks->setReadOnly(true);


                }
                if(qNoInPage==4)
                {
                    ui->lEAnswer4Marks->setHidden(false);
                    if(!marks.isEmpty())
                        ui->lEAnswer4Marks->setText("correct");
                    else
                    {
                        ui->lEAnswer4Marks->setText("wrong");

                    }
                    ui->lEAnswer4Marks->setReadOnly(true);


                }
                if(qNoInPage==5)
                {
                    ui->lEAnswer5Marks->setHidden(false);
                    if(!marks.isEmpty())
                        ui->lEAnswer5Marks->setText("correct");
                    else
                    {
                        ui->lEAnswer5Marks->setText("wrong");

                    }
                    ui->lEAnswer5Marks->setReadOnly(true);


                }




                if(noOfChoises==2)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);

                    rBMcqAnswers[mcqQusrionNo-1][0]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][1]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());

                    rBMcqAnswers[mcqQusrionNo-1][0]->setEnabled(false);
                    rBMcqAnswers[mcqQusrionNo-1][1]->setEnabled(false);

                    questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo],0,0,1,40,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("1)", this),1,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0],1,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("2)", this), 1,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1],1,21,1,19,0);



                }
                if(noOfChoises==3)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);
                    QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);

                    rBMcqAnswers[mcqQusrionNo-1][0]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][1]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][2]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][2]->setText(answer3.firstChild().nodeValue());

                    rBMcqAnswers[mcqQusrionNo-1][0]->setEnabled(false);
                    rBMcqAnswers[mcqQusrionNo-1][1]->setEnabled(false);
                    rBMcqAnswers[mcqQusrionNo-1][2]->setEnabled(false);


                    questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo],0,0,1,40,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("1)", this),1,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0],1,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("2)", this), 1,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1],1,21,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("3)", this), 2,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][2],2,1,1,39,0);


                }
                if(noOfChoises==4)
                {
                    QDomNode answer1=itemElement.elementsByTagName("Choice").at(0);
                    QDomNode answer2=itemElement.elementsByTagName("Choice").at(1);
                    QDomNode answer3=itemElement.elementsByTagName("Choice").at(2);
                    QDomNode answer4=itemElement.elementsByTagName("Choice").at(3);

                    rBMcqAnswers[mcqQusrionNo-1][0]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][0]->setText(answer1.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][1]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][1]->setText(answer2.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][2]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][2]->setText(answer3.firstChild().nodeValue());
                    rBMcqAnswers[mcqQusrionNo-1][3]=new QRadioButton();
                    rBMcqAnswers[mcqQusrionNo-1][3]->setText(answer4.firstChild().nodeValue());

                    rBMcqAnswers[mcqQusrionNo-1][0]->setEnabled(false);
                    rBMcqAnswers[mcqQusrionNo-1][1]->setEnabled(false);
                    rBMcqAnswers[mcqQusrionNo-1][2]->setEnabled(false);
                    rBMcqAnswers[mcqQusrionNo-1][3]->setEnabled(false);

                    questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo],0,0,1,40,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("1)", this),1,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][0],1,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("2)", this), 1,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][1],1,21,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("3)", this), 2,0,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][2],2,1,1,19,0);
                    questionLayout[qNoInPage-1]->addWidget(new QLabel("4)", this),2,20,1,1,0);
                    questionLayout[qNoInPage-1]->addWidget(rBMcqAnswers[mcqQusrionNo-1][3],2,21,1,19,0);



                }

                //mcqFrames[mcqQusrionNo-1]=new QFrame();
                //mcqFrames[mcqQusrionNo-1]->setLayout(mcqQuestionLayout[mcqQusrionNo-1]);
                if(qNoInPage==1)
                ui->fQuestion1->setLayout(questionLayout[qNoInPage-1]);
                if(qNoInPage==2)
                    ui->fQuestion2->setLayout(questionLayout[qNoInPage-1]);
                if(qNoInPage==3)
                    ui->fQuestion3->setLayout(questionLayout[qNoInPage-1]);
                if(qNoInPage==4)
                    ui->fQuestion4->setLayout(questionLayout[qNoInPage-1]);
                if(qNoInPage==5)
                    ui->fQuestion5->setLayout(questionLayout[qNoInPage-1]);

                qNoInPage++;

                QDomNode StudentAnswer=itemElement.elementsByTagName("StudentAnswer").at(0);

                int mcqQusrionAnswer=StudentAnswer.firstChild().nodeValue().toInt();

                if(mcqQusrionAnswer!=0)
                {
                    rBMcqAnswers[mcqQusrionNo-1][mcqQusrionAnswer-1]->setEnabled(true);
                    rBMcqAnswers[mcqQusrionNo-1][mcqQusrionAnswer-1]->setChecked(true);

                }
                //paperQuestionsLayout->addWidget(mcqFrames[mcqQusrionNo-1],1);
               // paperQuestionsLayout->addWidget(ui->fQuestion1]);






            }
            if(itemNode.toElement().attribute("Type")=="Essay")
            {
                 int questionNo=itemNode.toElement().attribute("QusetionNo").toInt();
                 int EssayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();

                 QDomElement itemElement=itemNode.toElement();
                 QDomNode question=itemElement.elementsByTagName("Question").at(0);
                 qusestionLables[questionNo]=new QLabel(QString::number(questionNo)+")"+question.firstChild().nodeValue());

                 //set marks in lEdit
                 QString marks=itemNode.toElement().attribute("Mark");


                 QDomElement teachermarks=itemNode.toElement();
                 QDomNode teachrmark=itemElement.elementsByTagName("TeacharMarks").at(0);
                 if(qNoInPage==1)
                 {

                     ui->lEAnswer1Marks->setReadOnly(false);
                     ui->lEAnswer1Marks->setHidden(false);
                     if(!marks.isEmpty())
                     {
                          ui->lEAnswer1Marks->setText(marks);
                          PreviousStudentMarks1=marks.toInt();
                     }
                     else
                     {
                         ui->lEAnswer1Marks->setText("");
                         PreviousStudentMarks1=0;

                     }


                     ui->lAnswer1TMark->setText("/"+teachrmark.firstChild().nodeValue());


                 }

                 if(qNoInPage==2)
                 {
                     ui->lEAnswer2Marks->setReadOnly(false);
                     ui->lEAnswer2Marks->setHidden(false);
                     if(!marks.isEmpty())
                     {

                         ui->lEAnswer2Marks->setText(marks);
                         PreviousStudentMarks2=marks.toInt();
                     }
                     else
                     {
                         ui->lEAnswer2Marks->setText("");
                         PreviousStudentMarks2=0;

                     }

                      ui->lAnswer2TMarks->setText("/"+teachrmark.firstChild().nodeValue());


                 }
                 if(qNoInPage==3)
                 {
                     ui->lEAnswer3Marks->setReadOnly(false);
                     ui->lEAnswer3Marks->setHidden(false);
                     if(!marks.isEmpty())
                     {

                         ui->lEAnswer3Marks->setText(marks);
                         PreviousStudentMarks3=marks.toInt();
                     }
                     else
                     {
                         ui->lEAnswer3Marks->setText("");
                         PreviousStudentMarks3=0;

                     }
                      ui->lAnswer3TMarks->setText("/"+teachrmark.firstChild().nodeValue());



                 }
                 if(qNoInPage==4)
                 {
                     ui->lEAnswer4Marks->setReadOnly(false);
                     ui->lEAnswer4Marks->setHidden(false);
                     if(!marks.isEmpty())
                     {
                         ui->lEAnswer4Marks->setText(marks);
                         PreviousStudentMarks4=marks.toInt();
                     }
                     else
                     {
                         ui->lEAnswer4Marks->setText("");
                         PreviousStudentMarks4=0;

                     }
                      ui->lAnswer4TMarks->setText("/"+teachrmark.firstChild().nodeValue());



                 }
                 if(qNoInPage==5)
                 {
                     ui->lEAnswer5Marks->setReadOnly(false);
                     ui->lEAnswer5Marks->setHidden(false);
                     if(!marks.isEmpty())
                     {
                         ui->lEAnswer5Marks->setText(marks);
                         PreviousStudentMarks5=marks.toInt();
                     }
                     else
                     {
                         ui->lEAnswer5Marks->setText("");
                         PreviousStudentMarks5=0;

                     }
                      ui->lAnswer5TMarks->setText("/"+teachrmark.firstChild().nodeValue());



                 }

                 questionLayout[qNoInPage-1]->addWidget(qusestionLables[questionNo]);

                 essayAnswers[EssayQusrionNo-1] = new QTextEdit;
                 questionLayout[qNoInPage-1]->addWidget(essayAnswers[EssayQusrionNo-1]);

                 if(qNoInPage==1)
                 ui->fQuestion1->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==2)
                     ui->fQuestion2->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==3)
                     ui->fQuestion3->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==4)
                     ui->fQuestion4->setLayout(questionLayout[qNoInPage-1]);
                 if(qNoInPage==5)
                     ui->fQuestion5->setLayout(questionLayout[qNoInPage-1]);


                 qNoInPage++;

                 QDomNode StudentAnswer=itemElement.elementsByTagName("StudentAnswer").at(0);

                 QString essayQusrionAnswer=StudentAnswer.firstChild().nodeValue();
                 essayAnswers[EssayQusrionNo-1]->setText(essayQusrionAnswer);
                 essayAnswers[EssayQusrionNo-1]->setReadOnly(true);

            }
        }



    }


    ui->gBQuestions->setLayout(paperQuestionsLayout);


}





void MarkingPapers::saveAnswers()
{
    QFile newPaperFile(paperOpenPath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&newPaperFile);

        QDomElement root= document.firstChildElement();

        QDomNodeList activityItems = root.elementsByTagName("Activity");

        int i=0;
        int j=0;
        if(ui->lPageNo->text().toInt()==1)
        {
            j=5;

        }
        else
        {
            i=(ui->lPageNo->text().toInt()-1)*5;
            j=i+5;
        }

        for (i;i<j;i++)
        {

            QDomNode itemNode = activityItems.at(i);
             if(itemNode.isElement())
             {
                  if(itemNode.toElement().attribute("Type")=="Mcq")
                  {

                      QDomElement itemElement=itemNode.toElement();
                      QDomNode StudentAnswer=itemElement.elementsByTagName("StudentAnswer").at(0);


                      if(!StudentAnswer.isNull())
                      {
                          int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();
                          int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();

                          QDomElement newStudentAnswer = document.createElement(QString("StudentAnswer"));


                          for(int k=0;k<noOfChoises;k++)
                          {

                              if(rBMcqAnswers[mcqQusrionNo-1][k]->isChecked())
                              {

                                  newStudentAnswer.appendChild(document.createTextNode(QString::number(k+1)));

                                  itemNode.replaceChild(newStudentAnswer,StudentAnswer);

                                  break;
                              }

                          }


                      }
                      else
                      {

                          QDomElement newStudentAnswer = document.createElement(QString("StudentAnswer"));

                          int mcqQusrionNo=itemNode.toElement().attribute("McqNo").toInt();
                          int noOfChoises=itemNode.toElement().attribute("NoOfChoises").toInt();


                         for(int m=0;m<noOfChoises;m++)
                         {



                             if(rBMcqAnswers[mcqQusrionNo-1][m]->isChecked())
                             {
                                 newStudentAnswer.appendChild(document.createTextNode(QString::number(m+1)));

                                 itemNode.appendChild(newStudentAnswer);


                                 break;
                             }

                         }

                      }

                  }
                if(itemNode.toElement().attribute("Type")=="Essay")
                  {
                    QDomElement itemElement=itemNode.toElement();
                    QDomNode StudentAnswer=itemElement.elementsByTagName("StudentAnswer").at(0);

                    if(!StudentAnswer.isNull())
                    {
                        QDomElement newStudentAnswer = document.createElement(QString("StudentAnswer"));
                         int essayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();
                         QString answer=essayAnswers[essayQusrionNo-1]->document()->toPlainText();
                        newStudentAnswer.appendChild(document.createTextNode(answer));

                        itemNode.replaceChild(newStudentAnswer,StudentAnswer);


                    }
                    else
                    {
                        QDomElement newStudentAnswer = document.createElement(QString("StudentAnswer"));
                        int essayQusrionNo=itemNode.toElement().attribute("EssayNo").toInt();
                        QString answer=essayAnswers[essayQusrionNo-1]->document()->toPlainText();
                        newStudentAnswer.appendChild(document.createTextNode(answer));

                        itemNode.appendChild(newStudentAnswer);


                    }

                  }


             }

             }

        newPaperFile.close();

        if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QTextStream stream(&newPaperFile);
            stream <<document.toString();
            //qDebug() <<document.toString();
            newPaperFile.close();
        //  QMessageBox::information(this,"Success","Mcq Qustion Added");

       }

        }


}




void MarkingPapers::on_pBPrivious_clicked()
{
    saveEssayMarks();
    ui->lEAnswer1Marks->setHidden(true);
    ui->lEAnswer1Marks->clear();
    ui->lAnswer1TMark->clear();
    ui->lEAnswer2Marks->setHidden(true);
    ui->lEAnswer2Marks->clear();
    ui->lAnswer2TMarks->clear();
    ui->lEAnswer3Marks->setHidden(true);
    ui->lEAnswer3Marks->clear();
    ui->lAnswer3TMarks->clear();
    ui->lEAnswer4Marks->setHidden(true);
    ui->lEAnswer4Marks->clear();
    ui->lAnswer4TMarks->clear();
    ui->lEAnswer5Marks->setHidden(true);
    ui->lEAnswer5Marks->clear();
    ui->lAnswer5TMarks->clear();

    //saveAnswers();
        ui->lPageNo->setText(QString::number(ui->lPageNo->text().toInt()-1));
        if(ui->lPageNo->text().toInt()==1)
        {
            ui->pBPrivious->setEnabled(false);
        }

        ui->pBNext->setEnabled(true);


        toCreatePaperLayout();

}

void MarkingPapers::on_pBNext_clicked()
{
    saveEssayMarks();
    ui->lEAnswer1Marks->setHidden(true);
    ui->lEAnswer1Marks->clear();
    ui->lAnswer1TMark->clear();
    ui->lEAnswer2Marks->setHidden(true);
    ui->lEAnswer2Marks->clear();
    ui->lAnswer2TMarks->clear();
    ui->lEAnswer3Marks->setHidden(true);
    ui->lEAnswer3Marks->clear();
    ui->lAnswer3TMarks->clear();
    ui->lEAnswer4Marks->setHidden(true);
    ui->lEAnswer4Marks->clear();
    ui->lAnswer4TMarks->clear();
    ui->lEAnswer5Marks->setHidden(true);
    ui->lEAnswer5Marks->clear();
    ui->lAnswer5TMarks->clear();

    //saveAnswers();
      ui->lPageNo->setText(QString::number(ui->lPageNo->text().toInt()+1));
      if(totalNoOfQuestions/5==ui->lPageNo->text().toInt())
      {
          if(totalNoOfQuestions%5>0)
          {
          }
          else
          {
              ui->pBNext->setEnabled(false);

          }

      }
      else if(totalNoOfQuestions/5<ui->lPageNo->text().toInt())
      {
          ui->pBNext->setEnabled(false);

      }
      ui->pBPrivious->setEnabled(true);

      toCreatePaperLayout();

}


void MarkingPapers::saveEssayMarks()
{

    QFile newPaperFile(paperOpenPath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&newPaperFile);

        QDomElement root= document.firstChildElement();

        QDomNodeList activityItems = root.elementsByTagName("Activity");

        int i=0;
        int j=0;
        if(ui->lPageNo->text().toInt()==1)
        {
            j=5;

        }
        else
        {
            i=(ui->lPageNo->text().toInt()-1)*5;
            j=i+5;
        }

        int qNoinPage=1;
        for (i;i<j;i++)
        {

            QDomNode itemNode = activityItems.at(i);
             if(itemNode.isElement())
             {

                if(itemNode.toElement().attribute("Type")=="Essay")
                  {
                    QDomElement essayElement=itemNode.toElement();


                     QDomElement newEssayElement=essayElement;
                     if(!newEssayElement.attribute("Mark").isEmpty())
                     {
                         newEssayElement.removeAttribute("Mark");
                         if(qNoinPage==1)
                            newEssayElement.setAttribute("Mark",ui->lEAnswer1Marks->text());
                         if(qNoinPage==2)
                            newEssayElement.setAttribute("Mark",ui->lEAnswer2Marks->text());
                         if(qNoinPage==3)
                             newEssayElement.setAttribute("Mark",ui->lEAnswer3Marks->text());
                         if(qNoinPage==4)
                             newEssayElement.setAttribute("Mark",ui->lEAnswer4Marks->text());
                         if(qNoinPage==5)
                             newEssayElement.setAttribute("Mark",ui->lEAnswer5Marks->text());


                     }
                     else
                     {
                         if(qNoinPage==1)
                            essayElement.setAttribute("Mark",ui->lEAnswer1Marks->text());
                         if(qNoinPage==2)
                            essayElement.setAttribute("Mark",ui->lEAnswer2Marks->text());
                         if(qNoinPage==3)
                             essayElement.setAttribute("Mark",ui->lEAnswer3Marks->text());
                         if(qNoinPage==4)
                             essayElement.setAttribute("Mark",ui->lEAnswer4Marks->text());
                         if(qNoinPage==5)
                             essayElement.setAttribute("Mark",ui->lEAnswer5Marks->text());

                     }

                     if(qNoinPage==1)
                     {
                         totalStudentMarks=QString::number(totalStudentMarks.mid(0,totalStudentMarks.lastIndexOf("/")).toInt()+ui->lEAnswer1Marks->text().toInt()-PreviousStudentMarks1).append(totalStudentMarks.mid(totalStudentMarks.lastIndexOf("/")));
                     }
                     if(qNoinPage==2)
                     {
                         totalStudentMarks=QString::number(totalStudentMarks.mid(0,totalStudentMarks.lastIndexOf("/")).toInt()+ui->lEAnswer2Marks->text().toInt()-PreviousStudentMarks2).append(totalStudentMarks.mid(totalStudentMarks.lastIndexOf("/")));
                     }
                     if(qNoinPage==3)
                     {
                         totalStudentMarks=QString::number(totalStudentMarks.mid(0,totalStudentMarks.lastIndexOf("/")).toInt()+ui->lEAnswer3Marks->text().toInt()-PreviousStudentMarks3).append(totalStudentMarks.mid(totalStudentMarks.lastIndexOf("/")));
                     }
                     if(qNoinPage==4)
                     {
                         totalStudentMarks=QString::number(totalStudentMarks.mid(0,totalStudentMarks.lastIndexOf("/")).toInt()+ui->lEAnswer4Marks->text().toInt()-PreviousStudentMarks4).append(totalStudentMarks.mid(totalStudentMarks.lastIndexOf("/")));
                     }
                     if(qNoinPage==5)
                     {
                         totalStudentMarks=QString::number(totalStudentMarks.mid(0,totalStudentMarks.lastIndexOf("/")).toInt()+ui->lEAnswer5Marks->text().toInt()-PreviousStudentMarks5).append(totalStudentMarks.mid(totalStudentMarks.lastIndexOf("/")));
                     }






                  }

                qNoinPage++;

             }

             }

        newPaperFile.close();

        if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
        {
            qDebug()<<"error";

        }
        else
        {
            QTextStream stream(&newPaperFile);
            stream <<document.toString();
            //qDebug() <<document.toString();
            newPaperFile.close();
        //  QMessageBox::information(this,"Success","Mcq Qustion Added");

       }

        }

    ui->lETotalMarks->setReadOnly(false);
    ui->lETotalMarks->setText(totalStudentMarks);
    ui->lETotalMarks->setReadOnly(true);

}

void MarkingPapers::on_pBSaveMarks_clicked()
{
     saveEssayMarks();

    QFile newPaperFile(paperOpenPath);
    if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";

    }
    else
    {
        QDomDocument document;

        document.setContent(&newPaperFile);
        QDomElement root= document.firstChildElement();

        QDomNodeList items = root.elementsByTagName("Header");

          QDomElement totalmarks= items.at(0).toElement().elementsByTagName("TotalMarks").at(0).toElement();
          QDomElement newTotalmarks=document.createElement("TotalMarks");
          newTotalmarks.appendChild(document.createTextNode(totalStudentMarks));
          items.at(0).toElement().replaceChild(newTotalmarks,totalmarks);




          newPaperFile.close();

          if(!newPaperFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
          {
              qDebug()<<"error";

          }
          else
          {
              QTextStream stream(&newPaperFile);
              stream <<document.toString();
              //qDebug() <<document.toString();
              newPaperFile.close();
          //  QMessageBox::information(this,"Success","Mcq Qustion Added");

         }
          //header.appendChild(subjectnode);
    }

    QString  paperXmlpath=paperOpenPath.mid(0,paperOpenPath.lastIndexOf("/")+1).append("paper.xml");
     qDebug()<<paperOpenPath;


     qDebug()<<paperXmlpath<<studentName<<"dfdddddddddddddd";
    //updating paper.xml
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
                    qDebug()<<studentList.at(i).toElement().attribute("StudentName")<<"dddddddddsssssssssssss";
                    QDomElement newStudent=document.createElement("student");
                    newStudent.setAttribute("StudentName",studentName);
                    newStudent.setAttribute("Marks",totalStudentMarks);
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

    this->close();


}
