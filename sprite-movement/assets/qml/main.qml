import QtQuick 2.4;
import Player 1.0;

Item {
    anchors.fill: parent;

    width: 800;
    height: 600;

    AnimatedSprite {
        id: demoSprite;

        anchors.centerIn: parent;

        running: false;
        width: 32;
        height: 48;
        source: "qrc:///sprites/snowwhite.png";
        frameCount: 4;
        frameHeight: 48;
        frameWidth: 32;
        frameRate: 10;
    }

    Connections {
        target: CppPlayer;

        onMovementChanged: {
            if (CppPlayer.movement !== Player.MovementIdle) {
                demoSprite.running = true;
            } else {
                demoSprite.running = false;
            }

            switch (CppPlayer.movement) {
                case Player.MovementLeft:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = 48;
                    break;
                case Player.MovementRight:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = 48*2;
                    break;
                case Player.MovementUp:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = 48*3;
                    break;
                case Player.MovementDown:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = 0;
                    break;
            }
        }
    }
}

