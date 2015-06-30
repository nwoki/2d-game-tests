#include "generalsettings.h"
#include "level.h"
#include "map.h"
#include "playersettings.h"
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
    qmlRegisterType<GeneralSettings>(uri, versionMajor, versionMinor, "Settings");
    qmlRegisterType<Map>(uri, versionMajor, versionMinor, "Map");
    qmlRegisterType<PlayerSettings>(uri, versionMajor, versionMinor, "PlayerSettings");
}

};

}

}
