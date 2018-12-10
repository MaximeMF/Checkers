import QtQuick 2.4

Item {
    width: 400
    height: 400

    GridView {
        id: gridView
        x: 94
        y: 40
        width: 173
        height: 174
        delegate: Item {
            x: 5
            height: 50
            Column {
                spacing: 0
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }
            }
        }
        cellWidth: 70
        cellHeight: 70
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
            ListElement {
                name: "sss"
                colorCode: "red"
            }
        }
    }
    states: [
        State {
            name: "State1"
        }
    ]
}
