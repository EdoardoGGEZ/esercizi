import QtQuick

Rectangle {
    id: dad
    width: 1420
    height: 324
    property string titolo: value
    property string contenuto: value

    Rectangle {
        id: content
        anchors.centerIn: parent
        color: "black"
        state: "default"
        radius: 10

        Text {
            id: text
            width: parent.width
            height: parent.height - 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlighVCenter
            font.pointSize: 40
            color: "white"
            text: titolo
        }

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
                    height: parent.height / 5 + 20
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
                PropertyChanges {
                    target: text
                    horizontalAlignment: text.AlignLeft
                    font.pointSize: 20
                    text: contenuto
                }
            }
        ]
    }
}
