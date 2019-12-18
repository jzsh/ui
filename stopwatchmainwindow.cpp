#include "stopwatchmainwindow.h"
#include "ui_stopwatchmainwindow.h"

StopWatchMainWindow::StopWatchMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StopWatchMainWindow)
{
    ui->setupUi(this);
}

StopWatchMainWindow::~StopWatchMainWindow()
{
    delete ui;
}
