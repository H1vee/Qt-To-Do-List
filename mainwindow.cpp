#include "mainwindow.h"
#include"second.h"
#include "./ui_mainwindow.h"
#include "QLineEdit"
#include "QString"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    secondWindow = new second();
    connect(ui->AuthorisationButton,&QPushButton::clicked,this,&MainWindow::AuthorisationCheckButtonClick);
    connect(ui->ShowPassBox,&QCheckBox::clicked,this,&MainWindow::ShowPasswordCheckBoxClick);
    connect(this,&MainWindow::AuthorisationSuccessful,secondWindow,&second::openWindow);
    ui->PasswordEdit->setEchoMode(QLineEdit::Password);


}

MainWindow::~MainWindow()
{
    delete ui;
    delete secondWindow;
}

bool MainWindow::AuthorisationCheckButtonClick(){
    QMessageBox messageBox;
    QString login= ui->LoginEdit->text();
    QString password = ui->PasswordEdit->text();
    if(login=="admin"&&password=="admin123"){
        messageBox.information(this,"Authorisation successful","Authorisation has been successful");
        emit AuthorisationSuccessful();
        return true;
    }else{
        messageBox.critical(this,"Authorisation failed","Authorisation has been failed");
    }
    return false;
}
void MainWindow::ShowPasswordCheckBoxClick(bool checked){
    if(checked){
        ui->PasswordEdit->setEchoMode(QLineEdit::Normal);
    }else{
        ui->PasswordEdit->setEchoMode(QLineEdit::Password);
    }
}



