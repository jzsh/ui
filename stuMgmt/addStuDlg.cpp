#include "addStuDlg.h"
#include "ui_addStuDlg.h"
addStuDlg::addStuDlg(QWidget *parent) :
QDialog(parent),
    ui(new Ui::addStuDlg)
{
    ui->setupUi(this);
}
addStuDlg::~addStuDlg()
{
    delete ui;
}
