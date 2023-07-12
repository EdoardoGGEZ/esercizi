import QtQuick

Page {
    id: root
    signal back

    Button {
        textButton: "SET ALARM"
        anchors {
            fill: root
            topMargin: 706
            leftMargin: 23
            bottomMargin: 30
            rightMargin: 23
        }
    }

    Text {
        id: name
        anchors {
            top: root.top
            horizontalCenter: root.horizontalCenter
            topMargin: 40
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font {
            pointSize: 20
            bold: true
            family: "Buenos Aires"
        }
        color: "#9FAAB0"
        text: "Alarm"
    }
    Image {
        id: arrowBack
        anchors {
            left: root.left
            verticalCenter: name.verticalCenter
            leftMargin: 28
        }
        source: "/assets/btn-back-active.svg"

        MouseArea {
            id: myMouseArea
            anchors.fill: parent
            hoverEnabled: true
            onClicked: back()
        }

        states: [
            State {
                name: "hover"
                when: myMouseArea.containsMouse
                PropertyChanges {
                    target: arrowBack
                    source: "/assets/btn-back-hover.svg"
                }
            }
        ]
    }
}
