#include "downloadmanage.h"
#include "ui_downloadmanage.h"

DownloadManage::DownloadManage(QDialog *parent,QString command ,QString filePath,QString studentList) :
    QDialog(parent),
    ui(new Ui::DownloadManage)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

    downloadLocationPath=filePath;
    basicPath="D:/dk work/Motarola/Bindu New/Teacher/";
    downloadingfiles(command,filePath,studentList);



}

DownloadManage::~DownloadManage()
{
    delete ui;
}


void DownloadManage::downloadingfiles(QString command ,QString filePath,QString studentList)
{
    QStringList studentSplitedList=studentList.split(",");
    int i=0;
    ui->tWDownlodingtate->setRowCount(studentSplitedList.size());
    foreach (QString student, studentSplitedList)
    {
        ui->tWDownlodingtate->setItem(i,0,new QTableWidgetItem(student));
        ui->tWDownlodingtate->setItem(i,1,new QTableWidgetItem("Pending"));

        i++;
    }

    qDebug()<<command<<"command";
    qDebug()<<filePath<<"filePath";
    qDebug()<<studentList<<"studentList";
    cliant = new ServerCliant;
    cliant->toExicuteTeacherCommand(command,filePath,studentList,"192.168.1.2");

     connect(cliant, SIGNAL(FileRecived(QString)), this, SLOT(OnFileRecived(QString)));

}


void DownloadManage::OnFileRecived(const QString & studentName)
{
    DownloadedStudentNameList.append(studentName);
    for(int i=0;i<ui->tWDownlodingtate->rowCount();i++)
    {
        if(ui->tWDownlodingtate->item(i,0)->text()==studentName)
        {
            ui->tWDownlodingtate->setItem(i,0,new QTableWidgetItem(studentName));
            ui->tWDownlodingtate->setItem(i,1,new QTableWidgetItem("Done"));
        }
    }

    //ui->lWRecivedStudentList->addItem(studentName);

}


void DownloadManage::on_pBDownloadClose_clicked()
{
    QStringList filePathInfo=downloadLocationPath.split("/");
    QString paperName=filePathInfo.at(filePathInfo.size()-2);
    QString subject=filePathInfo.at(filePathInfo.size()-3);
    QString className=filePathInfo.at(filePathInfo.size()-4);
    QString grade=filePathInfo.at(filePathInfo.size()-5);

     QString creatingQPaperXmlPath=basicPath;
     creatingQPaperXmlPath.append("Answers/");
     creatingQPaperXmlPath.append(grade);
     creatingQPaperXmlPath.append("/");
     creatingQPaperXmlPath.append(className);
     creatingQPaperXmlPath.append("/");
     creatingQPaperXmlPath.append(subject);
     creatingQPaperXmlPath.append("/");
     creatingQPaperXmlPath.append(paperName);
     creatingQPaperXmlPath.append("/paper.xml");


    QString creatingQuestionPaperPath=basicPath;
    creatingQuestionPaperPath.append("HomeWork/");
    creatingQuestionPaperPath.append(grade);
    creatingQuestionPaperPath.append("/");
    creatingQuestionPaperPath.append(subject);
    creatingQuestionPaperPath.append("/");
    creatingQuestionPaperPath.append(paperName);
    creatingQuestionPaperPath.append(".xml");


    QString type=getPaperType(creatingQuestionPaperPath);

  // qDebug()<<paperName<<" "<<subject<<" "<<className<<" "<<grade;

   //creating paper.xml
    QFile newPaperXmlFile(creatingQPaperXmlPath);
    if(newPaperXmlFile.size()==0)
    {
        if(!newPaperXmlFile.open(QFile::Append| QFile::Text))
        {

        }
        else
        {
           QDomDocument document;

           QDomElement root = document.createElement("paper");
           QDomElement header= document.createElement("Header");

            header.setAttribute("PaperName",paperName);
            header.setAttribute("type",type);
            header.setAttribute("Grade",grade);
            header.setAttribute("class",className);
            header.setAttribute("subject",subject);
            //header.setAttribute("PaperName");

            for(int k=0;k<DownloadedStudentNameList.size();k++)
            {
                QDomElement student=document.createElement("student");
                student.setAttribute("StudentName",DownloadedStudentNameList.at(k));
                student.setAttribute("Marks","");
                student.setAttribute("MarkState","NotMark");
                //student.appendChild(document.createTextNode(DownloadedStudentNameList.at(k)));
                root.appendChild(student);
            }

            root.appendChild(header);
            document.appendChild(root);
            QTextStream stream(&newPaperXmlFile);
            stream <<document.toString();
            newPaperXmlFile.close();
            //wait for write file


        }

    }
    else
    {
        QDomDocument document;
        QDomElement root;

        document.setContent(&newPaperXmlFile);
        root= document.firstChildElement();


        QDomNodeList studentList = root.elementsByTagName("student");

        int k=0;
        foreach (QString studnet, DownloadedStudentNameList)
        {
            int x=0;
            for(int i=0;i<studentList.count();i++)
            {


                QDomNode itemNode = studentList.at(i);
                if(itemNode.toElement().attribute("StudentName")==studnet)
                x=1;
            }

            if(x==0)
            {
                QDomElement student=document.createElement("student");
                student.setAttribute("StudentName",DownloadedStudentNameList.at(k));
                student.setAttribute("Marks","");
                student.setAttribute("MarkState","NotMark");
                root.appendChild(student);
            }
            k++;

        }


    document.appendChild(root);
    newPaperXmlFile.close();

    if(!newPaperXmlFile.open(QFile::ReadWrite|QIODevice::Truncate | QIODevice::Text))
    {

    }
    else
    {
        QTextStream stream(&newPaperXmlFile);
        stream <<document.toString();
        newPaperXmlFile.close();

    }

  }




}

QString DownloadManage::getPaperType(QString paperfilepath)
{
    QFile openConfigFile(paperfilepath);
    if(!openConfigFile.open(QFile::ReadWrite| QIODevice::Text))
    {
        qDebug()<<"error";
        return "";

    }
    else
    {
        QDomDocument document;

        document.setContent(&openConfigFile);
        QDomElement root= document.firstChildElement();


        QDomNodeList items = root.elementsByTagName("Header");

          QDomNode itemNode = items.at(0);
          QDomElement itemElement=itemNode.toElement();

          QDomNode type=itemElement.elementsByTagName("Type").at(0);

          return type.firstChild().nodeValue();





   }

}
