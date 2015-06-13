#ifndef SPRITEMOVEMENTSETTING_GENERALSETTINGS_H
#define SPRITEMOVEMENTSETTING_GENERALSETTINGS_H

#include <QtCore/QObject>


namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class PlayerSettings;

class GeneralSettings : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(GeneralSettings)

    Q_PROPERTY(Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player       READ player     WRITE setPlayer)

public:
    GeneralSettings(QObject *parent = 0);
    ~GeneralSettings();

    Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player() const;
    void setPlayer(Nwoki::Qml::SpriteMovementSettings::PlayerSettings *playerSettings);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTING_GENERALSETTINGS_H
