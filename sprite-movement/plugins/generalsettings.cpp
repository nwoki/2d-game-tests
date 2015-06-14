#include "mapsettings.h"
#include "playersettings.h"
#include "generalsettings.h"

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class GeneralSettings::Private
{
public:
    Private()
        : mapSettings(nullptr)
        , playerSettings(nullptr)
    {}

    MapSettings *mapSettings;
    PlayerSettings *playerSettings;
};


GeneralSettings::GeneralSettings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

GeneralSettings::~GeneralSettings()
{
    delete d->mapSettings;
    delete d->playerSettings;
    delete d;
}

MapSettings *GeneralSettings::map() const
{
    return d->mapSettings;
}

PlayerSettings *GeneralSettings::player() const
{
    return d->playerSettings;
}

void GeneralSettings::setMap(MapSettings *mapSettings)
{
    if (d->mapSettings != nullptr) {
        delete d->mapSettings;
        d->mapSettings = nullptr;
    }

    d->mapSettings = mapSettings;
}

void GeneralSettings::setPlayer(PlayerSettings *playerSettings)
{
    if (d->playerSettings != nullptr) {
        delete d->playerSettings;
        d->playerSettings = nullptr;
    }

    d->playerSettings = playerSettings;
}

}

}

}
