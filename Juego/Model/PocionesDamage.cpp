//
// Created by finch on 28/05/2021.
//

#include "PocionesDamage.h"

PocionesDamage::PocionesDamage() {
    efectoPocion = 15; //efecto de la pocion daño lo que aumenta
}

PocionesDamage::~PocionesDamage(){
}

void PocionesDamage::cargarTexturas(){
    texturaPocionDamage.loadFromFile("../Img/pocionFuerza.png");//carga textura
    spritePocionD.setTexture(texturaPocionDamage);
}

void PocionesDamage::pintarItem(RenderWindow *ventana, int x, int y){
    spriteItem.setPosition(x, y);
    if (PocionesDamage::suelo == 1){
        cargarTexturas();
        spriteItem.setTexture(texturaPocionDamage);
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

FloatRect PocionesDamage::getColision() {
    return spritePocionD.getGlobalBounds();
}

int PocionesDamage::getSuelo() {
    return suelo;
}

void PocionesDamage::recogerItemSuelo(){
    suelo = 0;
}

void PocionesDamage::pintarItemInventario(RenderWindow *ventana, int x, int y) {
    spriteItem.setPosition(x, y);
    spriteItem.setTexture(texturaPocionDamage);
    if(PocionesDamage::suelo == 0){
        ventana->draw(spriteItem);
    }else{
        return;
    }
}

void PocionesDamage::usarItem(Jugador *jugador) {
    jugador->setDamage(efectoPocion);
    efectoPocion = 0;
    texturaPocionDamage.loadFromFile("../Img/pocionVacia.png");
}