#ifndef SPRITEMOVEMENTSETTING_SETTINGS_H
#define SPRITEMOVEMENTSETTING_SETTINGS_H

#include <QtCore/QObject>


namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class PlayerSettings;

class Settings : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Settings)

    Q_PROPERTY(Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player       READ player     WRITE setPlayer)

public:
    Settings(QObject *parent = 0);
    ~Settings();

    Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player() const;
    void setPlayer(Nwoki::Qml::SpriteMovementSettings::PlayerSettings *playerSettings);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTING_SETTINGS_H
