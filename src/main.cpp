#include "cryptography.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cryptography w;
    w.show();

    return a.exec();
}
