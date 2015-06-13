#include "applicationview.h"
#include "core.h"

#include <QtQml/QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include <QtQuickWidgets/QQuickWidget>


class Core::Private
{
public:
    Private()
        : appView(new ApplicationView("qrc:///qml/main.qml", nullptr))
    {}

    ApplicationView *appView;
};


Core::Core()
    : d(new Private)
{
}

Core::~Core()
{
    d->appView->close();

    delete d->appView;
    delete d;
}
