import QtQuick
import QtQuick.Window

Window {
    width: 1920
    height: 1080
    visible: true
    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 150
        spacing: 100
        Bar {
            velocity: 50
        }
        Bar {}
        Bar {
            velocity: 200
        }
        Bar {
            velocity: 500
        }
        Bar {
            velocity: 1000
        }
    }
}
