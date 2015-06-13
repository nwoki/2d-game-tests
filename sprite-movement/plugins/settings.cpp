#include "playersettings.h"
#include "settings.h"

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class Settings::Private
{
public:
    Private()
        : playerSettings(nullptr)
    {}

    PlayerSettings *playerSettings;
};


Settings::Settings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

Settings::~Settings()
{
    delete d->playerSettings;
    delete d;
}

PlayerSettings* Settings::player() const
{
    return d->playerSettings;
}

void Settings::setPlayer(PlayerSettings *playerSettings)
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
