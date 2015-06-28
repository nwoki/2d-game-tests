#ifndef SPRITEMOVEMENTSETTING_GENERALSETTINGS_H
#define SPRITEMOVEMENTSETTING_GENERALSETTINGS_H

#include <QtCore/QObject>

#include <QtQml/QQmlListProperty>

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class Map;
class PlayerSettings;

class GeneralSettings : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(GeneralSettings)

    Q_PROPERTY(QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Map> maps           READ maps)
    Q_PROPERTY(Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player               READ player     WRITE setPlayer)
    Q_PROPERTY(QString startMap                                                         READ startMap   WRITE setStartMap)

public:
    GeneralSettings(QObject *parent = 0);
    ~GeneralSettings();

    Map* map(int index);
    QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Map> maps();
    int mapCount() const;
    Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player() const;
    QString startMap() const;
    void setPlayer(Nwoki::Qml::SpriteMovementSettings::PlayerSettings *playerSettings);
    void setStartMap(const QString &startMap);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTING_GENERALSETTINGS_H
