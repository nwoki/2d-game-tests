#include "generalsettings.h"
#include "map.h"
#include "playersettings.h"

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class GeneralSettings::Private
{
public:
    Private()
        : playerSettings(nullptr)
        , viewHeight(480)
        , viewWidth(480)
    {}

    QList<Map*> maps;
    PlayerSettings *playerSettings;
    QString startMap;
    int viewHeight;
    int viewWidth;
};


GeneralSettings::GeneralSettings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

GeneralSettings::~GeneralSettings()
{
    qDeleteAll(d->maps);
    d->maps.clear();

    delete d->playerSettings;
    delete d;
}

Map* GeneralSettings::map(int index)
{
    if (index > d->maps.count() || index < 0) {
        return nullptr;
    } else {
        return d->maps.at(index);
    }
}

Map* GeneralSettings::map(const QString &mapName)
{
    if (mapName.isEmpty()) {
        return nullptr;
    }

    Map *found = nullptr;

    for (Map *m : d->maps) {
        if (m->name() == mapName) {
            found = m;
            break;
        }
    }

    return found;
}

QQmlListProperty<Map> GeneralSettings::maps()
{
    // in case i use it via QML (should never need it as the file is intended for c++ use ONLY)
    return QQmlListProperty<Map>(this , 0
                                // Append function
                                , [] (QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Map> *property, Map *value) -> void {
                                    GeneralSettings *gs = qobject_cast<GeneralSettings*>(property->object);
                                    if (value) {
                                        gs->d->maps.append(value);
                                    }
                                }
                                // Count function
                                , [] (QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Map> *property) -> int {
                                    return qobject_cast<GeneralSettings*>(property->object)->d->maps.count();
                                }
                                // At function
                                , [] (QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Map> *property, int index) -> Map* {
                                    return qobject_cast<GeneralSettings*>(property->object)->d->maps.at(index);
                                }
                                // Clear function
                                , [] (QQmlListProperty<Map> *property) {
                                    GeneralSettings *gs = qobject_cast<GeneralSettings*>(property->object);
                                    qDeleteAll(gs->d->maps);
                                    gs->d->maps.clear();
                                }
                            );
}

int GeneralSettings::mapCount() const
{
    return d->maps.count();
}

PlayerSettings *GeneralSettings::player() const
{
    return d->playerSettings;
}

void GeneralSettings::setStartMap(const QString &startMap)
{
    d->startMap = startMap;
}

void GeneralSettings::setPlayer(PlayerSettings *playerSettings)
{
    if (d->playerSettings != nullptr) {
        delete d->playerSettings;
        d->playerSettings = nullptr;
    }

    d->playerSettings = playerSettings;
}

void GeneralSettings::setViewHeight(int viewHeight)
{
    d->viewHeight = viewHeight;
}

void GeneralSettings::setViewWidth(int viewWidth)
{
    d->viewWidth = viewWidth;
}

QString GeneralSettings::startMap() const
{
    return d->startMap;
}

int GeneralSettings::viewHeight() const
{
    return d->viewHeight;
}

int GeneralSettings::viewWidth() const
{
    return d->viewWidth;
}

}

}

}
