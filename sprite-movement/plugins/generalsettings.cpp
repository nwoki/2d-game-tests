#include "playersettings.h"
#include "generalsettings.h"

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

    class GeneralSettings::Private
{
public:
    Private()
        : playerSettings(nullptr)
    {}

    PlayerSettings *playerSettings;
};


GeneralSettings::GeneralSettings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

GeneralSettings::~GeneralSettings()
{
    delete d->playerSettings;
    delete d;
}

PlayerSettings* GeneralSettings::player() const
{
    return d->playerSettings;
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
