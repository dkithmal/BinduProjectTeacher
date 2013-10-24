#include "newmixpaper.h"
#include "ui_newmixpaper.h"

NewMixPaper::NewMixPaper(QWidget *parent,QString filePath) :
    QWidget(parent),
    ui(new Ui::NewMixPaper)
{
    ui->setupUi(this);
    paperCrationPath=filePath;

    ui->cBNoOfChoises->setCurrentIndex(0);
    on_cBNoOfChoises_currentIndexChanged(0);


    qustionNo = 0;
    mcqNo=0;
    essayNO=0;
}

NewMixPaper::~NewMixPaper()
{
    delete ui;
}

void NewMixPaper::on_cBNoOfChoises_currentIndexChanged(int index)
{
    if(index==0)
    {
        ui->lAnswer1->setEnabled(true);
        ui->lAnswer2->setEnabled(true);
        ui->lAnswer3->setEnabled(false);
        ui->lAnswer4->setEnabled(false);

        ui->lEAnswer1->setEnabled(true);
        ui->lEAnswer2->setEnabled(true);
        ui->lEAnswer3->setEnabled(false);
        ui->lEAnswer4->setEnabled(false);
    }
    if(index==1)
    {
        ui->lAnswer1->setEnabled(true);
        ui->lAnswer2->setEnabled(true);
        ui->lAnswer3->setEnabled(true);
        ui->lAnswer4->setEnabled(false);

        ui->lEAnswer1->setEnabled(true);
        ui->lEAnswer2->setEnabled(true);
        ui->lEAnswer3->setEnabled(true);
        ui->lEAnswer4->setEnabled(false);

    }
    if(index==2)
    {
        ui->lAnswer1->setEnabled(true);
        ui->lAnswer2->setEnabled(true);
        ui->lAnswer3->setEnabled(true);
        ui->lAnswer4->setEnabled(true);

        ui->lEAnswer1->setEnabled(true);
        ui->lEAnswer2->setEnabled(true);
        ui->lEAnswer3->setEnabled(true);
        ui->lEAnswer4->setEnabled(true);

    }


}

void NewMixPaper::on_pBAddMcq_clicked()
{
    int x=0;

    if(ui->cBNoOfChoises->currentText().toInt()==2)
    {
        if(ui->lEAnswer1->text().isEmpty()||ui->lEAnswer2->text().isEmpty())
        {
            QMessageBox::information(this,"Error","Please Enter All answers");
            x=1;

        }


    }
    if(ui->cBNoOfChoises->currentText().toInt()==3)
    {
        if(ui->lEAnswer1->text().isEmpty()||ui->lEAnswer2->text().isEmpty()||ui->lEAnswer3->text().isEmpty())
        {
            QMessageBox::information(this,"Error","Please Enter All answers");
            x=1;

        }


    }
    if(ui->cBNoOfChoises->currentText().toInt()==4)
    {
        if(ui->lEAnswer1->text().isEmpty()||ui->lEAnswer2->text().isEmpty()||ui->lEAnswer3->text().isEmpty()||ui->lEAnswer4->text().isEmpty())
        {
            QMessageBox::information(this,"Error","Please Enter All answers");
            x=1;

        }


    }



    if(ui->lEMcqQuestion->text().isEmpty())
    {
        QMessageBox::information(this,"Error","Please Enter Question");
        x=1;

    }







// start create paper xml
    if(x==0)
    {
        QFile newPaperFile(paperCrationPath);
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

              QDomElement Activity= document.createElement("Activity");
              Activity.setAttribute("Type","Mcq");
              qustionNo++;
              Activity.setAttribute("QusetionNo",qustionNo);
              mcqNo++;
              Activity.setAttribute("McqNo",mcqNo);
              Activity.setAttribute("NoOfChoises",ui->cBNoOfChoises->currentText().toInt());

               QDomElement Question= document.createElement("Question");
               Question.appendChild(document.createTextNode(ui->lEMcqQuestion->text()));
               Activity.appendChild(Question);

               for(int x=1;x<=ui->cBNoOfChoises->currentText().toInt();x++)
               {
                   QDomElement choice= document.createElement("Choice");
                   if(x==1)
                   choice.appendChild(document.createTextNode(ui->lEAnswer1->text()));
                   if(x==2)
                       choice.appendChild(document.createTextNode(ui->lEAnswer2->text()));
                   if(x==3)
                       choice.appendChild(document.createTextNode(ui->lEAnswer3->text()));
                   if(x==4)
                      choice.appendChild(document.createTextNode(ui->lEAnswer4->text()));

                   Activity.appendChild(choice);
               }



                root.appendChild(Activity);
                document.appendChild(root);

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
                  QMessageBox::information(this,"Success","Mcq Qustion Added");

                  ui->lEAnswer1->clear();
                  ui->lEAnswer2->clear();
                  ui->lEAnswer3->clear();
                  ui->lEAnswer4->clear();

                  ui->lEMcqQuestion->clear();


                }

        }

    }



}

void NewMixPaper::on_pBAddEssayQuestion_clicked()
{
    if(ui->lEEssayQuestion->text().isEmpty())
    {
       QMessageBox::information(this,"Error","Please Enter Question");
    }
    else
    {


        //crateing new qustion on xml
        QFile newPaperFile(paperCrationPath);
        if(!newPaperFile.open(QFile::ReadWrite| QIODevice::Text))
        {
            qDebug()<<"error";

        }

        QDomDocument document;

        document.setContent(&newPaperFile);

        QDomElement root= document.firstChildElement();

          QDomElement Activity= document.createElement("Activity");
          Activity.setAttribute("Type","Essay");
          qustionNo++;
          Activity.setAttribute("QusetionNo",qustionNo);
          essayNO++;
          Activity.setAttribute("EssayNo",essayNO);


          QDomElement Question= document.createElement("Question");
          Question.appendChild(document.createTextNode(ui->lEEssayQuestion->text()));
          Activity.appendChild(Question);


          root.appendChild(Activity);
          document.appendChild(root);

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
              QMessageBox::information(this,"Success","Eassy Qustion Added");

              ui->lEEssayQuestion->clear();

          }

    }



}
