import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12



Item {
    property double percentage

    ProgressBar {
        id: bar
        value: percentage
        padding: 2

        anchors.horizontalCenter: parent.horizontalCenter
        background: Rectangle {
            implicitWidth: 200
            implicitHeight: 30
            color: "black"
            radius: 3
        }


        contentItem: Item {
            implicitWidth: 200
            implicitHeight: 20

            Rectangle {
                width: bar.visualPosition * parent.width
                height: parent.height
                radius: 2
                color: "darkGreen"
            }
        }
    }

    Text {
        color: "white"

        text: bar.value*100 + "%"
        font.pixelSize: 30
        anchors.centerIn: bar
    }

    Text {
        color: "white"
        text: "POWER"
        font.pixelSize: 20
        anchors {
            verticalCenter: bar.verticalCenter
            left: bar.right
        }
    }

}
