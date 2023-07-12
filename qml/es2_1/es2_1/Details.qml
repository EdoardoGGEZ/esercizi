import QtQuick

Rectangle {
    id: dad
    radius: 10
    border {
        color: "black"
        width: 2
    }
    property var object
    signal back

    Column {
        id: column
        anchors.fill: dad

        Text {
            id: title
            anchors {
                left: column.left
                right: column.right
            }
            horizontalAlignment: Text.AlignHCenter
            font {
                pointSize: 55
                bold: true
            }
            text: object.name
        }
        Image {
            id: img
            source: object.imageFood
            anchors.horizontalCenter: column.horizontalCenter
            fillMode: Image.PreserveAspectFit
        }
        Text {
            anchors.left: img.left
            font.pointSize: 22
            text: qsTr("difficoltà: " + object.difficulty + "/5")
        }
        Text {
            anchors.left: img.left
            font.pointSize: 22
            text: qsTr("tempo: " + object.time + " min")
        }
    }
    MouseArea {
        anchors.fill: parent
        onClicked: back()
    }
}
