#include "mainwindow.h"
#include <gtkmm-3.0/gtkmm.h>
#include <iostream>


Mainwindow::Mainwindow()
    :sendBtn("Send") {
    // Initialize the main window
    set_border_width(15);
    set_size_request(600,600);
    set_title("App");
    set_margin(5);

    //Create the Tree model:
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_Combo.set_model(m_refTreeModel);

    //Fill the ComboBox's Tree Model:
    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
    row[m_Columns.m_col_list] = "Lista Simple";
    row[m_Columns.m_col_tree] = "Árbol Binario";
    m_Combo.set_active(row);

    //Add the model columns to the Combo
    m_Combo.pack_start(m_Columns.m_col_tree);
    m_Combo.pack_start(m_Columns.m_col_list);

    m_Combo.set_cell_data_func(m_cell, sigc::mem_fun(*this, &ExampleWindow::on_cell_data_extra));
    m_Combo.pack_start(m_cell);

    //Adding the ComboBox to the main window
    add(mainBx);
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
    textBfr->set_text("String desearilzado del JSON");
    msgRcv.set_buffer(textBfr);

    //Creating the selection of the data structure
    selectStct.set_text("Escoja la estructura:");

    //Adding the selection widgets to a VBox
    selecCnt.add(selectStct);


    //Adding the TextView to the mainwindow
    mainBx.add(msgRcv);

    //Adding the HBox to the main VBox
    mainBx.add(textBx);

    //Adding the VBox of the data structure selection to the main VBox
    mainBx.add(selecCnt);








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


