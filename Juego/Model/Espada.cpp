//
// Created by finch on 28/05/2021.
//

#include "Espada.h"
Espada::Espada() : Item (){
}

Espada::~Espada(){
}

void Espada::cargarTexturas(){
    this->cantidadUsos = 3;//cantidad de usos
    this->cantidadDano = 15;//cantidad de daño implementado
    texturaEspada.loadFromFile("../Img/espadaProv.png");//carga la textura de la espada

}

void Espada::reducirResistenciaEspada(){//reduce la cantidad de uso del arma
    this->cantidadUsos = this->cantidadUsos - 1;
}

void Espada::pintarItem(RenderWindow *ventana, int x, int y){//pinta el item espada en ventana
    spriteItem.setPosition(x, y);
    cargarTexturas();
    spriteItem.setTexture(texturaEspada);
    if (Espada::suelo == 1){
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

void Espada::pintarItemInventario(RenderWindow *ventana, int x, int y){//pinta el item espada en el inventario
    spriteItem.setPosition(x, y);
    cargarTexturas();
    spriteItem.setTexture(texturaEspada);
    if (Espada::suelo == 0){
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

void Espada::usarItem(Jugador *jugador) {//usar la espada
    if (cantidadUsos > 0) {
        jugador->setDamage(cantidadDano);
        cantidadUsos --;
    } else {
        jugador->setDamage(0);
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