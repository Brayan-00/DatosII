//
// Created by brayanrv on 8/8/19.
//

#include "main.h"
#include "mainwindow.h"
#include "mainwindow.cpp"
#include <gtkmm-3.0/gtkmm.h>


int main(int argc, char *argv[]) {
    // Initialize gtkmm
    auto app = Gtk::Application::create(argc, argv, "com.datosII.tarea");

    // Create the window
    Mainwindow window;

    // Start main loop
    return app->run(window);


}