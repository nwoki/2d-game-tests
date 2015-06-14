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

    QString name;
    QList<QRect> collisionBoxes;
    TiledJsonParser *tiledJsonParser;
};


MapSettings::MapSettings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

MapSettings::~MapSettings()
{
    delete d->tiledJsonParser;
    delete d;
}

QString MapSettings::name() const
{
    return d->name;
}

void MapSettings::setName(const QString &name)
{
    d->name = name;

    // parse as soon as we load a new map
    // NOTE when this becomes bigger and I'll need a list of maps for various levels etc, I think this might be a good idea
    // to move the parsing out so that I can call it on demand
    d->collisionBoxes = d->tiledJsonParser->parseObjects("/home/nwoki/GitProjects/Github/2d-game-tests/sprite-movement/assets/sprites/maps/greenmap/greenmap.json");
    qDebug() << "I have : " << d->collisionBoxes.count() << " collision boxes";
}

}

}

}
