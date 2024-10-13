import QtQuick 2.15
import QtQuick.Controls
import MyComplexQtQuickApp

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Complex Qt Quick App"

    Column {
        spacing: 10
        anchors.centerIn: parent

        Text {
            id: messageText
            text: "Waiting for message..."
            font.pixelSize: 24
        }

        Button {
            text: "Get Message from C++"
            onClicked: {
                messageText.text = myApp.getMessage()
            }
        }

        CustomComponent {  // Custom QML component
        }
    }

    MyApp {
        id: myApp
    }
}
