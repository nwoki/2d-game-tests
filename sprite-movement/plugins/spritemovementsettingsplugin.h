#ifndef SPRITEMOVEMENTSETTINGS_SPRITEMOVEMENTSETTINGSPLUGIN_H
#define SPRITEMOVEMENTSETTINGS_SPRITEMOVEMENTSETTINGSPLUGIN_H

#include <QtQml/QQmlExtensionPlugin>


namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class SpriteMovementSettingsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

}

}

}

#endif  // SPRITEMOVEMENTSETTINGS_SPRITEMOVEMENTSETTINGSPLUGIN_H
