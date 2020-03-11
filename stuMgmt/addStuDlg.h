#ifndef addStuDlg_H
#define addStuDlg_H
#include <QDialog>
namespace Ui {
class addStuDlg;
};

class addStuDlg : public QDialog
{
    Q_OBJECT

public:
    explicit addStuDlg(QWidget *parent = 0);
    ~addStuDlg();
private slots:

private:
    Ui::addStuDlg *ui;
};

#endif