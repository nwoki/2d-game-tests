#ifndef SPRITEMOVEMENTSETTING_GENERALSETTINGS_H
#define SPRITEMOVEMENTSETTING_GENERALSETTINGS_H

#include <QtCore/QObject>

#include <QtQml/QQmlListProperty>

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class Level;
class PlayerSettings;

class GeneralSettings : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(GeneralSettings)

    Q_PROPERTY(QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Level> levels       READ levels)
    Q_PROPERTY(Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player               READ player     WRITE setPlayer)
    Q_PROPERTY(QString startLevel                                                       READ startLevel WRITE setStartLevel)

public:
    GeneralSettings(QObject *parent = 0);
    ~GeneralSettings();

    Level* level(int index);
    QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Level> levels();
    int levelCount() const;
    Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player() const;
    QString startLevel() const;
    void setPlayer(Nwoki::Qml::SpriteMovementSettings::PlayerSettings *playerSettings);
    void setStartLevel(const QString &startLevel);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTING_GENERALSETTINGS_H
