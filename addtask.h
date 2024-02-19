#ifndef ADDTASK_H
#define ADDTASK_H
#include"QString"
#include <QDialog>
#include "QDateEdit"

namespace Ui {
class AddTask;
}

struct TaskInfoForCheck{
    QString TaskDesc;
    QDate deadLine;
};

class AddTask : public QDialog
{
    Q_OBJECT

public:
    explicit AddTask(QWidget *parent = nullptr);
    ~AddTask();
public slots:
    QString getTaskName();
    QString getTaskDescription();
    QDate   getDeadLine();
    void deleteTask(const QString &TaskName);

signals:
    void taskAdded(const QString &TaskName,const QString &TaskDescription,const QDate &DeadLine);
private slots:
    void OKButtonClick();
    void AddTaskToMap(const QString &TaskName,const QString &TaskDescription,const QDate& DeadLine);
private:
    Ui::AddTask *ui;
    std::map<QString,TaskInfoForCheck>TaskMap;

};

#endif // ADDTASK_H
