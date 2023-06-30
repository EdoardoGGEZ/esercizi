import QtQuick

Rectangle {
    id: button
    width: 240
    height: 240
    radius: 120
    anchors.centerIn: parent
    state: "off"

    MouseArea {
        id: myMouseArea
        anchors.fill: parent
        onClicked: parent.state = "on"
    }

    Behavior on color {
        ColorAnimation {
            duration: 200
        }
    }

    states: [
        State {
            name: "on"
            PropertyChanges {
                target: button
                color: "green"
            }
            PropertyChanges {
                target: myMouseArea
                onClicked: parent.state = "off"
            }
        },
        State {
            name: "off"
            PropertyChanges {
                target: button
                color: "red"
            }
            PropertyChanges {
                target: myMouseArea
                onClicked: parent.state = "on"
            }
        }
    ]
}
