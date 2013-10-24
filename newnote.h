#ifndef NEWNOTE_H
#define NEWNOTE_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>



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
    
private:
    Ui::NewNote *ui;
};

#endif // NEWNOTE_H
