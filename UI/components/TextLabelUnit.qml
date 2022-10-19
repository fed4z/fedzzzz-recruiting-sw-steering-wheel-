import QtQuick 2.12
import QtQuick.Layouts 1.12

Item {
    property int number: number.text
    property string label: label.text
    property string unit: unit.text
    property int size: number.font.pixelSize


    width: number.width
    height: number.height

    Text {
        id: number
        color: "white"
        text: parent.number
        font.pixelSize: parent.size
    }

    Text {
        id: unit
        color: "white"
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
        color: "white"
        font.pixelSize: number.font.pixelSize*(0.3)
        text: parent.label
        anchors{
            top: number.bottom
            horizontalCenter: number.horizontalCenter
            topMargin: -10
        }

    }

}
