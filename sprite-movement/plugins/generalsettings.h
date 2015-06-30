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
    Q_PROPERTY(int viewHeight                                                           READ viewHeight WRITE setViewHeight)
    Q_PROPERTY(int viewWidth                                                            READ viewWidth  WRITE setViewWidth)

public:
    GeneralSettings(QObject *parent = 0);
    ~GeneralSettings();

    Map* map(int index);
    Q_INVOKABLE Nwoki::Qml::SpriteMovementSettings::Map* map(const QString &mapName);
    QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Map> maps();
    int mapCount() const;
    Nwoki::Qml::SpriteMovementSettings::PlayerSettings* player() const;
    QString startMap() const;
    int viewHeight() const;
    int viewWidth() const;

    void setPlayer(Nwoki::Qml::SpriteMovementSettings::PlayerSettings *playerSettings);
    void setStartMap(const QString &startMap);
    void setViewHeight(int viewHeight);
    void setViewWidth(int viewWidth);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTING_GENERALSETTINGS_H
