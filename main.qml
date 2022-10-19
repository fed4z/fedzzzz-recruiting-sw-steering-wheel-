import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12

import Fed 1.0

import "./UI/components"




Window {
    width: 800
    height: 480
    visible: true
    title: qsTr("SteeringWheel")

    /*
    Loader {
        id: mainLoader
        anchors.fill: parent
        source: "./UI/Screen/Screen.qml"
    }*/



        property int margin: 50
        property int smallFont: 50
        property int bigFont: 150
        //property int cellDimensions: 100
        property int verticalSpacing: 35

        Rectangle {
            id: mainBackground
            anchors.fill: parent
            color: "black"
        }




        RowLayout {
            id: topRow
            anchors.top: mainBackground.top
            anchors.horizontalCenter: mainBackground.horizontalCenter

            Text {
                id: provvisorio
                color: "white"
                text:"fede" //sensor.getTemp();
                font.pixelSize: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }


        }

        ColumnLayout {
            id: centerColumn
            spacing: 100

            anchors {
               horizontalCenter: parent.horizontalCenter
               bottom: parent.bottom
               bottomMargin: margin
            }

            TextLabel {
                id: speed
                number: currentSpeed.value;
                label: "km/h"
                size: bigFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }


            TextLabel {
                id: rpm
                number: 13789
                label: "RPM"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

        }

        ColumnLayout {
            id: rightColumn
            spacing: verticalSpacing

            anchors {
                right: parent.right
                bottom: parent.bottom
                bottomMargin: margin
                rightMargin: margin*4/3
            }

            TextLabelUnit {
                id: optional
                number: 0
                label: "--"
                unit: "--"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }


            TextLabelUnit {
                id: sensorBmsHv
                number: 2
                label: "BMS HV"
                unit: "V"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }


            TextLabelUnit {
                id: sensorBmsLv
                number: 2
                label: "BMS LV"
                unit: "V"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

        }

        GridLayout {
            id: leftGrid
            columnSpacing: verticalSpacing
            rowSpacing: verticalSpacing

            rows: 3
            columns: 2

            anchors {
                bottom: parent.bottom
                left: parent.left
                bottomMargin: margin
                leftMargin: margin
            }

            TextLabelUnit {
                id: opt0
                number: 0
                label: "opt0"
                unit: "--"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            TextLabelUnit {
                id: opt2
                number: 0
                label: "opt1"
                unit: "--"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            TextLabelUnit {
                id: tempBmsLv
                number: 2
                label: "BMS LV"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            TextLabelUnit {
                id: tempBmsHv
                number: 2
                label: "BMS LV"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            TextLabelUnit {
                id: temp1
                number: 2
                label: "BMS LV"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
            TextLabelUnit {
                id: temp2
                number: 2
                label: "BMS LV"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

        }

}
