#include "QueryStuDlg.h"
#include "ui_QueryStuDlg.h"
QueryStuDlg::QueryStuDlg(QWidget *parent) :
QDialog(parent),
    ui(new Ui::QueryStuDlg)
{
    ui->setupUi(this);
}
QueryStuDlg::~QueryStuDlg()
{
    delete ui;
}
