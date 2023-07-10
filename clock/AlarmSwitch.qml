import QtQuick

Rectangle {
    id: switchAllarm
    height: 60
    width: 112
    color: disableColor
    radius: 8
    property color disableColor: Qt.rgba(159, 170, 176, 0.12)
    property color selectedColor: Qt.rgba(0, 180, 157, 0.2)

    Image {
        id: off
        source: "/assets/clock-switch-off-selected.png"
        anchors {
            left: parent.left
            leftMargin: 4
            top: parent.top
            topMargin: 4
        }
    }

    Image {
        id: on
        source: "/assets/clock-switch-on-disable.png"
        anchors {
            right: parent.right
            rightMargin: 4
            top: parent.top
            topMargin: 4
        }
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: switchAllarm
        onClicked: {
            if (switchAllarm.color === disableColor) {
                off.source = "/assets/clock-switch-off-disable.png"
                on.source = "/assets/clock-switch-on-selected.png"
                switchAllarm.color = selectedColor
            } else {
                off.source = "/assets/clock-switch-off-selected.png"
                on.source = "/assets/clock-switch-on-disable.png"
                switchAllarm.color = disableColor
            }
        }
    }
}
