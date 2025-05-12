#include "invetario.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Invetario w;
    w.show();
    return a.exec();
}
