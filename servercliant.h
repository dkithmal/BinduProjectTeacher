#ifndef SERVERCLIANT_H
#define SERVERCLIANT_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QNetworkInterface>

class ServerCliant : public QObject
{
    Q_OBJECT
public:
    explicit ServerCliant(QObject *parent = 0);
    QTcpSocket *socket;
    void test(QString command,QString filePath,QString studentList,QString iPAddress);
    void toHaddleUploadDone(QByteArray Arg);
    void  toExicuteTeacherCommand(QString command ,QString filePath,QString studentList,QString iPAddress);
    int DownloadStrted;
    QString downloadFilePath;
    QString studentList;
    QString ipAddress;
    QString filePath;
    QString studentName;


private:
    QByteArray mCommandBuffer;
    QString CCommand; //!teacher sent details about download or upload
    QString fileNameOrPath;     //!teacher send command argument if upload filpath if download filename

    void ProcessCommand(QByteArray clientCommand);
    void ExecuteCommand(QByteArray clientCommand);
    void ToDownload();
    void DoDownload(QByteArray Arg);
    void DoNewDownload(QByteArray Arg);
    void ToUpload();
    void DoINIT(QByteArray Arg);
    QFile *newfile;

signals:
    void FileSent(const QString& studentName);
    void FileRecived(const QString& studentName);

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void bytesWritten(qint64 bytes);


};

#endif // SERVERCLIANT_H
