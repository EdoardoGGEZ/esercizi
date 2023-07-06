import QtQuick

Rectangle {
    id: dad
    width: 1420
    height: title.height
    color: "black"
    state: "default"
    radius: 10
    property string titolo: value
    property string contenuto: value
    property double heightDad: 324
    signal close

    Column {

        anchors {
            left: dad.left
            leftMargin: 4
            bottom: dad.Bottom
            bottomMargin: 4
        }

        Text {
            id: title
            width: dad.width - 8
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 30
            color: "white"
            text: titolo
        }

        Text {
            id: content
            anchors {
                top: title.bottom
            }

            width: dad.width - 8
            opacity: 1
            wrapMode: Text.Wrap
            font.pointSize: 20
            color: "white"
            text: contenuto

            Behavior on opacity {
                NumberAnimation {
                    duration: 300
                }
            }

            Behavior on anchors.topMargin {
                NumberAnimation {
                    duration: 300
                }
            }
        }
    }

    MouseArea {
        id: myMouseArea
        anchors.fill: dad
        onClicked: {
            if (dad.state === "default") {
                close()
                //                dad.state = "expanded"
            } else
                dad.state = "default"
        }
    }

    Behavior on height {
        NumberAnimation {
            duration: 300
        }
    }

    states: [
        State {
            name: "default"
            PropertyChanges {
                target: content
                opacity: 0
                anchors.topMargin: 50
            }
        },
        State {
            name: "expanded"
            PropertyChanges {
                target: dad
                height: title.height + content.height + 4
            }
        }
    ]
}
