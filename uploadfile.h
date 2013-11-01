#ifndef UPLOADFILE_H
#define UPLOADFILE_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "uploadmanage.h"

namespace Ui {
class UploadFile;
}

class UploadFile : public QWidget
{
    Q_OBJECT
    
public:
    explicit UploadFile(QWidget *parent = 0);
    ~UploadFile();
    void setFileList();
    void setClassList();
    QString getSelectedClassStudents();
    QString getSelecteHomeWorkType();

    QString filepath;
    QString basicFilepath;
    QString Otherfilepath;

    UploadManage  *uploadManage;
    
private slots:
    void on_rBSelectHomeWork_clicked();

    void on_rBSelectOtherFile_clicked();

    void on_pushButton_3_clicked();

    void on_pBUpload_clicked();

    void on_tWSelectClass_clicked(const QModelIndex &index);

private:
    Ui::UploadFile *ui;
};

#endif // UPLOADFILE_H