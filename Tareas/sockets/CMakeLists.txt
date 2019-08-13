cmake_minimum_required(VERSION 3.14)
project(sockets)

set(CMAKE_CXX_STANDARD 17)

add_executable(sockets GUI/main.cpp GUI/main.h GUI/mainwindow.cpp GUI/mainwindow.h Client/Client.cpp Client/Client.h Server/Server.cpp Server/Server.h GUI/main.cpp GUI/main.h)

