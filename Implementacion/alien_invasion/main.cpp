#include "control_usuario.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    control_usuario wind;
    //MainWindow w;
    //w.show();
    wind.show();

    return a.exec();
}


