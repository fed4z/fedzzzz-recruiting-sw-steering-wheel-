import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.5

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
        property int  mediumFont: 70
        property int bigFont: 150
        //property int cellDimensions: 100
        property int verticalSpacing: 30

        Rectangle {
            id: mainBackground
            anchors.fill: parent
            color: "#36454F" // add to style sheet
        }




        RowLayout {
            id: topRow
            anchors {
                top: mainBackground.top
                horizontalCenter: mainBackground.horizontalCenter
                topMargin: 20
            }

            PowerBar {
                id: powerBar
                percentage: valuePower.value
                label: "POWER"
            }
        }

        ColumnLayout {
            id: centerColumn
            spacing: 90
            width: parent.width/3

            anchors {
               horizontalCenter: parent.horizontalCenter
               bottom: parent.bottom
               bottomMargin: margin
            }

            TextLabel {
                id: speed
                color: "darkblue"
                number: currentSpeed.value;
                label: "km/h"
                size: bigFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }


            TextLabel {
                id: rpm
                number: rpmCounter.value;
                label: "RPM"
                size: mediumFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

        }

        ColumnLayout {
            id: rightColumn
            spacing: verticalSpacing
            width: parent.width/3


            anchors {
                right: parent.right
                bottom: parent.bottom
                bottomMargin: margin
                leftMargin: margin
            }

            TextLabelUnit {
                id: optional
                number: 0
                label: "--"
                unit: "--"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
             //   anchors.horizontalCenter: parent.horizontalCenter
            }


            TextLabelUnit {
                id: sensorBmsHv
                number: volt_HV.value
                error: volt_HV.error
                label: "BMS HV"
                unit: "V"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }


            TextLabelUnit {
                id: sensorBmsLv
                number: volt_LV.value
                error: volt_LV.error
                label: "BMS LV"
                unit: "V"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

        }

        GridLayout {
            id: leftGrid
            columnSpacing: verticalSpacing*0.4
            rowSpacing: verticalSpacing
            width: parent.width/3
           // height: fillHeight

            rows: 3
            columns: 2

            anchors {
                bottom: parent.bottom
                left: parent.left
                bottomMargin: margin
               // leftMargin: margin
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
                number: temp_LV.value
                error: temp_LV.error
                label: "BMS LV"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            TextLabelUnit {
                id: tempBmsHv
                number: temp_HV.value
                error: temp_HV.error
                label: "BMS HV"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

            TextLabelUnit {
                id: tempInveter
                number: temp_INVERT.value
                error: temp_INVERT.error
                label: "INVERT"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }
            TextLabelUnit {
                id: tempMotor
                number: temp_MOTOR.value
                error: temp_MOTOR.error
                label: "MOTOR"
                unit: "°C"
                size: smallFont
                Layout.fillHeight: true
                Layout.fillWidth: true
            }

        }

}
