#include "mainwindow.h"
#include <gtkmm-3.0/gtkmm.h>
#include <iostream>


Mainwindow::Mainwindow()
    :sendBtn("Send") {
    // Initialize the main window
    set_border_width(15);
    set_size_request(600,600);
    set_title("App");


    // Create the first button

    sendBtn.signal_clicked().connect(sigc::mem_fun(*this, &Mainwindow::on_button_s));
    //mainBx.add(sendBtn);

    // Create the entry text for the message to send
    msgEnt.set_text("Ingrese un número entero");
    msgEnt.set_activates_default(true);

    //Settings for the HBox
    textBx.set_spacing(10);


    //Adding the entry and the send button in a HBox
    textBx.add(sendBtn);
    textBx.add(msgEnt);


    //Creating the TextView to display the information wanted
    textBfr = Gtk::TextBuffer::create();
    textBfr->set_text("Pruebaaa");
    msgRcv.set_buffer(textBfr);


    //Adding the TextView to the mainwindow
    mainBx.add(msgRcv);

    //Adding the HBox to the main VBox
    mainBx.add(textBx);






    // Display the main grid in the main window
    set_spacing(30);

    add(mainBx);
    //add(textBx);
    mainBx.show_all();
    //textBx.show_all();

}


// Destructor of the class
Mainwindow:: ~Mainwindow( ){
    }



// Call when the first button is clicked
void Mainwindow::on_button_s()
{
    char numberRcv;

    std::cout << numberRcv << std::endl;
}


