cmake_minimum_required(VERSION 3.5) # Version à adapter si besoin
project(projet LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11) # C++ 11, peut-être 14 ou 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
cmake_policy(SET CMP0100 NEW)
find_package(Qt5 COMPONENTS Widgets REQUIRED) # QWidget
set(app_icon_resource_windows "./resources.qrc")
add_executable(projet main.cpp quatrowidget.cpp quatrowidget.h mainwindow.cpp mainwindow.h resources.qrc ${app_icon_resource_window})

target_link_libraries(projet PRIVATE Qt5::Widgets)
