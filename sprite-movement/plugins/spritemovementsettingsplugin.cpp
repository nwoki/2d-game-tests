#include "playersettings.h"
#include "generalsettings.h"
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
    qmlRegisterType<PlayerSettings>(uri, versionMajor, versionMinor, "PlayerSettings");
}

};

}

}
