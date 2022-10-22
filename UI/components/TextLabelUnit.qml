import QtQuick 2.12
import QtQuick.Layouts 1.12


Item {
    property int number
    property string label
    property string unit
    property int size
    property bool error: false


    height: number.height
    width: parent.width

    Text {
        id: number
        color: (error) ? "red" : "white"
        text: parent.number
        font.pixelSize: parent.size
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
    }

    Text {
        id: unit
        color: (error) ? "red" : "white"
        font.pixelSize: number.font.pixelSize*(0.3)
        text: parent.unit
        anchors {
            left: number.right
            top: number.top
            topMargin: 5
        }
    }

    Text {
        id: label
        color: (error) ? "red" : "white"
        font.pixelSize: number.font.pixelSize*(0.3)
        text: parent.label
        anchors{
            top: number.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: -10
        }

    }

}
