import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.5

Window {
    width: 480
    height: 800
    visible: true

    StackView {
        id: stack
        anchors.fill: parent
        initialItem: pageHome
    }

    Component {
        id: pageHome

        PageHome {
            onOpenAlarmPage: stack.push(pageAlarm)
            onOpenPageAlarmList: stack.push(pageAlarmList)
        }
    }

    Component {
        id: pageAlarm

        PageAlarm {
            onBack: stack.pop()
            onAddAlarm: function (mins, hours) {
                clockObject.addAlarm(hours.toString().padStart(
                                         2, '0') + ":" + mins.toString(
                                         ).padStart(2, '0'), true)
            }
        }
    }

    Component {
        id: pageAlarmList

        PageAlarmList {
            onBack: stack.pop()
        }
    }
}
