#include "testcontrollerwindow.h"
#include "testpreviewwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestControllerWindow w;
    w.show();

    return a.exec();
}
