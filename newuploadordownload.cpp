#include "newuploadordownload.h"
#include "ui_newuploadordownload.h"

NewUploadOrDownload::NewUploadOrDownload(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewUploadOrDownload)
{
    ui->setupUi(this);
}

NewUploadOrDownload::~NewUploadOrDownload()
{
    delete ui;
}

void NewUploadOrDownload::on_pBUpload_clicked()
{
    uploadFile = new UploadFile;
    uploadFile->show();

}

void NewUploadOrDownload::on_pBDownload_clicked()
{
    downloadFile = new DownloadFile;
    downloadFile->show();
}
