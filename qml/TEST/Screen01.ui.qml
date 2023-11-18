import QtQuick
import QtQuick.Controls 6.2

Rectangle {
    width: 300
    height: 300
    visible: true
    color: "#31ff00"
    Logo {
        anchors.centerIn: parent
    }

    Button {
        id: button
        x: 44
        y: 0
        width: 210
        height: 52
        text: qsTr("TEST ME")
    }
}
