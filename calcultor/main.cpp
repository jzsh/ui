#include <QApplication>
#include "MyDialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDialog q;
    q.show();

    return a.exec();
}

