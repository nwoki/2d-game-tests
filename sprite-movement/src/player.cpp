#include "player.h"

#include <QtCore/QDebug>


class Player::Private
{
public:
    Private()
        : movement(Player::MovementIdle)
    {}

    Player::MovementDirection movement;
};


Player::Player(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

Player::~Player()
{
    delete d;
}

Player::MovementDirection Player::movement() const
{
    return d->movement;
}

void Player::setMovement(Player::MovementDirection movement)
{
    d->movement = movement;
    Q_EMIT movementChanged();
}
