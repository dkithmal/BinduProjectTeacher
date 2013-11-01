#ifndef UPLOADMANAGE_H
#define UPLOADMANAGE_H

#include <QWidget>
#include "servercliant.h"

namespace Ui {
class UploadManage;
}

class UploadManage : public QWidget
{
    Q_OBJECT
    
public:
    explicit UploadManage(QWidget *parent = 0,QString command=NULL ,QString filePath=NULL,QString studentList=NULL);
    ~UploadManage();
    void uploadingfiles(QString command ,QString filePath,QString studentList);

    ServerCliant *cliant;
    
private:
    Ui::UploadManage *ui;
};

#endif // UPLOADMANAGE_H
