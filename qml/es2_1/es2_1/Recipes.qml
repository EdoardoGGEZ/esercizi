import QtQuick
import QtQuick.Controls

ListView {
    id: listV
    orientation: ListView.Horizontal
    signal selected(int index)


    delegate: Rectangle {
        id: dad
        width: listV.width / 3
        height: title.height + img.height + 4
        radius: 10
        border {
            color: "black"
            width: 2
        }

        MouseArea {
            anchors.fill: parent
            onClicked: selected(index)
        }

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
                    pointSize: 33
                    bold: true
                }
                text: name
            }
            Image {
                id: img
                source: imageFood
                anchors {
                    right: column.right
                    left: column.left
                    leftMargin: 4
                    rightMargin: 4
                }
                fillMode: Image.PreserveAspectFit
            }
        }
    }
}
