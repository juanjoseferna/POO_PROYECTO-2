//
// Created by finch on 24/05/2021.
//

#ifndef PROYECTOJUEGO_ENEMIGO_H
#define PROYECTOJUEGO_ENEMIGO_H

#include "Personaje.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemigo : public Personaje{
private:
    Texture enemigoT;
public:
    Sprite spriteEnemigo;
    void dibujarEnemigo(RenderWindow * ventana, int x, int y);
    Enemigo();

};


#endif //PROYECTOJUEGO_ENEMIGO_H
