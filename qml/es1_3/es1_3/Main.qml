import QtQuick
import QtQuick.Window

Window {
    width: 1840
    height: 1020
    visible: true

    Column {
        id: column
        signal go

        function checkClose() {
            var children = column.children
            for (var i = 0; i < 3; i++) {
                if (children[i].state === "expanded") {
                    return false
                }
            }

            return true
        }

        Timer {
            id: timer
            interval: 300
            property Chapter objectOpenTimer: null
            onTriggered: objectOpenTimer.state = "expanded"

            function closeAll(objectOpen) {
                objectOpenTimer = objectOpen
                var children = column.children
                if (column.checkClose() === true)
                    objectOpen.state = "expanded"
                else {
                    for (var i = 0; i < 3; i++) {
                        children[i].state = "default"
                    }
                    start()
                }
            }
        }

        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 20
        }
        spacing: 4

        Chapter {
            titolo: "CAPITOLO 1"
            contenuto: "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum."
            onClose: timer.closeAll(this)
        }
        Chapter {
            titolo: "CAPITOLO 2"
            contenuto: "l'ananas"
            onClose: timer.closeAll(this)
        }
        Chapter {
            titolo: "CAPITOLO 3"
            contenuto: "l'avocado"
            onClose: timer.closeAll(this)
        }
    }
}
