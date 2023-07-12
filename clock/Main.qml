import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.5

Window {
    width: 480
    height: 800
    visible: true
    color: "#151B2E"

    StackView {
        anchors.fill: parent
        initialItem: pageHome
    }
    Component {
        id: pageHome
        PageHome {}
    }
}
