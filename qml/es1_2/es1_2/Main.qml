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
        Bar {}
        Bar {}
        Bar {}
        Bar {}
        Bar {}
    }
}
