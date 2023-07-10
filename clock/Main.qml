import QtQuick
import QtQuick.Window

Window {
    width: 480
    height: 800
    visible: true
    color: "#151B2E"

    Button {
        textButton: "TIMER"
        anchors {
            fill: parent
            topMargin: 628
            leftMargin: 18
            bottomMargin: 108
            rightMargin: 272
        }
    }
    Button {
        textButton: "ALARM"
        anchors {
            fill: parent
            topMargin: 628
            leftMargin: 272
            bottomMargin: 108
            rightMargin: 18
        }
    }

    AlarmSwitch {}
}
