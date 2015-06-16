#ifndef SPRITEMOVEMENTSETTINGS_MAPSETTINGS_H
#define SPRITEMOVEMENTSETTINGS_MAPSETTINGS_H


#include <QtCore/QObject>


namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {


class Map;

class MapSettings : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MapSettings)


public:
    MapSettings(QObject *parent = 0);
    ~MapSettings();

    Map* map(const QString &mapName);

//     void setName(const QString &name);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTINGS_MAPSETTINGS_H
