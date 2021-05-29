//
// Created by finch on 28/05/2021.
//

#include "Lanza.h"

Lanza::Lanza() : Item(){
    this->cantidadUsos = 3;
    this->cantidadDano = 10;
}

Lanza::~Lanza(){}

void Lanza::cargarTexturas(){
    texturaLanza.loadFromFile("../Img/lanza.png");
    spriteLanza.setTexture(texturaLanza);
}

void Lanza::reducirResistencia(){
    this->cantidadUsos = this->cantidadUsos-1;
}

void Lanza::pintarItem(RenderWindow *ventana, int x, int y) {
    cargarTexturas();
    spriteLanza.setPosition(x, y);
    ventana->draw(spriteLanza);
}

FloatRect Lanza::getColision(){

}