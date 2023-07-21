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

    //    ListModel {
    //        ListElement {
    //
    //        }
    //    }
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
            object: recipesModel.getRecipe(recipesIndex)
            index: recipesIndex
            onBack: stack.pop()
        }
    }
}
