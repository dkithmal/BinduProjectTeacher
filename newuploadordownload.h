#ifndef NEWUPLOADORDOWNLOAD_H
#define NEWUPLOADORDOWNLOAD_H

#include <QWidget>
#include "uploadfile.h"
#include "downloadfile.h"

namespace Ui {
class NewUploadOrDownload;
}

class NewUploadOrDownload : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewUploadOrDownload(QWidget *parent = 0);
    ~NewUploadOrDownload();
    UploadFile *uploadFile;
    DownloadFile *downloadFile;
    
private slots:
    void on_pBUpload_clicked();

    void on_pBDownload_clicked();

private:
    Ui::NewUploadOrDownload *ui;
};

#endif // NEWUPLOADORDOWNLOAD_H
