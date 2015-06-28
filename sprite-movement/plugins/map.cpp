#include "map.h"

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
    {}

    QList<QRect> collisionBoxes;
    int height;                         // number of tiles for the "Y" axis
    QString name;                       // map name
    int tileHeight;                     // pixel height of the tiles
    int tileWidth;                      // pixel width of the tiles
    int width;                          // number of tiles for the "X" axis
};


Map::Map(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

Map::~Map()
{
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

void Map::setHeight(int height)
{
    d->height = height;
}

void Map::setName(const QString &name)
{
    d->name = name;
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
