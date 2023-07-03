import QtQuick
import QtQuick.Window

Window {
    width: 1840
    height: 1020
    visible: true

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 20
        spacing: 4
        Chapter {}
        Chapter {}
        Chapter {}
    }
}
