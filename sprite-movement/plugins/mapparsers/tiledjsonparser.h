#ifndef SPRITEMOVEMENTSETTING_TILEDJSONPARSER_H
#define SPRITEMOVEMENTSETTING_TILEDJSONPARSER_H


#include <QtCore/QList>
#include <QtCore/QRect>
#include <QtCore/QString>


class TiledJsonParser
{
public:
    TiledJsonParser();
    ~TiledJsonParser();

    QList<QRect> parseObjects(const QString &jsonMapFile);

private:
    class Private;
    Private * const d;
};


#endif  // SPRITEMOVEMENTSETTING_TILEDJSONPARSER_H
