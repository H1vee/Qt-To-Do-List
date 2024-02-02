#ifndef SECOND_H
#define SECOND_H

#include <QDialog>
#include "addtask.h"
#include "QListWidgetItem"
namespace Ui {
class second;
}

class second : public QDialog
{
    Q_OBJECT

public:
    explicit second(QWidget *parent = nullptr);
    ~second();



public slots:
    void openWindow();
private slots:
    void AddItemClickLabel();
    void ExitItemClickLabel();
    void AddedTaskViewSelectItem();
    void DefaultSelection();
    void AddTaskToListWidget(const QString&TaskName,const QString &TaskDescription,const QDate &DeadLine);
    void DeleteTaskListWidget();
    void UpdateInfoListWidget(QListWidgetItem *item);
private:
    Ui::second *ui;
    AddTask *Task;
protected:
    bool eventFilter(QObject *obj,QEvent *event);
};

#endif // SECOND_H
