#include "infotask.h"
#include "ui_infotask.h"

InfoTask::InfoTask(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InfoTask)
{
    ui->setupUi(this);
    Task = new AddTask();
    connect(ui->OKPushButton,&QPushButton::clicked,this,&InfoTask::OKInfoButton);
    connect(Task,&AddTask::FullInfo,this,&InfoTask::SetInfo);
}

InfoTask::~InfoTask()
{
    delete ui;
}

void InfoTask::OKInfoButton(){
    accept();
}

void InfoTask::OpenInfoWindow(){
    this->show();
}

void InfoTask::SetInfo(const QString &TaskName,const QString &TaskDescription,const QDate &DeadLine){
    ui->InfoTaskNameLabel->setText(TaskName);
    ui->InfoTaskDescriptionLabel->setText(TaskDescription);
    ui->InfoDeadLineLabel->setText(DeadLine.toString());
}
