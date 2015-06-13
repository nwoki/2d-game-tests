#ifndef SPRITEMOVEMENTSETTINGS_PLAYER_H
#define SPRITEMOVEMENTSETTINGS_PLAYER_H


#include <QtCore/QObject>

namespace Nwoki {

namespace Qml {

namespace SpriteMovementSettings {

class PlayerSettings : public QObject {
    Q_OBJECT
    Q_DISABLE_COPY(PlayerSettings)

    Q_PROPERTY(int frameCount   READ frameCount WRITE setFrameCount)
    Q_PROPERTY(int height       READ height     WRITE setHeight)
    Q_PROPERTY(int width        READ width      WRITE setWidth)
    Q_PROPERTY(QString name     READ name       WRITE setName)
    Q_PROPERTY(QString sprite   READ sprite     WRITE setSprite)

public:
    PlayerSettings(QObject *parent = 0);
    ~PlayerSettings();

    int frameCount() const;
    int height() const;
    int width() const;
    QString name() const;
    QString sprite() const;

    void setFrameCount(int frameCount);
    void setHeight(int height);
    void setWidth(int width);
    void setName(const QString &name);
    void setSprite(const QString &sprite);

private:
    class Private;
    Private * const d;
};

}

}

}

#endif  // SPRITEMOVEMENTSETTINGS_PLAYER_H
