import QtQuick

Rectangle {
    id: button
    width: 240
    height: 240
    radius: 120
    state: "off"

    MouseArea {
        id: myMouseArea
        anchors.fill: parent
        onClicked: {
            if (parent.state === "off")
                parent.state = "on"
            else
                parent.state = "off"
        }
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
        },
        State {
            name: "off"
            PropertyChanges {
                target: button
                color: "red"
            }
        }
    ]
}
