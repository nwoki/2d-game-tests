#ifndef APPLICATIONVIEW_H
#define APPLICATIONVIEW_H

#include <QtQuick/QQuickView>


class ApplicationView : public QQuickView
{
    Q_OBJECT

public:
    ApplicationView(const QString &qmlSourceFile, QWindow *parent = 0);
    ~ApplicationView();

protected:
    void keyPressEvent(QKeyEvent *keyEvent) Q_DECL_FINAL;
    void keyReleaseEvent(QKeyEvent *keyEvent) Q_DECL_FINAL;

private:
    class Private;
    Private * const d;
};

#endif  // APPLICATIONVIEW_H
