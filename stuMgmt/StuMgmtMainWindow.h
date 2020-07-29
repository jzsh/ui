#ifndef StuMgmtMainWindow_H
#define StuMgmtMainWindow_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class StuMgmtMainWindow;
};

class StuMgmtMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StuMgmtMainWindow(QWidget *parent = 0);
    ~StuMgmtMainWindow();

private slots:
	void slotAddStudent();

private:
    Ui::StuMgmtMainWindow *ui;
};

#endif
