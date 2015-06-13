#include "playersettings.h"
#include "settings.h"
#include "spritemovementsettingsplugin.h"

#include <QtQml/QQmlComponent>


namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

void SpriteMovementSettingsPlugin::registerTypes(const char* uri)
{
    int versionMajor = 0;
    int versionMinor = 1;

    // register types used for the application settings
    qmlRegisterType<PlayerSettings>(uri, versionMajor, versionMinor, "PlayerSettings");
    qmlRegisterType<Settings>(uri, versionMajor, versionMinor, "Settings");
}

};

}

}
