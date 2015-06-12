#include "core.h"

#include <QtQml/QQmlApplicationEngine>


class Core::Private
{
public:
    Private() {};

    QQmlApplicationEngine *engine;
};


Core::Core(QQmlApplicationEngine *engine)
    : d(new Private)
{
    d->engine = engine;

    // start the GUI
    d->engine->load(QUrl("qrc:///qml/main.qml"));
}

Core::~Core()
{
    delete d;
}
