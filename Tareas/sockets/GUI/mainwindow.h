//
// Created by brayanrv on 8/8/19.
//

#ifndef SOCKETS_MAINWINDOW_H
#define SOCKETS_MAINWINDOW_H

#include <gtkmm-3.0/gtkmm.h>


class window : public Gtk::Window{

    //Constructor
public:
    window();
    virtual ~window();

protected:



    //Signal handlers:
    void send_Data();
    void listBtn_clicked();
    void TreeBtn_clicked();
    void charge_Data();
    void on_treeview_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);









    //Member widgets:
    Gtk::Button sendBtn;
    Gtk::VBox mainBx;
    Gtk::HBox textBx;
    //TextView related data
    Gtk::TextView msgRcv;

    //Selecting data structure related data
    Gtk::Label selectInst;
    Gtk::VBox selecCnt;
    Gtk::VBox selectStct;

    Gtk::Entry msgEnt;


    //Child widgets:
    Gtk::CheckButton listBtn;
    Gtk::CheckButton TreeBtn;


    //Tree model columns:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        void add_childrow();
        ModelColumns()
        { add(m_col_id); add(m_col_name); }

        Gtk::TreeModelColumn<int> m_col_id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumns m_Columns;

    //Child widgets:
    Gtk::Box m_VBox;

    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;

    Gtk::Box m_ButtonBox;

};





#endif //SOCKETS_MAINWINDOW_H
