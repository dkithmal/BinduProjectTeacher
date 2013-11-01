#ifndef DOWNLOADMANAGE_H
#define DOWNLOADMANAGE_H

#include <QWidget>
#include <QDebug>
#include "servercliant.h"
namespace Ui {
class DownloadManage;
}

class DownloadManage : public QWidget
{
    Q_OBJECT
    
public:
    explicit DownloadManage(QWidget *parent = 0,QString command=NULL ,QString filePath=NULL,QString studentList=NULL);
    ~DownloadManage();
    void downloadingfiles(QString command ,QString filePath,QString studentList);
    ServerCliant *cliant;
protected slots:
    void OnFileRecived(const QString& studentName);
    
private:
    Ui::DownloadManage *ui;
};

#endif // DOWNLOADMANAGE_H
