#include "core.h"

#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#include <QtQuick/QQuickWindow>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Core core;

    return app.exec();

}
