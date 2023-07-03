import QtQuick

Rectangle {
    id: dad
    width: 1420
    height: 324

    Rectangle {
        id: content
        anchors.centerIn: parent
        color: "green"
        state: "default"

        MouseArea {
            id: myMouseArea
            anchors.fill: parent
        }

        states: [
            State {
                name: "default"
                PropertyChanges {
                    target: content
                    width: parent.width / 3
                    height: parent.height / 5
                }
                PropertyChanges {
                    target: myMouseArea
                    onClicked: parent.state = "expanded"
                }
            },
            State {
                name: "expanded"
                PropertyChanges {
                    target: content
                    width: parent.width
                    height: parent.height
                }
                PropertyChanges {
                    target: myMouseArea
                    onClicked: parent.state = "default"
                }
            }
        ]
    }
}
