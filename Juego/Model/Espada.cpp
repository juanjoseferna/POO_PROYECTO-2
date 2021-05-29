//
// Created by finch on 28/05/2021.
//

#include "Espada.h"
Espada::Espada(){}

Espada::~Espada(){}

void Espada::cargarTexturas(){
    this->cantidadUsos = 3;
    this->cantidadDano = 15;
    texturaEspada.loadFromFile("../Img/enemigo2.png");
    spriteEspada.setTexture(texturaEspada);
}

void Espada::reducirResistencia(){
    this->cantidadUsos = this->cantidadUsos - 1;
}

void Espada::pintarItem(RenderWindow *ventana, int x, int y){
    cargarTexturas();
    spriteEspada.setPosition(x,y);
    ventana->draw(spriteEspada);
}

FloatRect Espada::getColision() {
    return spriteEspada.getGlobalBounds();
}
