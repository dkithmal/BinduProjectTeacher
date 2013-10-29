#include "newhomework.h"
#include "ui_newhomework.h"

NewHomeWork::NewHomeWork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewHomeWork)
{
    ui->setupUi(this);
    filepath ="D:/dk work/Motarola/Bindu/Administration/GradesAndClassManage/GradesAndClassManage.xml";
    qPaperSavefilepath="D:/dk work/Motarola/Bindu/HomeWorkTool/HomeWork/Papers/";
    setSubjetToTree();
}

NewHomeWork::~NewHomeWork()
{
    delete ui;
}

void NewHomeWork::setSubjetToTree()
{

    //QTreeWidgetItem *item= new QTreeWidgetItem(ui->tWSelectSubject);
    //item->setText(0,"dfdfdfdfdf");
    //ui->tWSelectSubject->addTopLevelItem(item);




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


                QDomNodeList classList= itemNode.toElement().elementsByTagName("Subject");

                    for(int j=0;j<classList.count();j++)
                    {

                        QDomNode itemNodeClass = classList.at(j);
                        // ui->cBSelectClass->addItem(itemNodeClass.toElement().attribute("ClassName"));
                         QTreeWidgetItem *subjectItem= new QTreeWidgetItem(grade);
                         subjectItem->setText(0,itemNodeClass.toElement().attribute("SubjectName"));

                    }




              ui->tWSelectSubject->addTopLevelItem(grade);


            }




       }


   }


}

void NewHomeWork::on_pBCreatePaper_clicked()
{
    int x=0;
//    if(!ui->tWSelectSubject->currentIndex().isValid()||!ui->tWSelectSubject->currentIndex().parent().isValid())
//    {
//        QMessageBox::information(this,"Error","Select Subject");
//        x=1;

//    }

//     if(ui->lEPaperName->text().isEmpty())
//    {
//        QMessageBox::information(this,"Error","Enter Paper Name");
//        x=1;

//    }

//    if(ui->lEDuration->text().isEmpty())
//    {
//        QMessageBox::information(this,"Error","Enter Paper Duration");
//        x=1;

//    }

//    if(!(ui->rBEssay->isChecked()||ui->rBEssayMcq->isChecked()||ui->rBMcq->isChecked()))
//    {
//        QMessageBox::information(this,"Error","Select Paper Type");
//        x=1;

//    }



     if(ui->rBEssayMcq->isChecked()&&x==0)
    {
         //QString filepath ="D:/dk work/Motarola/project/assinment/";
        // filepath.append(ui->fileName->text());
        // filepath.append(".xml");
         QString newqPaperSavefilepath=qPaperSavefilepath;
         newqPaperSavefilepath.append(ui->tWSelectSubject->currentItem()->parent()->text(0));
         newqPaperSavefilepath.append("/");
         newqPaperSavefilepath.append(ui->tWSelectSubject->currentItem()->text(0));
         newqPaperSavefilepath.append("/");
         newqPaperSavefilepath.append(ui->lEPaperName->text());
         newqPaperSavefilepath.append(".xml");



         QFile newPaperFile(newqPaperSavefilepath);
         if(!newPaperFile.open(QFile::Append| QFile::Text))
         {

         }
         else
         {
             QDomDocument document;


             QDomElement root = document.createElement("Question_Paper");


             QDomElement header= document.createElement("Header");


             QDomElement titlenode=document.createElement("Title");
             titlenode.appendChild(document.createTextNode(ui->lEPaperName->text()));
             header.appendChild(titlenode);


             QDomElement subjectnode=document.createElement("Subject");
             subjectnode.appendChild(document.createTextNode(ui->tWSelectSubject->currentItem()->text(0)));
             header.appendChild(subjectnode);

             QDomElement teacherenode=document.createElement("Duration");
             teacherenode.appendChild(document.createTextNode(ui->lEDuration->text()));
             header.appendChild(teacherenode);


             root.appendChild(header);
             document.appendChild(root);
             QTextStream stream(&newPaperFile);
             stream <<document.toString();
             newPaperFile.close();
             //wait for write file




         }




         newMixPaper = new NewMixPaper(0,newqPaperSavefilepath);
         newMixPaper->show();

        // this->close();
    }





}
