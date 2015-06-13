#include "playersettings.h"


namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class PlayerSettings::Private {
public:
    Private()
        : frameCount(0)
        , height(0)
        , width(0)
    {}

    int frameCount;
    int height;
    int width;
    QString name;
    QString sprite;
};


PlayerSettings::PlayerSettings(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

PlayerSettings::~PlayerSettings()
{
    delete d;
}

int PlayerSettings::frameCount() const
{
    return d->frameCount;
}

int PlayerSettings::height() const
{
    return d->height;
}

QString PlayerSettings::name() const
{
    return d->name;
}

void PlayerSettings::setFrameCount(int frameCount)
{
    d->frameCount = frameCount;
}

void PlayerSettings::setHeight(int height)
{
    d->height = height;
}

void PlayerSettings::setName(const QString &name)
{
    d->name = name;
}

void PlayerSettings::setSprite(const QString &sprite)
{
    d->sprite = sprite;
}

void PlayerSettings::setWidth(int width)
{
    d->width = width;
}

QString PlayerSettings::sprite() const
{
    return d->sprite;
}

int PlayerSettings::width() const
{
    return d->width;
}

}

}

}
