cmake_minimum_required(VERSION 3.19)
project(proyectoJuego)

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5 COMPONENTS system window graphics audio)

add_executable(proyectoJuego main.cpp Controller/Controller.cpp Controller/Controller.h View/View.cpp View/View.h
        Model/Jugador.cpp Model/Jugador.h Model/Ventana.cpp Model/Ventana.h Model/Combate.cpp Model/Combate.h
        Model/Mapa.cpp Model/Mapa.h Model/Personaje.cpp Model/Personaje.h Model/Enemigo.cpp Model/Enemigo.h
        Model/Lanza.cpp Model/Lanza.h Model/Espada.cpp Model/Espada.h Model/Item.cpp Model/Item.h Model/Inventario.cpp
        Model/Inventario.h Model/Pociones.cpp Model/Pociones.h Model/PocionesVida.cpp Model/PocionesVida.h Model/PocionesDamage.cpp Model/PocionesDamage.h)
target_link_libraries(proyectoJuego sfml-system sfml-window sfml-graphics sfml-audio)