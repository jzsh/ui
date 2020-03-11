
#include <QApplication>
#include "addStuDlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    addStuDlg m;
    m.show();
    return a.exec();
}
