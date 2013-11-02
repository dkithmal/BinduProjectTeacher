#ifndef UPLOADMANAGE_H
#define UPLOADMANAGE_H

#include <QWidget>
#include <QDialog>
#include "servercliant.h"

namespace Ui {
class UploadManage;
}

class UploadManage : public QDialog
{
    Q_OBJECT
    
public:
    explicit UploadManage(QDialog *parent = 0,QString command=NULL ,QString filePath=NULL,QString studentList=NULL);
    ~UploadManage();
    void uploadingfiles(QString command ,QString filePath,QString studentList);

    ServerCliant *cliant;

protected slots:
    void OnFileSent(const QString& studentName);
    
private:
    Ui::UploadManage *ui;
};

#endif // UPLOADMANAGE_H
