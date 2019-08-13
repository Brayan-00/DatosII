#include "mainwindow.h"
#include <gtkmm-3.0/gtkmm.h>
#include <iostream>


Mainwindow::Mainwindow()
    :sendBtn("Send") {
    // Initialize the main window
    set_border_width(10);
    set_size_request(400,600);
    set_title("App");


    // Create the first button

    sendBtn.signal_clicked().connect(sigc::mem_fun(*this, &Mainwindow::on_button_s));
    //mainBx.add(sendBtn);

    // Create the entry text for the message to send
    msgEnt.set_text("Ingrese un número entero");
    msgEnt.set_activities_default(true);



    //Adding the entry and the send button in a HBox
    textBx.add(sendBtn);
    textBx.add(msgEnt);

    //Adding the HBox to the main VBox
    //mainBx.add(textBx);




    // Display the main grid in the main window

    //add(mainBx);
    add(textBx);
    //mainBx.show_all();
    textBx.show_all();

}

// Destructor of the class
Mainwindow:: ~Mainwindow(  ){
    }



// Call when the first button is clicked
void Mainwindow::on_button_s()
{
    char numberRcv;

    std::cout << numberRcv << std::endl;
}


