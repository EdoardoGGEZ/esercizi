import QtQuick

Item {
    id: root
    property var numberType: value
    Rectangle {
        id: count
        anchors {
            left: parent.left
            right: parent.right
        }
        height: 280
        color: "#1B2F46"
        radius: 30
        property int numCount: 0

        Text {
            id: number
            anchors {
                horizontalCenter: count.horizontalCenter
                top: count.top
                topMargin: 52
            }
            color: "#FCB647"
            font {
                family: "Buenos Aires"
                pointSize: 85
            }
            text: count.numCount.toString().padStart(2, '0')
        }

        Text {
            id: numType
            anchors {
                horizontalCenter: count.horizontalCenter
                bottom: count.bottom
                bottomMargin: 39
            }
            color: "#9FAAB0"
            font {
                family: "Buenos Aires"
                pointSize: 14
            }
            text: root.numberType
        }
    }

    Image {
        id: arrowUp
        anchors {
            horizontalCenter: root.horizontalCenter
            bottom: divider.top
            bottomMargin: 4
        }
        source: "/assets/btn-arrow-active.svg"

        MouseArea {
            id: upMouseArea
            anchors.fill: arrowUp
            hoverEnabled: true
            //onClicked:
        }

        states: [
            State {
                name: "hover"
                when: upMouseArea.containsMouse
                PropertyChanges {
                    target: arrowUp
                    source: "/assets/btn-arrow-hover.svg"
                }
            }
        ]
    }

    Rectangle {
        id: divider
        anchors {
            horizontalCenter: root.horizontalCenter
            bottom: arrowDown.top
            bottomMargin: 4
        }
        height: 2
        width: arrowDown.width
        color: "#1B2F46"
    }

    Image {
        id: arrowDown
        anchors {
            horizontalCenter: root.horizontalCenter
            bottom: root.bottom
        }
        source: "/assets/btn-arrow-active.svg"
        rotation: 180

        MouseArea {
            id: downMouseArea
            anchors.fill: arrowDown
            hoverEnabled: true
            //onClicked:
        }

        states: [
            State {
                name: "hover"
                when: downMouseArea.containsMouse
                PropertyChanges {
                    target: arrowDown
                    source: "/assets/btn-arrow-hover.svg"
                }
            }
        ]
    }
}
