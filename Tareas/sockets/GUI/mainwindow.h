//
// Created by brayanrv on 8/8/19.
//

#ifndef SOCKETS_MAINWINDOW_H
#define SOCKETS_MAINWINDOW_H

#include <gtkmm-3.0/gtkmm.h>


class Mainwindow : public Gtk::Window{

    //Constructor
public:
    Mainwindow();
    virtual ~Mainwindow();

protected:

    void on_cell_data_extra(const Gtk::TreeModel::const_iterator& iter);

    //Signal handlers:
    void    on_button_s();
    void    on_combo_changed();

    //Tree model columns:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord{
    public:
        ModelColumns(){
            add(m_col_list); add(m_col_tree); }

        Gtk::TreeModelColumn<Glib::ustring> m_col_list;
        Gtk::TreeModelColumn<Glib::ustring> m_col_tree;
    };
    ModelColumns m_Columns;

    //Child widgets:
    Gtk::ComboBox m_Combo;
    Gtk::CellRenderText m_cell;
    Glib::RefPtr<Gtr::ListStore> m_refTreeModel;


    //Member widgets:
    Gtk::Button sendBtn;
    Gtk::VBox mainBx;
    Gtk::HBox textBx;
    //TextView related data
    Gtk::TextView msgRcv;
    Glib::RefPtr<Gtk::TextBuffer> textBfr;
    //Selecting data structure related data
    Gtk::ListBox selectStct;
    Gtk::Label selectInst;
    Gtk::VBox selecCnt;

    Gtk::Entry msgEnt;


};


#endif //SOCKETS_MAINWINDOW_H
