#include <QApplication>
#include <QFontDatabase>

#include "mainwindow.h"

int main(int argc, char *argv[])
{

    QPalette palette;
    palette.setColor(QPalette::Active, QPalette::Base, QColor("white"));
    palette.setColor(QPalette::Active, QPalette::Dark, QColor("black"));

    QFont font;
    font.setFamily("Roboto");
    font.setPixelSize(14);

    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/font/Roboto-Bold.ttf");
    QFontDatabase::addApplicationFont(":/font/Roboto-Regular.ttf");

    a.setPalette(palette);
    a.setFont(font);

    MainWindow w;
    w.show();
    return a.exec();
}

