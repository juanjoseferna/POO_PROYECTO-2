//
// Created by finch on 24/05/2021.
//

#ifndef PROYECTOJUEGO_COMBATE_H
#define PROYECTOJUEGO_COMBATE_H

#include <SFML/Graphics.hpp>
#include "Enemigo.h"
#include <iostream>
#include "Jugador.h"

using namespace sf;

class Combate {
private:
    int turno, turnoEnemigo;
    Texture fondoPelea;
    Enemigo enemigo;
    int x1Huir = 47, x2Huir = 579, y1Huir = 47, y2Huir = 581;
    int x1Rojo = 649, x2Rojo = 929, y1Rojo = 651, y2Rojo = 933;
    int x1Verde = 653, x2Verde = 923, y1Verde = 655, y2Verde = 923;
    int x1Naranja = 971, x2Naranja = 1235, y1Naranja = 969, y2Naranja = 1239;
    int x1Azul = 975, x2Azul = 1243, y1Azul = 973, y2Azul = 1241;
    Sprite sprite;
public:
    Combate();
    void mostrarCombate(RenderWindow * ventana, Jugador * jugador);
    void retirarse();
};


#endif //PROYECTOJUEGO_COMBATE_H
