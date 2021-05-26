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
    View camara;
    int fotogram = 0, direccion = 0, sizeA = 48, sizeB = 48;
    int ataqueEspecial;
    Clock reloj;
public:
    Sprite spriteHerz;
    float cordX, cordY;
    float velocidad;
    Jugador();
    void crearJugador();
    void mostrarJugador(RenderWindow * ventana);
    void moverse();
    int getAtaqueEspecial();
    FloatRect getColision();
};


#endif //PROYECTOJUEGO_JUGADOR_H
