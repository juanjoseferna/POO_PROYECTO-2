//
// Created by finch on 24/05/2021.
//

#include "Enemigo.h"
Enemigo::Enemigo() : Personaje(40,5){
    enemigoT.loadFromFile("../Img/enemigo.png");
    spriteEnemigo.setTexture(enemigoT);
}

Enemigo::~Enemigo(){
}

void Enemigo::dibujarEnemigo(RenderWindow *ventana, int x, int y) {
    enemigoT.loadFromFile("../Img/enemigo.png");
    spriteEnemigo.setTexture(enemigoT);
    if (Enemigo::getVida() > 0) {
        spriteEnemigo.setPosition(x, y);
        ventana->draw(spriteEnemigo);
    } else {
        return;
    }
}

Enemigo::Enemigo(Enemigo *pEnemigo) : Personaje(40,5){
    enemigoT.loadFromFile("../Img/enemigo.png");
    spriteEnemigo.setTexture(enemigoT);
}