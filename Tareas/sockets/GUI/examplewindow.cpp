#include <iostream>
#include "examplewindow.h"

ExampleWindow::ExampleWindow()
        : m_VBox(Gtk::ORIENTATION_VERTICAL),
          m_Button_Quit("Send"),
          addTree("Agregar Árbol"),
          addList("Agregar Lista")
{
    set_title("App");
    set_border_width(10);
    set_default_size(400, 600);


    container.add(m_VBox);
    container.add(data_view);
    quantityTrees = 0;
    quantityLists = 0;






    //Add the TreeView, inside a ScrolledWindow, with the button underneath:
    m_ScrolledWindow.add(m_TreeView);

    //Only show the scrollbars when they are necessary:
    m_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

    m_VBox.pack_start(m_ScrolledWindow);
    m_VBox.pack_start(m_ButtonBox, Gtk::PACK_SHRINK);
    m_ButtonBox.pack_start(m_Button_Quit, Gtk::PACK_SHRINK);
    m_ButtonBox.pack_start(addList, Gtk::PACK_SHRINK);
    m_ButtonBox.pack_start(addTree, Gtk::PACK_SHRINK);
    m_ButtonBox.set_border_width(5);
    m_ButtonBox.set_layout(Gtk::BUTTONBOX_END);
    m_Button_Quit.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::send_Data));
    addTree.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::add_Tree));
    addList.signal_clicked().connect(sigc::mem_fun(*this, &ExampleWindow::add_List));

    //Create the Tree model:
    m_refTreeModel = Gtk::TreeStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    //All the items to be reordered with drag-and-drop:
    m_TreeView.set_reorderable();

    //Fill the TreeView's model
    listrow = *(m_refTreeModel->append());
    listrow[m_Columns.m_col_id] = 1;
    listrow[m_Columns.m_col_name] = "Listas Simples";



    treerow = *(m_refTreeModel->append());
    treerow[m_Columns.m_col_id] = 2;
    treerow[m_Columns.m_col_name] = "Árboles Binarios";




    //Add the TreeView's view columns:
    m_TreeView.append_column("ID", m_Columns.m_col_id);
    m_TreeView.append_column("Name", m_Columns.m_col_name);


    //Connect signal:
    m_TreeView.signal_row_activated().connect(sigc::mem_fun(*this, &ExampleWindow::on_treeview_row_activated) );





    add(container);
    show_all_children();
}

ExampleWindow::~ExampleWindow()
{
}

void ExampleWindow::send_Data()
{
    fill_buffers("Esto es una prueba");
}

void ExampleWindow::on_treeview_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* /* column */)
{
    Gtk::TreeModel::iterator iter = m_refTreeModel->get_iter(path);
    if(iter)
    {
        Gtk::TreeModel::Row row = *iter;
        std::cout << "Row activated: ID=" << row[m_Columns.m_col_id] << ", Name="
                  << row[m_Columns.m_col_name] << std::endl;
    }
}

void ExampleWindow::add_List_Child(){
    auto childrow = *(m_refTreeModel->append(listrow.children()));
    childrow[m_Columns.m_col_id] = quantityLists;
    childrow[m_Columns.m_col_name] = "Lista";
    quantityLists++;
    std::cout<<"Se agrego a lista";

}
void ExampleWindow::add_Tree_Child(){
    auto childrow_Tree  = *(m_refTreeModel->append(treerow.children()));
    childrow_Tree[m_Columns.m_col_id] = quantityTrees;
    childrow_Tree[m_Columns.m_col_name] = "Árbol";
    quantityTrees++;
    std::cout<<"Se agrego a Árbol";
}

void ExampleWindow::fill_buffers(Glib::ustring text) {
    data_view_buffer = Gtk::TextBuffer::create();
    data_view_buffer->set_text(text);
    data_view.set_buffer(data_view_buffer);
}

void ExampleWindow::add_List() {
   add_List_Child();


}
void ExampleWindow::add_Tree() {
    add_Tree_Child();

}