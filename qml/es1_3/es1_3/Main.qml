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
        signal close
        Chapter {
            titolo: "CAPITOLO 1"
            contenuto: "la papaia"
            signal close
        }
        Chapter {
            titolo: "CAPITOLO 2"
            contenuto: "l'ananas"
            signal close
        }
        Chapter {
            titolo: "CAPITOLO 3"
            contenuto: "l'avocado"
            signal close
        }
    }
}
