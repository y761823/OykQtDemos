import QtQuick 2.15

Item {
    id: root

    Rectangle {
        id: rect
        width: Math.min(parent.width, parent.height)
        height: width
        color: "transparent"
        border.color: "green"
        border.width: 0.1 * height
        Text {
            id: text
            anchors.centerIn: parent
            color: "red"
            text: "Center"
            font.pixelSize: 0.1 * parent.height
        }
    }

    Connections {
        target: viewerConnection
        function onValueChanged(count) {
            text.text = viewerConnection.getValue()
        }
    }
}

