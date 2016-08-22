#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName("VNICTT");
    a.setApplicationName("StrangSplitting");

    MainWindow w;
    w.show();

    return a.exec();
}
