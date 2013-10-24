#include "openhomework.h"
#include "ui_openhomework.h"

OpenHomeWork::OpenHomeWork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpenHomeWork)
{
    ui->setupUi(this);
}

OpenHomeWork::~OpenHomeWork()
{
    delete ui;
}
