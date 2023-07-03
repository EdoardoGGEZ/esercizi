import QtQuick

Rectangle {
    id: dad
    width: 1420
    height: 324
    color: "red"
    Rectangle {
        id: content
        width: parent.width / 3
        height: parent.height / 5
        anchors.centerIn: parent
        color: "green"
        state: "default"

        states: [
            State {
                name: "default"
                PropertyChanges {
                    target: object
                }
            },
            State {
                name: "expanded"
                PropertyChanges {
                    target: content
                    width: dad.width
                    height: dad.height
                }
            }
        ]
    }
}
