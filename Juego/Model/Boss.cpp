//
// Created by Usuario on 30/05/2021.
//

#include "Boss.h"

Boss::Boss() : Personaje(80,15){
}

void Boss::dibujarBoss(RenderWindow *ventana, int x, int y) {//dibuja el boss en la ventana
    bossTexture.loadFromFile("../Img/enemigo2.png");
    boss.setTexture(bossTexture);
    if (Boss::getVida() > 0) {
        boss.setPosition(x, y);
        ventana->draw(boss);
    } else {
        return;
    }
}