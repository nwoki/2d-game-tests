#include "../../generated/auxconfig.h"
#include "map.h"
#include "mapsettings.h"
#include "mapparsers/tiledjsonparser.h"

#include <QtCore/QDebug>
#include <QtCore/QRect>

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {


class MapSettings::Private
{
public:
    Private()
        : tiledJsonParser(new TiledJsonParser)
    {}

    QHash<QString, Map*> maps;
    TiledJsonParser *tiledJsonParser;
};


MapSettings::MapSettings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

MapSettings::~MapSettings()
{
    qDeleteAll(d->maps);
    d->maps.clear();

    delete d->tiledJsonParser;
    delete d;
}

Map* MapSettings::map(const QString &mapName)
{
    return d->maps.value(mapName, nullptr);
}


// void MapSettings::setName(const QString &name)
// {
//     d->name = name;
//
//     // parse as soon as we load a new map
//     // NOTE when this becomes bigger and I'll need a list of maps for various levels etc, I think this might be a good idea
//     // to move the parsing out so that I can call it on demand
//     d->collisionBoxes = d->tiledJsonParser->parseObjects(MAPS_DIR
//                                                         + d->name
//                                                         + "/" + d->name + ".json");
//
//     qDebug() << "I have : " << d->collisionBoxes.count() << " collision boxes";
// }

}

}

}
