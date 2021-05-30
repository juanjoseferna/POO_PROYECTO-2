//
// Created by finch on 28/05/2021.
//

#include "Espada.h"
Espada::Espada() : Item (){
    suelo = true;
}

Espada::~Espada(){
}

void Espada::cargarTexturas(){
    this->cantidadUsos = 3;
    this->cantidadDano = 15;
    texturaEspada.loadFromFile("../Img/espadaProv.png");

}

void Espada::reducirResistenciaEspada(){
    this->cantidadUsos = this->cantidadUsos - 1;
}

void Espada::pintarItem(RenderWindow *ventana, int x, int y){
    spriteItem.setPosition(x, y);
    cargarTexturas();
    spriteItem.setTexture(texturaEspada);
    if (Espada::suelo == 1){
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

void Espada::pintarItemInventario(RenderWindow *ventana, int x, int y){
    spriteItem.setPosition(x, y);
    cargarTexturas();
    spriteItem.setTexture(texturaEspada);
    if (Espada::suelo == 0){
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

FloatRect Espada::getColision() {
    return spriteItem.getGlobalBounds();
}

void Espada::recogerItemSuelo(){
    suelo = 0;
}

int Espada::getSuelo(){
    return suelo;
}