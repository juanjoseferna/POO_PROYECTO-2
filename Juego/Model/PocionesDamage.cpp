//
// Created by finch on 28/05/2021.
//

#include "PocionesDamage.h"

#include "PocionesDamage.h"
PocionesDamage::PocionesDamage() {
    efectoPocion = 15;
}

void PocionesDamage::utilizarPocionDamage(Jugador *jugador){
    jugador->setDamage(jugador->getDamage() + efectoPocion);
}
void PocionesDamage::cargarTexturasPocionDamage(){
    texturaPocionDamage.loadFromFile("../Img/pocionFuerza.png");
    spritePocionD.setTexture(texturaPocionDamage);
}

void PocionesDamage::pintarItem(RenderWindow *ventana, int x, int y){
    cargarTexturasPocionDamage();
    spritePocionD.setPosition(x,y);
    ventana->draw(spritePocionD);
}