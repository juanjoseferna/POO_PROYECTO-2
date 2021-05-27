//
// Created by finch on 24/05/2021.
//

#ifndef PROYECTOJUEGO_COMBATE_H
#define PROYECTOJUEGO_COMBATE_H

#include <SFML/Graphics.hpp>
#include "Enemigo.h"
#include <iostream>
#include "Jugador.h"
#include <cstdlib>
#include <ctime>

using namespace sf;

class Combate {
private:
    Texture fondoPelea;
    int posibilidadHuir;
    int x1Rosa = 640, x2Rosa = 940, y1Rosa = 622, y2Rosa = 700;
    int x1Verde = 640, x2Verde = 940, y1Verde = 710, y2Verde = 788;
    int x1Naranja = 955, x2Naranja = 1256, y1Naranja = 622, y2Naranja = 700;
    int x1Azul = 955, x2Azul = 1256, y1Azul = 710, y2Azul = 788;
    Sprite sprite;
    Font *fuente1;
    Text *vidaTxt, *vidaNumero, *vidaEnemigoTxt, *vidaEnemigoNumero,
            *danoRealizado, *danoRecibido, *ataqueBasico, *ataqueEspecial,
            *huir, *pociones, *danoRealizadoNumero, *danoRecibidodoNumero;
public:
    Combate();
    void mostrarCombate(RenderWindow * ventana, Jugador * jugador, Enemigo * enemigo);
};


#endif //PROYECTOJUEGO_COMBATE_H

