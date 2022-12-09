#include "mainwindow.h"
#include "loginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow mw;
//    mw.show();
    LoginWindow lw;
    lw.show();
    return a.exec();
}
