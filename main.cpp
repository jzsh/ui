#include "stopwatchmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StopWatchMainWindow w;
    w.show();

    return a.exec();
}
