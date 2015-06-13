#ifndef PLAYER_H
#define PLAYER_H

#include <QtCore/QObject>


class Player : public QObject
{
    Q_OBJECT
    Q_ENUMS(MovementDirection)

    Q_PROPERTY(MovementDirection movement       READ movement   WRITE setMovement       NOTIFY movementChanged)

public:
    enum MovementDirection {
        MovementDown,
        MovementIdle,
        MovementLeft,
        MovementRight,
        MovementUp
    };

    Player(QObject *parent = 0);
    ~Player();

    MovementDirection movement() const;
    void setMovement(MovementDirection movement);

Q_SIGNALS:
    void movementChanged();

private:
    class Private;
    Private * const d;
};

#endif  // PLAYER_H
