#ifndef OPENNOTE_H
#define OPENNOTE_H

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "editnote.h"

namespace Ui {
class OpenNote;
}

class OpenNote : public QDialog
{
    Q_OBJECT
    
public:
    explicit OpenNote(QDialog *parent = 0);
    ~OpenNote();
    QString filepath;
    QString basicPath;
    void setSubjetToTree();
    EditNote *editNote;
    
private slots:
    void on_pBOpen_clicked();

    void on_tWSelectSubject_clicked(const QModelIndex &index);

    void on_pBDeleteNote_clicked();

private:
    Ui::OpenNote *ui;
};

#endif // OPENNOTE_H
