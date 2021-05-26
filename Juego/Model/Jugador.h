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
    Sprite spriteHerz, herz2;
    View camara;
    int fotogram = 0, direccion = 0, sizeA = 48, sizeB = 48;
    int ataqueEspecial;
    float velocidad;
    float cordX, cordY;
    Clock reloj;
public:
    Jugador();
    void crearJugador();
    void mostrarJugador(RenderWindow * ventana);
    void moverse();
    int getAtaqueEspecial();
};


#endif //PROYECTOJUEGO_JUGADOR_H
