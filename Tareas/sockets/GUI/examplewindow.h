#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::Window
{
public:
    ExampleWindow();
    virtual ~ExampleWindow();

protected:
    //Signal handlers:
    void send_Data();
    void on_treeview_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);
    void add_List_Child();
    void add_Tree_Child();
    void fill_buffers(Glib::ustring text);
    void add_Tree();
    void add_List();

    //Tree model columns:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:

        ModelColumns()
        { add(m_col_id); add(m_col_name);}

        Gtk::TreeModelColumn<int> m_col_id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;


    };

    ModelColumns m_Columns;

    //Child widgets:
    Gtk::Box m_VBox;

    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;

    Gtk::TreeModel::Row listrow;
    Gtk::TreeModel::Row treerow;

    Gtk::ButtonBox m_ButtonBox;
    Gtk::Button m_Button_Quit;
    Gtk::Button addList;
    Gtk::Button addTree;

    Gtk::TextView data_view;
    Glib::RefPtr<Gtk::TextBuffer> data_view_buffer;

    Gtk::VBox container;

    int quantityLists;
    int quantityTrees;
};

#endif //GTKMM_EXAMPLEWINDOW_H