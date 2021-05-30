//
// Created by Usuario on 30/05/2021.
//

#ifndef PROYECTOJUEGO_BOSS_H
#define PROYECTOJUEGO_BOSS_H

#include "Personaje.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Boss : public Personaje {
private:
    Texture bossTexture;//textura del boss final
public:
    Sprite boss;
    Boss();
    void dibujarBoss(RenderWindow * ventana, int x, int y);//dibuja el boss en ventana
};

#endif //PROYECTOJUEGO_BOSS_H
