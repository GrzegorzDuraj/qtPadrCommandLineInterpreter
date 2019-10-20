import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    // color: "grey"

    property color fontColor: "black"
    property int  fontSize: 20
    readonly property string preeditInput: "Insert Command"

    Connections
    {
        target: commandInputClass
        onMessageChanged:
        {
            console.log ( " sygnal z cpp " + outputCommand )
            textAreaId.text = outputCommand + textAreaId.text

        }

    }


    ColumnLayout
    {
        Component.onCompleted:
        {
            console.log ("object " , this + " height " + height)
        }

        anchors.fill: parent
        Rectangle
        {
            id: rectangleTextAreaId
            //Layout.fillHeight: true
            Layout.preferredWidth: parent.width
            Layout.preferredHeight: parent.height - insertCommandRectangleId.height



            Component.onCompleted:
            {
                console.log ("object " , this + " height " + height)
            }


            color: "lightblue"
            Flickable {
                id: flick

                //   width: 300; height: 200;
                anchors.fill: parent
                contentWidth: textAreaId.paintedWidth
                contentHeight: textAreaId.paintedHeight
                clip: true

//                function ensureVisible(r)
//                {

//                    console.log("contentX: " , contentX)
//                    console.log("contentY: " , contentY)
//                    console.log("r: " , r)

//                    console.log("r.X: " , r.x)
//                    console.log("r.Y: " , r.y)


//                    if (contentX >= r.x)
//                        contentX = r.x;
//                    else if (contentX+width <= r.x+r.width)
//                        contentX = r.x+r.width-width;

//                    if (r.y === 0 )
//                    {
//                        r.y = contentY
//                        console.log("r.y is eqaul 0 : " , contentY + " " + r.y)
//                        contentY += r.height

//                    }
//                    else if (contentY >= r.y)
//                    {
//                        contentY = r.y;
//                        console.log("r >=  " , contentY)

//                    }
//                    else if (contentY+height <= r.y+r.height)
//                    {

//                        contentY = r.y+r.height-height;
//                        console.log("r <  " , contentY)

//                    }

//                    console.log("contentX: " , contentX)
//                    console.log("contentY: " , contentY)


//                }

                Component.onCompleted:
                {
                    console.log ("object " , this + " height " + height)
                }


                TextEdit
                {
                    Component.onCompleted:
                    {
                        console.log ("object " , this + " height " + height)
                    }

                    id :textAreaId
                    color: "black"
                    font{pixelSize:fontSize}
                    //anchors.fill: parent
                    width: flick.width
                    height: flick.height
                    textFormat: Text.RichText

                    focus: true
                    //      cursorRectangle:

             //       onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)
                    text:
                        "lorem ipsum dolor sit amet, \n" +
                        "druga linia " +
                        "\n\n\nkolejna linia n\n\n\n\n" +
                        "\n\n\nkolejna linia n\n\n\n\n"

                }

                ScrollBar {
                    id: vbar
                    hoverEnabled: true
                    active: true
                    orientation: Qt.Vertical
                    size: rectangleTextAreaId.height / textAreaId.height
                    anchors.top: parent.top
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    policy: ScrollBar.AlwaysOn
                }

                ScrollBar {
                    id: hbar
                    hoverEnabled: true
                    active:true
                    orientation: Qt.Horizontal
                    size: rectangleTextAreaId.width / textAreaId.width
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom
                    policy: ScrollBar.AlwaysOn
                }

            }
        }




        Rectangle
        {
            Component.onCompleted:
            {
                console.log ("object " , this + " height " + height)
            }


            id: insertCommandRectangleId
            color: "green"
            objectName: "rectangleCommandSend"
            border.color: "black"

            Layout.preferredWidth: parent.width
            Layout.preferredHeight: textInputCommandId.height
            Layout.alignment: Qt.AlignBottom


            function checkKey ( myKeyEvent)
            {
                print ("Detect Key: " + myKeyEvent.key)
                if (myKeyEvent.key === Qt.Key_Enter)
                {
                    console.log("enter pressed")
                }
            }


            Keys.onPressed: checkKey(event)

            signal sendMessage(var msg )

            Keys.onReturnPressed: {
                console.log("enterPressed")
                //    console.log("textArea Id text " + textAreaId.text)
                console.log("\n\n")
                console.log(textInputCommandId.text)
               // textAreaId.text = "<font color=\"00FFFF\">" + textInputCommandId.text </font> + "\n" + textAreaId.text
                 textAreaId.text = "<b>" + textInputCommandId.text + "<\\b>" + "\n" + textAreaId.text

                insertCommandRectangleId.sendMessage(textInputCommandId.text)
                textInputCommandId.clear()

            }

            TextField
            {

                id: textInputCommandId

                width: parent.width

                Component.onCompleted:
                {
                    console.log ("object " , this + " height " + height)
                }
                placeholderText : preeditInput
                font {pixelSize:fontSize}
                //   wrapMode: TextInput.Wrap
                focus:true
            }
        }
    }
}
