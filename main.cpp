#include "board.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Board s;
    s.show();
    return a.exec();
}
