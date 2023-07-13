import QtQuick

Page {
    id: root
    signal back

    Button {
        textButton: "SET ALARM"
        anchors {
            left: root.left
            bottom: root.bottom
            right: root.right
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

    Counter {
        anchors {
            top: root.top
            left: root.left
            bottom: root.bottom
            right: root.horizontalCenter
            topMargin: 160
            leftMargin: 28
            bottomMargin: 138
            rightMargin: 22
        }
        numberType: "hours"
    }

    Text {
        id: colon
        anchors {
            top: root.top
            topMargin: 52 + 160
            horizontalCenter: root.horizontalCenter
        }
        color: "#707070"
        font {
            //family: "SF Pro Display"
            pointSize: 85
        }
        text: qsTr(":")
    }

    Counter {
        anchors {
            top: root.top
            left: root.horizontalCenter
            bottom: root.bottom
            right: root.right
            topMargin: 160
            leftMargin: 22
            bottomMargin: 138
            rightMargin: 28
        }
        numberType: "mins"
    }
}
