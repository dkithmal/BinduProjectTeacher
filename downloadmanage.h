#ifndef DOWNLOADMANAGE_H
#define DOWNLOADMANAGE_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QtXml>
#include "servercliant.h"
namespace Ui {
class DownloadManage;
}

class DownloadManage : public QDialog
{
    Q_OBJECT
    
public:
    explicit DownloadManage(QDialog *parent = 0,QString command=NULL ,QString filePath=NULL,QString studentList=NULL);
    ~DownloadManage();
    void downloadingfiles(QString command ,QString filePath,QString studentList);
    ServerCliant *cliant;
    QStringList DownloadedStudentNameList;
    QString downloadLocationPath;
    QString basicPath;
    QString getPaperType(QString paperfilepath);
protected slots:
    void OnFileRecived(const QString& studentName);
    
private slots:
    void on_pBDownloadClose_clicked();

private:
    Ui::DownloadManage *ui;
};

#endif // DOWNLOADMANAGE_H
