#ifndef STOPWATCHMAINWINDOW_H
#define STOPWATCHMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class StopWatchMainWindow;
}

class StopWatchMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StopWatchMainWindow(QWidget *parent = 0);
    ~StopWatchMainWindow();

private:
    Ui::StopWatchMainWindow *ui;
};

#endif // STOPWATCHMAINWINDOW_H
