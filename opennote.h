#ifndef OPENNOTE_H
#define OPENNOTE_H

#include <QtWidgets>
#include <QString>
#include <QFile>
#include <QtXml>
#include <QDebug>
#include <QMessageBox>
#include "editnote.h"

namespace Ui {
class OpenNote;
}

class OpenNote : public QWidget
{
    Q_OBJECT
    
public:
    explicit OpenNote(QWidget *parent = 0);
    ~OpenNote();
    QString filepath;
    QString basicPath;
    void setSubjetToTree();
    EditNote *editNote;
    
private slots:
    void on_pBOpen_clicked();

    void on_tWSelectSubject_clicked(const QModelIndex &index);

private:
    Ui::OpenNote *ui;
};

#endif // OPENNOTE_H
