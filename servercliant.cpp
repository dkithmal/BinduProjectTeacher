#include "servercliant.h"

ServerCliant::ServerCliant(QObject *parent) :
    QObject(parent)
{
}


//command argument like Upload Subject/type/fileName or Download Subject/answer/filename
//in the upload server create folders in subject name and type then save the file
//in download spceify the subject and file name to get file
//file path menas download or upload filepath
//studentList student list in classs
void  ServerCliant::toExicuteTeacherCommand(QString command ,QString filePath,QString studentList,QString iPAddress)
{
    test(command,filePath,studentList,iPAddress);

}
void ServerCliant::test(QString command ,QString filePath,QString studentList,QString iPAddress)
{
    this->ipAddress=iPAddress;
    this->studentList=studentList;
    this->filePath=filePath;
    DownloadStrted=0;
    downloadFilePath ="E:/dk work/Motarola/project/teacher/";


    int pos = command.indexOf(" ");
    CCommand = command.mid(0,pos).trimmed();
    //file name or path like Subject/type/FileName
    fileNameOrPath = command.mid(pos + 1).trimmed();



    socket = new QTcpSocket(this);

    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(bytesWritten(qint64 )),this,SLOT(bytesWritten(qint64 )));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));


    qDebug()<<"conneting...";

    socket->connectToHost(ipAddress                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         ,1234);
    if(!socket->waitForConnected(5000))
    {
        qDebug()<<"Error:"<<socket->errorString();
    }


}


void ServerCliant::connected()
{
    qDebug()<<"connected to Server";
    QString init="INIT Start \n";
    socket->write(init.toLatin1());
    socket->waitForBytesWritten(5000);
    qDebug() << "Client Command:"<<init.toLatin1();
}

void ServerCliant::disconnected()
{

    qDebug()<<"Server disconnected";
}


void ServerCliant::readyRead()
{
    if(DownloadStrted==0)
    {
        mCommandBuffer.append(socket->readAll());
        if(mCommandBuffer.endsWith('\n'))
        {
            ProcessCommand(mCommandBuffer);
            mCommandBuffer.clear();
        }


    }
    else
    {

        DoDownload(socket->readAll());


    }


}

void ServerCliant::bytesWritten(qint64 bytes)
{
    qDebug()<<bytes<<" client written";

}


void ServerCliant::ProcessCommand(QByteArray clientCommand)
{
    ExecuteCommand(clientCommand);


}

void ServerCliant::ExecuteCommand(QByteArray clientCommand)
{
    try
    {
        QByteArray Command = "";
        QByteArray Arg = "";

        if(clientCommand.contains(" "))
        {
            //Contains arquments
            int pos = clientCommand.indexOf(" ");
            Command = clientCommand.mid(0,pos).trimmed();
            Arg = clientCommand.mid(pos + 1);
        }
        else
        {
            //No arquments
            Command = clientCommand.trimmed();
        }

        qDebug() << "ServerReplay: " << Command ;


        if(Command=="INIT")
        {
            DoINIT(Arg.trimmed());

        }
        else if(Command=="DOWNSTART")
        {
            DoNewDownload(Arg);
        }
        else if(Command=="DownloadDone")
        {
            toHaddleUploadDone(Arg);

        }





    }
    catch(QString error)
    {
        //SendResponse(550,err);
    }
    catch(...)
    {
        //SendResponse(550,"Unknown error in ExecuteCommand()");
    }
}

void ServerCliant::DoINIT(QByteArray Arg)
{


 QStringList studentNameList=studentList.split(",");

 int x=0;
    foreach (QString student, studentNameList)
    {
        if(student==Arg)
        {
            // to speciy download from student or not
            studentName=student;
            qDebug()<<" Success: student match";
            x=1;

            if(CCommand=="Download")
            {
                ToDownload();
                break;


            }
            if(CCommand=="Upload")
            {

                ToUpload();
                break;

            }

        }

    }
    if(x==0)
    {
         emit socket->disconnectFromHost();

    }



}



void ServerCliant::ToDownload()
{

    socket->write("DOWN "+fileNameOrPath.append("\n").toLatin1());
    qDebug()<<"Client Command:" <<"DOWN "+fileNameOrPath;

}


void ServerCliant::ToUpload()
{

    //QString filename=fileNameOrPath.mid(fileNameOrPath.lastIndexOf("/")+1).trimmed();

    QString startUpload="START ";
    startUpload.append(fileNameOrPath);
    startUpload.append("FNEnd");

    socket->write(startUpload.toLatin1());

    qDebug()<<"Client Command:" <<startUpload;

    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    while (!file.atEnd())
    {
        QByteArray buffer = file.read(1024 * 8);
        socket->write(buffer);
        socket->waitForBytesWritten(5000);
    }
    file.close();
    socket->write("End\n");
    socket->waitForBytesWritten(500);
    qDebug()<<"Client Command: Finish Upload" ;

}
void ServerCliant::DoNewDownload(QByteArray Arg)
{
    QByteArray fileName = "";
    QByteArray File = "";

    if(Arg.contains("FNEnd"))
    {
        //Contains arquments
        int pos = Arg.indexOf("FNEnd",0);
        fileName = Arg.mid(0,pos).trimmed();
        File = Arg.mid(pos + 5);

    }


    //QString filepath=downloadFilePath;
    //filepath.append(fileName);
    filePath.append(fileName);

    newfile= new QFile(filePath);
    if(newfile->exists())
    {
        newfile->remove();

    }
    if(!newfile->open(QIODevice::Append))
    {

        qDebug()<<"error";
    }
    else
    {
        if(File.endsWith("End\n"))
        {
            qDebug()<<"Download Started";

            newfile->write(File.mid(0,(File.length()-4)));
            newfile->close();
            DownloadStrted=0;

            qDebug()<<"Download Done";
            //to acknolge to app
            emit socket->disconnectFromHost();
            emit this->FileRecived(studentName);
        }
        else {
            qDebug()<<"Download Started";

            newfile->write(File);
            DownloadStrted=1;
        }




    }


}

void ServerCliant::DoDownload(QByteArray Arg)
{
    if(Arg.endsWith("End\n"))
    {
        qDebug()<<Arg;
        newfile->write(Arg.mid(0,(Arg.length()-4)));
        newfile->close();
        DownloadStrted =0;

        qDebug()<<"Download Done";
        emit socket->disconnectFromHost();

        //to acknoladgement
        emit this->FileRecived(studentName);
    }
    else
    {
        newfile->write(Arg);

    }

}

void ServerCliant::toHaddleUploadDone(QByteArray Arg)
{
    //Arg is student name
    qDebug()<<QString::fromUtf8(Arg.trimmed().data(), Arg.trimmed().size())<<"Server Downloaded file";
    emit socket->disconnectFromHost();
   // ayya code
    emit this->FileSent(QString::fromUtf8(Arg.trimmed().data(), Arg.trimmed().size()));
}
