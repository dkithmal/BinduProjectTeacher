#include "newnote.h"
#include "ui_newnote.h"

NewNote::NewNote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
}

NewNote::~NewNote()
{
    delete ui;
}
