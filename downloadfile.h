#ifndef DOWNLOADFILE_H
#define DOWNLOADFILE_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "downloadmanage.h"
namespace Ui {
class DownloadFile;
}

class DownloadFile : public QWidget
{
    Q_OBJECT
    
public:
    explicit DownloadFile(QWidget *parent = 0);
    ~DownloadFile();
    void setFileList();
    void setClassList();
    QString getSelectedClassStudents();
    QString filepath;
    QString basicPath;
    QString Otherfilepath;
    DownloadManage *downloadManage;
    
private slots:
    void on_tWSelectClass_clicked(const QModelIndex &index);

    void on_pBDownload_clicked();

private:
    Ui::DownloadFile *ui;
};

#endif // DOWNLOADFILE_H
