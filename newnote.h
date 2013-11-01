#ifndef NEWNOTE_H
#define NEWNOTE_H

#include <QtWidgets>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "newnotecreating.h"



namespace Ui {
class NewNote;
}

class NewNote : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewNote(QWidget *parent = 0);
    ~NewNote();
    void setSubjetToTree();
    QString filepath;
    QString basicPath;
    NewNoteCreating *newNoteCreating;
    
private slots:
    void on_pBCreateNote_clicked();

private:
    Ui::NewNote *ui;
};

#endif // NEWNOTE_H
