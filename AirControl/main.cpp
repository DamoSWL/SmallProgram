#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setFixedSize(640,800);
    w.setWindowTitle(QString(u8"空调控制器"));
    w.show();

    return a.exec();
}
