#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->btnLogin, SIGNAL(clicked(bool)), this, SLOT(login()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login()
{
    static int count = 0;
    QString name = this->ui->leAccount->text();
    QString passwd = this->ui->lePassword->text();

    if(name == "jack" && passwd == "1234") {
        qDebug() << "Login successfully";
    } else {
        qDebug() << "Login failed";
        count++;
        if(count >= 3) {
            disconnect(this->ui->btnLogin, SIGNAL(clicked(bool)),this,SLOT(login()));
        }
    }
}

// 有什么控件、这些控件可以发出什么信号
// 信号与槽机制
// 槽函数

// 第二种方式：通过ui文件的"转到槽", 可以不用显性的定义connect()
void MainWindow::on_btnCancel_clicked()
{
    this->close();
}

void MainWindow::on_leAccount_textChanged(const QString &arg1)
{
    qDebug() << "text changed";
}

