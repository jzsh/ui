#ifndef MyDialog_H
#define MyDialog_H
#include <QDialog>
#include "model.h"

namespace Ui {
class MyDialog;
};

class MyDialog : public QDialog
{
	Q_OBJECT

public:
	explicit MyDialog(QWidget *parent = 0);
	~MyDialog();
private slots:
private slots:
    void getBtn0();
    void getBtn1();
    void getBtn2();
    void getBtn3();
    void getBtn4();
    void getBtn5();
    void getBtn6();
    void getBtn7();
    void getBtn8();
    void getBtn9();

    void on_btn_clear_clicked();
    void on_btn_plus_clicked();
    void on_btn_sub_clicked();
    void on_btn_mul_clicked();
    void on_btn_div_clicked();
    void on_btn_equal_clicked();

private:
	Ui::MyDialog *ui;
	model* mode;
	QString tmp;
};

#endif
