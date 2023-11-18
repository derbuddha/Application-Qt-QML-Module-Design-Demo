import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import qml.TEST

Rectangle {
    width: 1200
    height: 800
    visible: true
    color: "blue"

    ColumnLayout {
        anchors.fill: parent

        TestDisplay{
        }
    }
}
