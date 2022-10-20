import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12



Item {
    property string label
    property double percentage: 0.0
    property int intPercentage: percentage*100

    ProgressBar {
        id: bar
        value: percentage
        padding: 2

        anchors.horizontalCenter: parent.horizontalCenter
        background: Rectangle {
            implicitWidth: 200
            implicitHeight: 30
            color: "black"
            opacity: 0.2
            radius: 3
        }


        contentItem: Item {
            implicitWidth: 400
            implicitHeight: 20

            Rectangle {
                width: bar.visualPosition * parent.width
                height: parent.height
                radius: 2
                color: "Green"
            }
        }
    }

    Text {
        color: "white"

        text: intPercentage
        font.pixelSize: 30
        anchors.centerIn: bar
    }

    Text {
        color: "white"
        text: label
        font.pixelSize: 20
        anchors {
            /*
            verticalCenter: bar.verticalCenter
            left: bar.right
            */
            horizontalCenter: bar.horizontalCenter
            top: bar.bottom
        }
    }

}
