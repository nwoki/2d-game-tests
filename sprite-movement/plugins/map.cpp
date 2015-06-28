#include "map.h"
#include "../generated/auxconfig.h"
#include "mapparsers/tiledjsonparser.h"


namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class Map::Private
{
public:
    Private()
        : height(0)
        , tileHeight(0)
        , tileWidth(0)
        , width(0)
        , tiledJsonParser(new TiledJsonParser)
    {}

    QList<QRect> collisionBoxes;
    int height;                         // number of tiles for the "Y" axis
    QString name;                       // map name
    QRect playerStartBox;
    int tileHeight;                     // pixel height of the tiles
    int tileWidth;                      // pixel width of the tiles
    int width;                          // number of tiles for the "X" axis

    TiledJsonParser *tiledJsonParser;
};


Map::Map(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
    connect(d->tiledJsonParser, &TiledJsonParser::collisionObjects, [this] (const QList<QRect> &collisionObjects) {
        d->collisionBoxes = collisionObjects;
    });

    connect(d->tiledJsonParser, &TiledJsonParser::playerStartObject, [this] (const QRect &playerStartObject) {
        d->playerStartBox = playerStartObject;
        Q_EMIT playerStartChanged();
    });
}

Map::~Map()
{
    delete d->tiledJsonParser;
    delete d;
}

QList<QRect> Map::collisionBoxes() const
{
    return d->collisionBoxes;
}

int Map::height() const
{
    return d->height;
}

QString Map::name() const
{
    return d->name;
}

int Map::playerStartX() const
{
    return d->playerStartBox.x();
}

int Map::playerStartY() const
{
    return d->playerStartBox.y();
}

void Map::setHeight(int height)
{
    d->height = height;
}

void Map::setName(const QString &name)
{
    d->name = name;

    // parse the collision objects necessary for the map
    d->tiledJsonParser->parseObjects(MAPS_DIR + d->name + "/" + d->name + ".json");
}

void Map::setPlayerStartX(int x)
{
    d->playerStartBox.setX(x);
}

void Map::setPlayerStartY(int y)
{
    d->playerStartBox.setY(y);
}

void Map::setTileHeight(int tileHeight)
{
    d->tileHeight = tileHeight;
}

void Map::setTileWidth(int tileWidth)
{
    d->tileWidth = tileWidth;
}

void Map::setWidth(int width)
{
    d->width = width;
}

int Map::tileHeight() const
{
    return d->tileHeight;
}

int Map::tileWidth() const
{
    return d->tileWidth;
}

int Map::width() const
{
    return d->width;
}

}

}

}
