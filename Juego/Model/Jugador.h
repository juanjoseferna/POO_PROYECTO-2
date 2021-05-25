//
// Created by finch on 20/05/2021.
//

#ifndef PROYECTOJUEGO_JUGADOR_H
#define PROYECTOJUEGO_JUGADOR_H

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include <iostream>

using namespace sf;

class Jugador : public Personaje{
private:
    Texture Herz;
    Sprite spriteHerz;
    View camara;
    int fotogram = 0, direccion = 0, sizeA = 48, sizeB = 48;
    float cordX, cordY;
    Clock reloj;
public:
    Jugador();
    void mostrarJugador(RenderWindow * ventana);
    void moverse();

};


#endif //PROYECTOJUEGO_JUGADOR_H
