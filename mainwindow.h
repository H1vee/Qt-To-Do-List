#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"second.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void AuthorisationSuccessful();
private slots:
    bool AuthorisationCheckButtonClick();
    void ShowPasswordCheckBoxClick(bool checked);


private:
    Ui::MainWindow *ui;
    second* secondWindow;
};
#endif // MAINWINDOW_H
