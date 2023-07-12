import QtQuick

Item {
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
