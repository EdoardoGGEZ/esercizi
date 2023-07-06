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
            contenuto: "There are many variations of passages of Lorem Ipsum available, but the majority have suffered alteration in some form, by injected humour, or randomised words which don't look even slightly believable. If you are going to use a passage of Lorem Ipsum, you need to be sure there isn't anything embarrassing hidden in the middle of text. All the Lorem Ipsum generators on the Internet tend to repeat predefined chunks as necessary, making this the first true generator on the Internet. It uses a dictionary of over 200 Latin words, combined with a handful of model sentence structures, to generate Lorem Ipsum which looks reasonable. The generated Lorem Ipsum is therefore always free from repetition, injected humour, or non-characteristic words etc."
            onClose: timer.closeAll(this)
        }
        Chapter {
            titolo: "CAPITOLO 3"
            contenuto: "Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of \"de Finibus Bonorum et Malorum\" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, \"Lorem ipsum dolor sit amet..\", comes from a line in section 1.10.32."
            onClose: timer.closeAll(this)
        }
    }
}
