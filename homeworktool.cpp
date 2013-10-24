#include "homeworktool.h"
#include "ui_homeworktool.h"

HomeWorkTool::HomeWorkTool(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeWorkTool)
{
    ui->setupUi(this);
}

HomeWorkTool::~HomeWorkTool()
{
    delete ui;
}
