//
// Created by finch on 28/05/2021.
//

#include "Lanza.h"

Lanza::Lanza() : Item(){
    this->cantidadUsos = 3; //cantidad de usos para el arma
    this->cantidadDano = 10;//cantidad del daño
}

Lanza::~Lanza(){}

void Lanza::cargarTexturas(){ //carga la textura del hacha
    texturaLanza.loadFromFile("../Img/hacha.png");
}

void Lanza::reducirResistenciaLanza(){ //reduce la cantidad de usos del arma
    this->cantidadUsos = this->cantidadUsos-1;
}

void Lanza::pintarItem(RenderWindow *ventana, int x, int y) { //pinta el arma en ventana
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

void Lanza::pintarItemInventario(RenderWindow *ventana, int x, int y){ //pintar el hacha en el inventario
    spriteItem.setPosition(x, y);
    cargarTexturas();
    spriteItem.setTexture(texturaLanza);
    if (Lanza::suelo == 0){
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

void Lanza::recogerItemSuelo(){//recoge item del suelo
    suelo = 0;
}

int Lanza::getSuelo(){
    return suelo;
}

void Lanza::usarItem(Jugador *jugador) {//usa el hacha y hace su efecto
    if (cantidadUsos > 0) {
        jugador->setDamage(cantidadDano);
        cantidadUsos --;
    } else {
        jugador->setDamage(0);
    }
}