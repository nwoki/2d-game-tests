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


TiledJsonParser::TiledJsonParser()
    : d(new Private)
{
}

TiledJsonParser::~TiledJsonParser()
{
    delete d;
}

QList<QRect> TiledJsonParser::parseObjects(const QString &jsonMapFile)
{
    QFile jsonFile(jsonMapFile);
    QList<QRect> objects;

    if (!jsonFile.open(QIODevice::ReadOnly)) {
        return objects;
    }

    QJsonParseError jsonParseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonFile.readAll(), &jsonParseError);

    if (jsonParseError.error != QJsonParseError::NoError) {
        qDebug() << "ERROR: " << jsonParseError.errorString();
        return objects;
    }

    // do the actual parsing
    QJsonObject jsonRootObj = jsonDoc.object();

    for (const QVariant &layerVariant : jsonRootObj.value("layers").toVariant().toList()) {
        QVariantMap layerMap = layerVariant.toMap();

        // objects
        if (layerMap.value("type").toString() == QStringLiteral("objectgroup")) {
            QVariantList layerObjects = layerMap.value("objects").toList();

            for (const QVariant &object : layerObjects) {
                QVariantMap objectMap = object.toMap();
                objects.append(QRect(objectMap.value("x").toInt()
                                    , objectMap.value("y").toInt()
                                    , objectMap.value("width").toInt()
                                    , objectMap.value("height").toInt()));
            }
        }
    }

    return objects;
}
