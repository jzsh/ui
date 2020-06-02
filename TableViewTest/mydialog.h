#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();
    void resizeEvent(QResizeEvent *event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void auto_adjust_length();
    void printSize();

private:
    Ui::MyDialog *ui;
    QStandardItemModel *m_model;
};

#endif // MYDIALOG_H
