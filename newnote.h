#ifndef NEWNOTE_H
#define NEWNOTE_H

#include <QWidget>

namespace Ui {
class NewNote;
}

class NewNote : public QWidget
{
    Q_OBJECT
    
public:
    explicit NewNote(QWidget *parent = 0);
    ~NewNote();
    
private:
    Ui::NewNote *ui;
};

#endif // NEWNOTE_H
