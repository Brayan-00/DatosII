#include "mainwindow.h"
#include <gtkmm-3.0/gtkmm.h>
#include <iostream>


Mainwindow::Mainwindow()
    :sendBtn("Send") ,listBtn("Lista Simple"), TreeBtn("Árbol Binario"), m_VBox(Gtk::Orientation::VERTICAL)
    {
    // Initialize the main window
    set_border_width(15);
    set_size_request(600,600);
    set_title("App");

    sendBtn.set_hexpand(true);
   // sendBtn.set_halign(Gtk::Align::END);
    sendBtn.signal_clicked().connect(sigc::mem_fun(*this, &Mainwindow::send_Data()));


    //Adding the ComboBox to the main window
    add(mainBx);
    // Create the first button


    //mainBx.add(sendBtn);

    listBtn.signal_clicked().connect(sigc::mem_fun(*this, &Mainwindow::listBtn_clicked) );
    TreeBtn.signal_clicked().connect(sigc::mem_fun(*this, &Mainwindow::TreeBtn_clicked) );

    // Create the entry text for the message to send

    msgEnt.set_activates_default(true);

    //Settings for the HBox
    textBx.set_spacing(10);


    //Adding the entry and the send button in a HBox
    textBx.add(sendBtn);
    selectStct.add(listBtn);
    selectStct.add(TreeBtn);
    textBx.add(selectStct);
    textBx.add(msgEnt);





    //Adding the selection widgets to a VBox
    selecCnt.add(selectStct);


    //Adding the TextView to the mainwindow
    //mainBx.add(msgRcv);

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
void Mainwindow::send_Data() {
    std::cout<<"Se envía la información\n";
}
void Mainwindow::listBtn_clicked() {
    std::cout <<"Se escogió la lista\n";
}

void Mainwindow::TreeBtn_clicked() {
    std::cout<< "Se escogió el árbol\n";
}
void add_childrow(m_refTreeModel,int id, char name){
    auto childrow = *(m_refTreeModel->append(row.children()));
    childrow[m_Columns.m_col_id] = id;
    childrow[m_Columns.m_col_name] = name;


}

void Mainwindow::charge_Data(){
    add(m_VBox);

    m_ScrolledWindow.add(m_TreeView);

    m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
    m_ScrolledWindow.set_expand();

    m_VBox.add(m_ScrolledWindow);
    m_VBox.add(m_ButtonBox);

    m_ButtonBox.set_margin(5);

    m_refTreeModel = Gtk::TreeStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    m_TreeView.set_reorderable();

    auto row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 1;
    row[m_Columns.m_col_name] = "Listas Simples";

    row = *(m_refTreeModel->append());
    row[m_Columns.m_col_id] = 2;
    row[m_Columns.m_col_name] = "Árboles Binarios";

    //Add the TreeView's view columns:
    m_TreeView.append_column("ID", m_Columns.m_col_id);
    m_TreeView.append_column("Name", m_Columns.m_col_name);

    //Connect signal:
    m_TreeView.signal_row_activated().connect(sigc::mem_fun(*this, &Mainwindow::on_treeview_row_activated) );


}

void Mainwindow::on_treeview_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* /* column */)
{
    const auto iter = m_refTreeModel->get_iter(path);
    if(iter)
    {
        const auto row = *iter;
        std::cout << "Row activated: ID=" << row[m_Columns.m_col_id] << ", Name="
                  << row[m_Columns.m_col_name] << std::endl;
    }
}
