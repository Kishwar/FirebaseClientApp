#include "wlogin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    wlogin w;
    w.show();
    return a.exec();
}
