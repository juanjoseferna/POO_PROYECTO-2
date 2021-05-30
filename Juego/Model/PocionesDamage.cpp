//
// Created by finch on 28/05/2021.
//

#include "PocionesDamage.h"

PocionesDamage::PocionesDamage() {
    efectoPocion = 15;
}

PocionesDamage::~PocionesDamage(){
}

void PocionesDamage::usarPocion(Jugador *jugador){
    jugador->setDamage(jugador->getDamage() + efectoPocion);
}

void PocionesDamage::cargarTexturas(){
    texturaPocionDamage.loadFromFile("../Img/pocionFuerza.png");
    spritePocionD.setTexture(texturaPocionDamage);
}

void PocionesDamage::pintarItem(RenderWindow *ventana, int x, int y){
    cargarTexturas();
    spritePocionD.setPosition(x,y);
    ventana->draw(spritePocionD);
}

FloatRect PocionesDamage::getColision() {
    return spritePocionD.getGlobalBounds();
}