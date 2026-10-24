import QtQuick
import QtQuick.Controls //Hello Roshan. I added some buttons. Ty im making cookies for my family rn so i will be afk // Ok!

ApplicationWindow {
    title: "SFS Modpack Manager"
    visible: true // apparently this is required cuz it isnt visible by default
    width: 960 // I think this is how to set width
    height: 480 // I think this is how to set height

    Text {
        id: titleText // better avoid using reserved keywords so changed it to titleText
        text: "SFS Modpack Manager"
        y: 30
        anchors.horizontalCenter: parent.horizontalCenter // better to use parent instead of an id
        font.pointSize: 20
        font.bold: true
        color: "white" // colors text white
        font.family: "Monospace" // Do i need to explain what this does? No
    }

    ComboBox {
        id: modpackChooser
        editable: false //I'm assuming that's what you meant. as long as i can still add items through the JS. OK
        model: modpacks
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

    Button{
        id: launchButton
        text: "Launch SFS" //Do you want to be able to do that? 
        anchors.horizontalCenter: parent.horizontalCenter
        y: 360
    }

    Button{
        id: manageButton
        text: "Manage Modpacks"
        y: 360
        x: 320
    }

    Button{
        id: otherButton
        text: "PLACEHOLDER" //PLACEHOLDER!
        y: 360
        x: 640
    }
} // arent you suppose to use ApplicationWindow?
// I don't know qml
// I told you
// Learn some I will wait dw
// It might be better for you to do it yourself, I don't really know how this works
// Neither do i
// Oh. OK
// Ig qt widgets is a good option
// What is "ig"? I guess
// Oh
// you can import QtQuick.Controls for Buttons and stuff
// Thanks
// Btw you can embed JS functions in this
// I know, but I don't know JS either. I really only know python
// I know some JS but not alot. I offered to make a C++ backend because I knew you didn't know JS
// I have to go now, I'll be back in 30 minutes. Ok cya
// Remember to delete some of these comments before we commit
// OK
// Roshan, is it going to support multiple mod packs?
// if i know how to do it in C++ lol
// So really it can just be like ckan
// CKAN technically doesnt support modpacks, it only supports game instances
// Wait it can do that? it cant create game instances tho. Oh. Also i mean copies of the game not instances
// I have been wasting so much time
// What do you want buttons for? no clue
// Better if you use ComboBox or smth
// What do you want the combo box for?
// Picking the modpack.
// OK
// I'll let you vibecode if you need the help.
// I'm not going to do that
// Ok