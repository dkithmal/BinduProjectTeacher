#include "newuploadordownload.h"
#include "ui_newuploadordownload.h"

NewUploadOrDownload::NewUploadOrDownload(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::NewUploadOrDownload)
{
    ui->setupUi(this);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    // this->setStyleSheet( "background-color: rgba(0,0,0, 70%); color:Azure;");
   // this->setWindowOpacity(0.45);
    //this->setAttribute(Qt::WA_TranslucentBackground);

//set button icons
    QPixmap uploadButtonImg(":/binduTeacher/new/imgs/upload.jpg");

    QIcon uploadButtonIcon(uploadButtonImg);
    ui->pBUpload->setIcon(uploadButtonIcon);
    QSize upBsize=uploadButtonImg.rect().size();
    upBsize.setHeight(upBsize.height()-50);
    upBsize.setWidth(upBsize.width()-50);
    ui->pBUpload->setIconSize(upBsize);

    QPixmap downloadButtonImg(":/binduTeacher/new/imgs/download.jpg");

    QIcon downloadButtonIcon(downloadButtonImg);
    ui->pBDownload->setIcon(downloadButtonIcon);
    QSize downBsize=uploadButtonImg.rect().size();
    downBsize.setHeight(downBsize.height()-50);
    downBsize.setWidth(downBsize.width()-50);
    ui->pBDownload->setIconSize(downBsize);
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
