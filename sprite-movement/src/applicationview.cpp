#include "applicationview.h"
#include "player.h"

#include <generated/auxconfig.h>
#include <plugins/mapsettings.h>
#include <plugins/playersettings.h>
#include <plugins/generalsettings.h>

#include <QtCore/QDebug>
#include <QtCore/QDir>

#include <QtQml/QQmlContext>
#include <QtQml/QQmlEngine>


class ApplicationView::Private
{
public:
    Private()
        : player(new Player)
        , settingsComponent(nullptr)
        , settings(nullptr)
    {};

    QString qmlSourceFile;
    Player *player;
    QQmlComponent *settingsComponent;

    Nwoki::Qml::SpriteMovementSettings::GeneralSettings *settings;
};


ApplicationView::ApplicationView(const QString &qmlSourceFile, QWindow *parent)
    : QQuickView(parent)
    , d(new Private)
{
    d->qmlSourceFile = qmlSourceFile;
    d->settingsComponent = new QQmlComponent(engine(), this);

    engine()->addImportPath(PLUGIN_DIR);

    connect(d->settingsComponent, &QQmlComponent::statusChanged, this, &ApplicationView::onSettingsComponentStatusChanged);

    setWidth(800);
    setHeight(600);

    // we want the QML to follow the View. And not the other way around
    setResizeMode(SizeRootObjectToView);

    // setup C++ objects visible to the QML side
    qmlRegisterType<Player>("Player", 1, 0, "Player");

    // load settings file
    loadSettingsFile();
}

ApplicationView::~ApplicationView()
{
    delete d->settings;
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

void ApplicationView::loadSettingsFile()
{
    d->settingsComponent->loadUrl(QUrl::fromLocalFile(QString(SETTINGS_DIR) + QDir::separator() + "settings.rc"), QQmlComponent::Asynchronous);
}

void ApplicationView::onSettingsComponentStatusChanged(QQmlComponent::Status status)
{
    if (status == QQmlComponent::Ready) {
        if (d->settings) {
            delete d->settings;
            d->settings = nullptr;
        }

        d->settings = qobject_cast<Nwoki::Qml::SpriteMovementSettings::GeneralSettings*>(d->settingsComponent->create());

        // TODO handle this, otherwise the following fails brutally with a segfault
        if (d->settings == nullptr) {
            qDebug() << "[Core::onSettingsComponentStatusChanged] ERROR: Could not create component";
            qDebug() << d->settingsComponent->errorString();
        } else {
            // creaate player
            if (d->settings->player() != nullptr) {
                d->player = new Player(this);

                // setup C++ objects visible to the QML side
                engine()->rootContext()->setContextProperty("CppPlayer", d->player);
                engine()->rootContext()->setContextProperty("PlayerSettings", d->settings->player());
            }

            if (d->settings->map() != nullptr) {
                // This setting can't be null otherwise there's no point in loading the demo game
                qDebug() << "MAP NAME: " << d->settings->map()->name();

//                 d->settings->map()->setCollisionObjects(SPRITES_DIR
//                                                         + "maps/"
//                                                         + d->settings->map()->name()
//                                                         + "/"
//                                                         + d->settings->map()->name()
//                                                         + ".json");
            }

            engine()->rootContext()->setContextProperty("SpritesDirectory", SPRITES_DIR);

            // after loadign the settings file, I set the QML source otherwise the context properties
            // aren't picked up
            setSource(QUrl(d->qmlSourceFile));
            show();
        }
    } else if (status == QQmlComponent::Error) {
        qDebug() << "[Core::onSettingsComponentStatusChanged] ERROR: " << d->settingsComponent->errorString();
        for (QQmlError err : d->settingsComponent->errors()) {
            qDebug() << "ERROR: " << err;
        }
    }
}


