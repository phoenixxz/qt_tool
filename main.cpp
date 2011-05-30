#include <QApplication>
#include "dialog.h"
#include "threadnetrecv.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog dialog;
    return dialog.exec();
}
