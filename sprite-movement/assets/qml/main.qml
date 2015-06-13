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

        // TODO player sprite info to be move to settings file
        width: PlayerSettings.width;
        height: PlayerSettings.height;
        source: "qrc:///sprites/players/16x18_green-man-sprite.png";
        frameCount: PlayerSettings.frameCount;
        frameHeight: PlayerSettings.height;
        frameWidth: PlayerSettings.width;
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

            // All sprites must be made the same way to facilitate animations
            // UP - top row
            // RIGHT - second row
            // DOWN - third row
            // LEFT - fourth row
            switch (CppPlayer.movement) {
                case Player.MovementUp:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = 0;
                    break;
                case Player.MovementRight:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = PlayerSettings.height;
                    break;
                case Player.MovementDown:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = PlayerSettings.height*2;
                    break;
                case Player.MovementLeft:
                    demoSprite.frameX = 0;
                    demoSprite.frameY = PlayerSettings.height*3;
                    break;
            }
        }
    }
}

