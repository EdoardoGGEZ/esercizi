import QtQuick
import QtQuick.Window

Window {
    width: 1920
    height: 1020
    visible: true

    Column {
        id: column
        property var percentages: [0.36, 0.12, 0.74, 0.94, 0.18]
        spacing: 100

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 150
        }

        Bar {
            percentage: column.percentages[0]
        }
        Bar {
            percentage: column.percentages[1]
        }
        Bar {
            percentage: column.percentages[2]
        }
        Bar {
            percentage: column.percentages[3]
        }
        Bar {
            percentage: column.percentages[4]
        }
    }
}
