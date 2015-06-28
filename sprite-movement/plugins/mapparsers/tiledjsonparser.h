#ifndef SPRITEMOVEMENTSETTING_TILEDJSONPARSER_H
#define SPRITEMOVEMENTSETTING_TILEDJSONPARSER_H


#include <QtCore/QList>
#include <QtCore/QObject>
#include <QtCore/QRect>
#include <QtCore/QString>


class TiledJsonParser : public QObject
{
    Q_OBJECT

public:
    TiledJsonParser(QObject *parent = 0);
    ~TiledJsonParser();

    void parseObjects(const QString &jsonMapFile);

Q_SIGNALS:
    /** emitted when the collision objects have been parsed */
    void collisionObjects(const QList<QRect> &collisionObjects);

    /** emitted when the player start object has been parsed */
    void playerStartObject(const QRect &startPos);

private:
    class Private;
    Private * const d;
};


#endif  // SPRITEMOVEMENTSETTING_TILEDJSONPARSER_H
