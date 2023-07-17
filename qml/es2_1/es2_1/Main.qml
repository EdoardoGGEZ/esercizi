import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
    id: desk
    width: 1840
    height: 1020
    visible: true
    color: "#fffdd0"
    property int recipesIndex: 0
    property var recipe: recipesModel.get(recipesIndex)

    ListModel {
        id: recipesModel
        ListElement {
            name: qsTr("torta di mele")
            imageFood: "https://www.fattoincasadabenedetta.it/wp-content/uploads/2019/08/torta-di-mele-semplice-SITO-copertina.jpg"
            difficulty: 2
            time: 20
        }
        ListElement {
            name: qsTr("tiramisu")
            imageFood: "https://www.giallozafferano.it/images/251-25105/Tiramisu-della-tradizione_650x433_wm.jpg"
            difficulty: 4
            time: 50
        }
        ListElement {
            name: qsTr("torta della nonna")
            imageFood: "https://www.lucake.it/wp-content/uploads/2022/09/torta-della-nonna.jpg"
            difficulty: 3
            time: 30
        }
    }

    StackView {
        id: stack
        initialItem: overView
        anchors.fill: parent
    }
    Component {
        id: overView
        Recipes {
            width: desk.width
            onSelected: function (index) {
                recipesIndex = index
                stack.push(details)
            }
            model: recipesModel
        }
    }
    Component {
        id: details
        Details {
            object: recipe
            onBack: stack.pop()
        }
    }
}
