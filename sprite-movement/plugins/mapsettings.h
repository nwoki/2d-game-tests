#ifndef SPRITEMOVEMENTSETTINGS_MAPSETTINGS_H
#define SPRITEMOVEMENTSETTINGS_MAPSETTINGS_H


#include <QtCore/QObject>

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {


class MapSettings : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name     READ name       WRITE   setName)

public:
    MapSettings(QObject *parent = 0);
    ~MapSettings();

    QString name() const;
    void setName(const QString &name);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTINGS_MAPSETTINGS_H
