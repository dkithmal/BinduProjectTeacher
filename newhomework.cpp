#include "newhomework.h"
#include "ui_newhomework.h"

NewHomeWork::NewHomeWork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewHomeWork)
{
    ui->setupUi(this);
}

NewHomeWork::~NewHomeWork()
{
    delete ui;
}
