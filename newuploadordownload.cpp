#include "newuploadordownload.h"
#include "ui_newuploadordownload.h"

NewUploadOrDownload::NewUploadOrDownload(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::NewUploadOrDownload)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
}

NewUploadOrDownload::~NewUploadOrDownload()
{
    delete ui;
}

void NewUploadOrDownload::on_pBUpload_clicked()
{
    uploadFile = new UploadFile;
    uploadFile->setModal(false);
    this->close();
    uploadFile->exec();

}

void NewUploadOrDownload::on_pBDownload_clicked()
{
    downloadFile = new DownloadFile;
    downloadFile->setModal(false);
    this->close();
    downloadFile->exec();


}
