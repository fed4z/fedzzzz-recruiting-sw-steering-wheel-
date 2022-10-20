import QtQuick 2.12
import QtQuick.Layouts 1.12

Item {
    property int number
    property string label
    property string unit
    property int size
    property string color

    width: parent.width
    height: number.height

    Text {
        id: number
        color: parent.color
        text: parent.number
        font.pixelSize: parent.size
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
        }
    }

    Text {
        id: label
        color: parent.color
        font.pixelSize: size*(0.3)
        text: parent.label
        anchors{
            top: number.bottom
            horizontalCenter: parent.horizontalCenter
            topMargin: -15
        }

    }
}
