import QtQuick 2.15

Item {
    id: root

    Rectangle {
        width: Math.min(parent.width, parent.height)
        height: width
        color: "red"
        border.color: "black"
        border.width: 0.1 * height
        radius: 0.5 * width
        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("qml log")
                controllerConnection.callSlot("Rect")
                controllerConnection.add(5)
            }
        }
    }
}

