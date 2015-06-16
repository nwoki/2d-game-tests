#include "level.h"
#include "playersettings.h"
#include "generalsettings.h"

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class GeneralSettings::Private
{
public:
    Private()
        : playerSettings(nullptr)
    {}

    QList<Level*> levels;
    PlayerSettings *playerSettings;
    QString startLevel;
};


GeneralSettings::GeneralSettings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

GeneralSettings::~GeneralSettings()
{
    qDeleteAll(d->levels);
    d->levels.clear();

    delete d->playerSettings;
    delete d;
}

Level* GeneralSettings::level(int index)
{
    if (index > d->levels.count() || index < 0) {
        return nullptr;
    } else {
        return d->levels.at(index);
    }
}

QQmlListProperty<Level> GeneralSettings::levels()
{
    // in case i use it via QML (should never need it as the file is intended for c++ use ONLY)
    return QQmlListProperty<Level>(this , 0
                                // Append function
                                , [] (QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Level> *property, Level *value) -> void {
                                    GeneralSettings *gs = qobject_cast<GeneralSettings*>(property->object);
                                    if (value) {
                                        gs->d->levels.append(value);
                                    }
                                }
                                // Count function
                                , [] (QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Level> *property) -> int {
                                    return qobject_cast<GeneralSettings*>(property->object)->d->levels.count();
                                }
                                // At function
                                , [] (QQmlListProperty<Nwoki::Qml::SpriteMovementSettings::Level> *property, int index) -> Level* {
                                    return qobject_cast<GeneralSettings*>(property->object)->d->levels.at(index);
                                }
                                // Clear function
                                , [] (QQmlListProperty<Level> *property) {
                                    GeneralSettings *gs = qobject_cast<GeneralSettings*>(property->object);
                                    qDeleteAll(gs->d->levels);
                                    gs->d->levels.clear();
                                }
                            );
}

int GeneralSettings::levelCount() const
{
    return d->levels.count();
}

PlayerSettings *GeneralSettings::player() const
{
    return d->playerSettings;
}

void GeneralSettings::setStartLevel(const QString &startLevel)
{
    d->startLevel = startLevel;
}

void GeneralSettings::setPlayer(PlayerSettings *playerSettings)
{
    if (d->playerSettings != nullptr) {
        delete d->playerSettings;
        d->playerSettings = nullptr;
    }

    d->playerSettings = playerSettings;
}

QString GeneralSettings::startLevel() const
{
    return d->startLevel;
}


}

}

}
