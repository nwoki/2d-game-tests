#ifndef SPRITEMOVEMENTSETTINGS_MAP_H
#define SPRITEMOVEMENTSETTINGS_MAP_H

#include <QtCore/QObject>
#include <QtCore/QRect>

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class Map : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Map)

    Q_PROPERTY(int height       READ height     WRITE setHeight)
    Q_PROPERTY(QString name     READ name       WRITE setName)
    Q_PROPERTY(int tileHeight   READ tileHeight WRITE setTileHeight)
    Q_PROPERTY(int tileWidth    READ tileWidth  WRITE setTileWidth)
    Q_PROPERTY(int width        READ width      WRITE setWidth)

public:
    Map(QObject *parent = 0);
    ~Map();

    /** @return list of collision boxes present on the map */
    QList<QRect> collisionBoxes() const;

    /** @return map height intended as number of tiles */
    int height() const;

    /** @return name of the map */
    QString name() const;

    /** @return height of a single map tile */
    int tileHeight() const;

    /** @return width of a single map tile */
    int tileWidth() const;

    /** @return map width intended as number of tiles */
    int width() const;

    void setHeight(int height);
    void setName(const QString &name);
    void setTileHeight(int tileHeight);
    void setTileWidth(int tileWidth);
    void setWidth(int width);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTINGS_MAP_H
