import QtQuick

Column {
    id: dad
    spacing: 10
    property double percentage: 0

    Text {
        id: percentageText
    }

    Rectangle {
        height: 40
        width: 804
        border.color: "black"
        border.width: 2

        Rectangle {
            id: bar
            property int velocity: 800

            anchors {
                left: parent.left
                leftMargin: 2
                verticalCenter: parent.verticalCenter
            }
            color: "green"
            height: parent.height - 4
            width: percentage * 800

            Behavior on width {
                NumberAnimation {
                    duration: bar.velocity
                }
            }

            Timer {
                interval: bar.velocity
                repeat: true
                running: true
                triggeredOnStart: true
                onTriggered: {
                    var rand = Math.random() % 1
                    dad.percentage = rand
                    percentageText.text = (dad.percentage).toFixed(2)
                }
            }
        }
    }
}
