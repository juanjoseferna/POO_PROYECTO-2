//
// Created by finch on 28/05/2021.
//

#include "PocionesVida.h"
PocionesVida::PocionesVida() {
    efectoPocion = 50;
}

void PocionesVida::usarPocion(Jugador *jugador){
    jugador->setVida(jugador->getVida() + efectoPocion); //efecto pocion a jugador
}

void PocionesVida::cargarTexturas(){
    texturaPocionVida.loadFromFile("../Img/pocionVida.png");//carga la textura
    spritePocion.setTexture(texturaPocionVida);
}

void PocionesVida::pintarItem(RenderWindow * ventana, int x, int y){
    spriteItem.setPosition(x, y);
    if (PocionesVida::suelo == 1){
        cargarTexturas();
        spriteItem.setTexture(texturaPocionVida);
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

FloatRect PocionesVida::getColision() {
    return spritePocion.getGlobalBounds();
}

void PocionesVida::recogerItemSuelo(){
    suelo = 0;
}

int PocionesVida::getSuelo() {
    return suelo;
}

void PocionesVida::pintarItemInventario(RenderWindow *ventana, int x, int y) {
    spriteItem.setPosition(x, y);
    spriteItem.setTexture(texturaPocionVida);
    if(PocionesVida::suelo == 0){
        ventana->draw(spriteItem);
    }else{
        return;
    }
}

void PocionesVida::usarItem(Jugador *jugador) {
    jugador->setVida(efectoPocion);
    efectoPocion = 0;
    texturaPocionVida.loadFromFile("../Img/pocionVacia.png"); //carga la textura una vez seutilice la pocion
}