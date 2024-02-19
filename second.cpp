#include "second.h"
#include "ui_second.h"
#include "addtask.h"
#include<QMouseEvent>
second::second(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::second)
{
    ui->setupUi(this);
    ui->DeletePushButton->setVisible(false);
    ui->EditPushButton->setVisible(false);
    ui->TaskDescriptionLabel->setVisible(false);
    ui->DeadLineLabel->setVisible(false);
    ui->InfoDeadLineLabel->setVisible(false);
    ui->InfoTaskDescriptionLabel->setVisible(false);
    ui->InfoListWidget->setVisible(false);
    installEventFilter(this);
    Task = new AddTask();
    connect(ui->ExitPushButton,&QPushButton::clicked,this,&second::ExitItemClickLabel);
    connect(ui->AddPushButton,&QPushButton::clicked,this,&second::AddItemClickLabel);
    connect(ui->ToDolistWidget,&QListWidget::itemClicked,this,&second::AddedTaskViewSelectItem);
    connect(ui->ToDolistWidget, &QListWidget::itemClicked, this, &second::UpdateInfoListWidget);
    connect(Task,&AddTask::taskAdded,this,&second::AddTaskToListWidget);
    connect(ui->DeletePushButton,&QPushButton::clicked,this,&second::DeleteTaskListWidget);
    connect(this,&second::TaskDeleted,Task,&AddTask::deleteTask);
}

second::~second()
{
    delete ui;
    delete Task;
}




void second::openWindow(){
    this->show();
}

void second::ExitItemClickLabel(){
    QApplication::quit();
}

void second::AddItemClickLabel(){
    Task->show();
}


struct TaskInfo{
    QString Description;
    QDate DeadLine;
};


std::map<QString,TaskInfo>taskInfoMap;

void second::AddTaskToListWidget(const QString&TaskName,const QString &TaskDescription,const QDate &DeadLine){
    QListWidgetItem *newItem = new QListWidgetItem(TaskName);
    QFont font("Times New Roman",15);
    newItem->setFont(font);
    newItem->setTextAlignment(Qt::AlignCenter);
    newItem->setData(Qt::ForegroundRole,QBrush(Qt::lightGray));
    ui->ToDolistWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->ToDolistWidget->addItem(newItem);
    // ui->InfoDeadLineLabel->setText(DeadLine.toString("dd-MM-yyyy"));
    // ui->InfoTaskDescriptionLabel->setText(TaskDescription);
    // ui->InfoTaskNameLabel->setText(TaskName);
    taskInfoMap[TaskName]={TaskDescription,DeadLine};

}

void second::DeleteTaskListWidget(){

    QListWidgetItem *item = ui->ToDolistWidget->currentItem();
    if(item){
        QString TaskName = item->text();
        ui->InfoTaskDescriptionLabel->clear();
        ui->InfoDeadLineLabel->clear();
        taskInfoMap.erase(TaskName);
        emit TaskDeleted(TaskName);
        delete item;
        DefaultSelection();
    }
}

void second::AddedTaskViewSelectItem(){
    ui->EditPushButton->setVisible(true);
    ui->DeletePushButton->setVisible(true);
    ui->InfoDeadLineLabel->setVisible(true);
    ui->InfoTaskDescriptionLabel->setVisible(true);
    ui->InfoListWidget->setVisible(true);
    ui->TaskDescriptionLabel->setVisible(true);
    ui->DeadLineLabel->setVisible(true);

}
void second::UpdateInfoListWidget(QListWidgetItem *item){
    if(item){
        QString TaskName = item->text();
        TaskInfo& taskInfo = taskInfoMap[TaskName];

        ui->InfoTaskDescriptionLabel->setText(taskInfo.Description);
        ui->InfoDeadLineLabel->setText(taskInfo.DeadLine.toString("dd-MM-yyyy"));
    }else{
        ui->InfoTaskDescriptionLabel->clear();
        ui->InfoDeadLineLabel->clear();
    }
}

void second::DefaultSelection(){
    ui->EditPushButton->setVisible(false);
    ui->DeletePushButton->setVisible(false);
    ui->TaskDescriptionLabel->setVisible(false);
    ui->DeadLineLabel->setVisible(false);
    ui->InfoDeadLineLabel->setVisible(false);
    ui->InfoTaskDescriptionLabel->setVisible(false);
    ui->InfoListWidget->setVisible(false);
}



bool second::eventFilter(QObject *obj,QEvent *event){
    if(obj==this&&event->type()==QEvent::MouseButtonPress){
        if(!ui->ToDolistWidget->underMouse()){
            DefaultSelection();
        }
    }
    return QObject::eventFilter(obj,event);

}
