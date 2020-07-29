#include <QApplication>
#include "StuMgmtMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StuMgmtMainWindow w;
    w.show();
    return a.exec();
}
