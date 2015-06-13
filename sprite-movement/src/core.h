#ifndef CORE_H
#define CORE_H

class QQmlApplicationEngine;

class Core
{
public:
    Core();
    ~Core();

private:
    class Private;
    Private * const d;
};

#endif  // CORE_H
