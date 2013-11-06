#ifndef NEWNOTE_H
#define NEWNOTE_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "newnotecreating.h"



namespace Ui {
class NewNote;
}

class NewNote : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewNote(QDialog *parent = 0);
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
