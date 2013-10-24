#ifndef HOMEWORKTOOL_H
#define HOMEWORKTOOL_H

#include <QWidget>

namespace Ui {
class HomeWorkTool;
}

class HomeWorkTool : public QWidget
{
    Q_OBJECT
    
public:
    explicit HomeWorkTool(QWidget *parent = 0);
    ~HomeWorkTool();
    
private:
    Ui::HomeWorkTool *ui;
};

#endif // HOMEWORKTOOL_H
