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
    texturaLanza.loadFromFile("../Img/lanzaProv.png");
}

void Lanza::reducirResistenciaLanza(){
    this->cantidadUsos = this->cantidadUsos-1;
}

void Lanza::pintarItem(RenderWindow *ventana, int x, int y) {
    spriteItem.setPosition(x, y);
    cargarTexturas();
    spriteItem.setTexture(texturaLanza);
    if (Lanza::suelo == 1){
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

FloatRect Lanza::getColision(){

}

void Lanza::pintarItemInventario(RenderWindow *ventana, int x, int y){
    spriteItem.setPosition(x, y);
    cargarTexturas();
    spriteItem.setTexture(texturaLanza);
    if (Lanza::suelo == 0){
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

void Lanza::recogerItemSuelo(){
    suelo = 0;
}

int Lanza::getSuelo(){
    return suelo;
}