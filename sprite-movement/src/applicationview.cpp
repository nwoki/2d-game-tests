#include "applicationview.h"
#include "player.h"


#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>


class ApplicationView::Private
{
public:
    Private()
        : player(new Player)
    {};

    QString qmlSourceFile;
    Player *player;
};


ApplicationView::ApplicationView(const QString &qmlSourceFile, QWindow *parent)
    : QQuickView(parent)
    , d(new Private)
{
    d->qmlSourceFile = qmlSourceFile;

    setWidth(800);
    setHeight(600);

    // we want the QML to follow the View. And not the other way around
    setResizeMode(SizeRootObjectToView);

    // setup C++ objects visible to the QML side
    qmlRegisterType<Player>("Player", 1, 0, "Player");

    engine()->rootContext()->setContextProperty("CppPlayer", d->player);

    setSource(QUrl(d->qmlSourceFile));
    show();
}

ApplicationView::~ApplicationView()
{
    delete d->player;
    delete d;
}


void ApplicationView::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key()) {
        case Qt::Key_Up:
            d->player->setMovement(Player::MovementUp);
            break;
        case Qt::Key_Down:
            d->player->setMovement(Player::MovementDown);
            break;
        case Qt::Key_Left:
            d->player->setMovement(Player::MovementLeft);
            break;
        case Qt::Key_Right:
            d->player->setMovement(Player::MovementRight);
            break;
        default:
            break;
    }

    QQuickView::keyPressEvent(keyEvent);
}

void ApplicationView::keyReleaseEvent(QKeyEvent* keyEvent)
{
    // TODO detect IDLE state for player
    QQuickView::keyReleaseEvent(keyEvent);
}

