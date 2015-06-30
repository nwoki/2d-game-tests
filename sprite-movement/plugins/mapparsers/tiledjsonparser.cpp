#include "tiledjsonparser.h"

#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QJsonArray>
#include <QtCore/QJsonDocument>
#include <QtCore/QJsonObject>
#include <QtCore/QJsonParseError>
#include <QtCore/QVariant>
#include <QtCore/QVariantList>



class TiledJsonParser::Private
{
public:
    Private() {}
};


TiledJsonParser::TiledJsonParser(QObject *parent)
    : QObject(parent)
    , d(new Private)
{
}

TiledJsonParser::~TiledJsonParser()
{
    delete d;
}

void TiledJsonParser::parseObjects(const QString &jsonMapFile)
{
    QFile jsonFile(jsonMapFile);

    if (!jsonFile.open(QIODevice::ReadOnly)) {
        return;
    }

    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonFile.readAll(), &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError) {
        qDebug() << "ERROR: " << jsonParseError.errorString();
        return;
    }

    // do the actual parsing
    QJsonObject jsonRootObj = jsonDoc.object();

    for (const QVariant &layerVariant : jsonRootObj.value("layers").toVariant().toList()) {
        QVariantMap layerMap = layerVariant.toMap();

        // collision objects
        if (layerMap.value("type").toString() == QStringLiteral("objectgroup")
            && layerMap.value("name").toString().toLower() == QStringLiteral("collision")) {

            QVariantList layerObjects = layerMap.value("objects").toList();

            QList<QRect> objects;
            for (const QVariant &object : layerObjects) {
                QVariantMap objectMap = object.toMap();
                objects.append(QRect(objectMap.value("x").toInt()
                , objectMap.value("y").toInt()
                , objectMap.value("width").toInt()
                , objectMap.value("height").toInt()));
            }

            Q_EMIT collisionObjects(objects);
        }

        // player start object
        else if (layerMap.value("type").toString() == QStringLiteral("objectgroup")
            && layerMap.value("name").toString().toLower() == QStringLiteral("playerstart")) {

            QVariantList layerObjects = layerMap.value("objects").toList();

            // just extract the first position. If there's more than one, then it's the devs fault
            if (layerObjects.count() > 0) {
                QVariantMap playerStartMap = layerObjects.at(0).toMap();

                Q_EMIT playerStartObject(QRect(playerStartMap.value("x").toInt()
                                            , playerStartMap.value("y").toInt()
                                            , playerStartMap.value("width").toInt()
                                            , playerStartMap.value("height").toInt()));
            }
        }
    }
}

