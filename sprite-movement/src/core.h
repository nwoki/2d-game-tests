#ifndef CORE_H
#define CORE_H

class QQmlApplicationEngine;

class Core
{
public:
    Core(QQmlApplicationEngine *engine);
    ~Core();

private:
    class Private;
    Private * const d;
};

#endif  // CORE_H
