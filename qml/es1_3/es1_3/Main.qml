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
        Chapter {
            titolo: "CAPITOLO 1"
            contenuto: "la papaia"
        }
        Chapter {
            titolo: "CAPITOLO 1"
            contenuto: "l'ananas"
        }
        Chapter {
            titolo: "CAPITOLO 1"
            contenuto: "l'avocado"
        }
    }
}
