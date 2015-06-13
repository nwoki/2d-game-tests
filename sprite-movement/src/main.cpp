#include "applicationview.h"

#include <QtGui/QGuiApplication>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    ApplicationView appView("qrc:///qml/main.qml");

    return app.exec();

}
