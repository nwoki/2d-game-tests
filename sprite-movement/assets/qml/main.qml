import QtQuick 2.4;
import QtQuick.Window 2.2

Window {
    width: 800;
    height: 600;
    visible: true;

    AnimatedSprite {
        id: demoSprite;
        anchors.centerIn: parent;
        width: 32;
        height: 51;
        source: "qrc:///sprites/down_walk.png";
        frameCount: 4;
        frameHeight: 51;
        frameWidth: 32;
        frameRate: 10;
    }
}
