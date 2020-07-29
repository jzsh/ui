#include "StuMgmtMainWindow.h"
#include "ui_StuMgmtMainWindow.h"
#include "addStuDlg.h"

StuMgmtMainWindow::StuMgmtMainWindow(QWidget *parent) :
QMainWindow(parent),
    ui(new Ui::StuMgmtMainWindow)
{
    ui->setupUi(this);

	// connect action
	connect(ui->actionAdd_Student, SIGNAL(triggered()), this, SLOT(slotAddStudent()) );
}
StuMgmtMainWindow::~StuMgmtMainWindow()
{
    delete ui;
}

void StuMgmtMainWindow::slotAddStudent()
{
	qDebug() << "add stu";
	addStuDlg addStuDlg;
	addStuDlg.exec();
}
