cmake_minimum_required(VERSION 3.19)
project(proyectoJuego)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics)

add_executable(proyectoJuego main.cpp Controller/Controller.cpp Controller/Controller.h View/View.cpp View/View.h Model/Jugador.cpp Model/Jugador.h)
target_link_libraries(proyectoJuego sfml-system sfml-window sfml-graphics)