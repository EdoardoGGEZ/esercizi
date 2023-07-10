import QtQuick

Rectangle {
    id: button
    color: "transparent"
    radius: 32
    state: "default"
    border {
        color: "#FCB647"
        width: 1
    }
    property alias textButton: text.text

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
    }

    states: [
        State {
            name: "hover"
            when: myMouseArea.containsMouse
            PropertyChanges {
                target: text
                color: "#151B2E"
            }
            PropertyChanges {
                target: button
                color: "#FCB647"
            }
        }
    ]
    transitions: [
        Transition {
            from: ""
            to: "hover"
            reversible: true

            ColorAnimation {
                target: button
                duration: 300
            }
            ColorAnimation {
                target: text
                duration: 300
            }
        }
    ]
}
