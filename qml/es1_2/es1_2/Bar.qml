import QtQuick

Column {
    id: dad
    property int velocity: 500
    spacing: 10
    Text {
        id: percentageText
        Timer {
            interval: dad.velocity
            repeat: true
            running: true
            triggeredOnStart: true
            onTriggered: parent.text = (bar.percentage).toFixed(2)
        }
    }

    Rectangle {
        height: 40
        width: 804
        border.color: "black"
        border.width: 2
        Rectangle {
            id: bar
            property double percentage: 0
            anchors.left: parent.left
            anchors.leftMargin: 2
            anchors.verticalCenter: parent.verticalCenter
            color: "green"
            height: parent.height - 4
            width: percentage * 800

            Behavior on width {
                NumberAnimation {
                    duration: dad.velocity
                }
            }

            Timer {
                interval: dad.velocity
                repeat: true
                running: true
                triggeredOnStart: true
                onTriggered: {
                    var rand = Math.random() % 1
                    parent.percentage = rand
                }
            }
        }
    }
}
