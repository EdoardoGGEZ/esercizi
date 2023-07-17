import QtQuick

Page {
    id: root
    signal openAlarmPage
    Button {
        textButton: "TIMER"
        anchors {
            left: root.left
            right: root.horizontalCenter
            bottom: root.bottom
            leftMargin: 18
            rightMargin: 32
            bottomMargin: 108
        }
    }
    Button {
        textButton: "ALARM"
        anchors {
            left: root.horizontalCenter
            right: root.right
            bottom: root.bottom
            leftMargin: 32
            rightMargin: 18
            bottomMargin: 108
        }
        onClick: openAlarmPage()
    }

    AlarmSwitch {}
}
