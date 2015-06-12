import QtQuick 2.4;
import QtQuick.Window 2.2

Window {
    width: 800;
    height: 600;
    visible: true;

    Item {
        anchors.fill: parent;
        focus: true;

        AnimatedSprite {
            id: demoSprite;

            anchors.centerIn: parent;

            width: 32;
            height: 48;
            source: "qrc:///sprites/snowwhite.png";
            frameCount: 4;
            frameHeight: 48;
            frameWidth: 32;
            frameRate: 10;
        }

        Keys.onLeftPressed: {
            demoSprite.frameX = 0;
            demoSprite.frameY = 48;
        }

        Keys.onRightPressed: {
            demoSprite.frameX = 0;
            demoSprite.frameY = 48*2;
        }

        Keys.onUpPressed: {
            demoSprite.frameX = 0;
            demoSprite.frameY = 48*3;
        }

        Keys.onDownPressed: {
            demoSprite.frameX = 0;
            demoSprite.frameY = 0;
        }
    }
}
