#ifndef INFOTASK_H
#define INFOTASK_H

#include <QDialog>
#include "QDate"
#include "addtask.h"
namespace Ui {
class InfoTask;
}

class InfoTask : public QDialog
{
    Q_OBJECT

public:
    explicit InfoTask(QWidget *parent = nullptr);
    ~InfoTask();



public slots:
    void OpenInfoWindow();
private slots:
     void SetInfo(const QString &TaskName,const QString &TaskDescription,const QDate &DeadLine);
     void OKInfoButton();


private:
    Ui::InfoTask *ui;
    AddTask* Task;

};

#endif // INFOTASK_H
