#ifndef QueryStuDlg_H
#define QueryStuDlg_H

#include <QDialog>

namespace Ui {
	class QueryStuDlg;
};

class QueryStuDlg : public QDialog
{
    Q_OBJECT

public:
    explicit QueryStuDlg(QWidget *parent = 0);
    ~QueryStuDlg();
private slots:

private:
    Ui::QueryStuDlg *ui;
};

#endif
