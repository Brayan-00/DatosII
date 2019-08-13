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
    //Signal handlers:
    void    on_button_s();

    //Member widgets:
    Gtk::Button sendBtn;
    Gtk::VBox mainBx;
    Gtk::HBox textBx;
    Gtk::TextView msgRcv;
    Gtk::Entry msgEnt;
};


#endif //SOCKETS_MAINWINDOW_H
