#include "addStuDlg.h"
#include "ui_addStuDlg.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>

addStuDlg::addStuDlg(QWidget *parent) :
QDialog(parent),
    ui(new Ui::addStuDlg)
{
    ui->setupUi(this);

	// connect signal and slot
	connect(ui->OkBtn, SIGNAL(clicked()), this, SLOT(slotOkBtnClicked()));
	connect(ui->CancelBtn, SIGNAL(clicked()), this, SLOT(slotCancelClicked()));

	// init
	for(int i=1; i<100; i++) {
		ui->cbbAge->addItem(QString::number(i));
	}
	ui->cbbAge->setCurrentIndex(20);

	ui->cbbDepat->addItem("Auot College");
	ui->cbbDepat->addItem("Electronic College");
	ui->cbbDepat->addItem("Computer College");
}

addStuDlg::~addStuDlg()
{
    delete ui;
}

void addStuDlg::slotOkBtnClicked()
{
	qDebug() << "ok clicked";
    QString name=ui->leName->text();
    QString id=ui->leID->text();
    QString gender=ui->btnGrpGender->checkedButton()->text();
    QString age=ui->cbbAge->currentText();
    QString dev=ui->cbbDepat->currentText();
    QList<QAbstractButton*> ins_list=ui->btnGrpHobbies->buttons();
    QString ins;
    for(int i=0;i<ins_list.length();i++)
    {
        QAbstractButton* che=ins_list[i];
        if(che->isChecked())
        {
            ins+=che->text()+" ";
        }
    }

    QString content=name+'\n'+id+'\n'+gender+'\n'+age+'\n'+dev+'\n'+ins;
    QString cnt=name+" "+id+" "+gender+" "+age+" "+dev+" "+ins+'\n';
    if(name.length()<1||id.length()<10||ins.length()<1){
        QMessageBox::critical(this,"Error","Imcomplete infomation, please rewrite","Comfirm");
    }else{
        int ret=QMessageBox::information(this,"Please comfirm",content,"OK","Cancel");
        if(0==ret)
        {
			qDebug() << "writeToFile";
//             clearUserInterface();
            writeToFile(cnt);
        }
    }
}


void addStuDlg::slotCancelClicked()
{
    this->close();
}

void addStuDlg::writeToFile(QString cnt)
{
	QFile file("stu.txt");
	if(!file.open(QIODevice::Append|QIODevice::Text))
	{
		QMessageBox::critical(this,"错误","文件打开失败,请检查权限！");
		return;
	}
	QTextStream out(&file);
	out<<cnt;
	file.close();
}

