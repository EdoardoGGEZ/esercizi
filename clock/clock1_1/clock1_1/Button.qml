import QtQuick

Rectangle {
    id: button
    width: 190
    height: 64
    color: "#FCB647"
    radius: 32
    state: "default"
    border {
        color: "#FCB647"
        width: 1
    }

    Text {
        id: text
        anchors {
            top: button.top
            right: button.right
            left: button.left
            bottom: button.bottom
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: 20
            bold: true
            family: "Buenos Aires"
        }
        color: "#FCB647"
        text: "ACTIVE"
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: button
        hoverEnabled: true
        onEntered: button.state = "hover"
        onExited: button.state = "default"
    }

    states: [
        State {
            name: "default"
            PropertyChanges {
                target: button
                color: "transparent"
            }
        },
        State {
            name: "hover"
            PropertyChanges {
                target: text
                color: "#151B2E"
                text: "HOVER"
            }
        }
    ]
}
