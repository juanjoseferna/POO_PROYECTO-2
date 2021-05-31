//
// Created by Usuario on 30/05/2021.
//

#include "Artefacto.h"

Artefacto::Artefacto(){
    texturaArtefacto.loadFromFile("../Img/Artefacto.png");
}

void Artefacto::cargarTexturas(){
    texturaArtefacto.loadFromFile("../Img/Artefacto.png");
}

void Artefacto::pintarItem(RenderWindow *ventana, int x, int y) {
    if (Artefacto::suelo == 1){
        cargarTexturas();
        spriteItem.setTexture(texturaArtefacto);
        spriteItem.setPosition(x,y);
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

FloatRect Artefacto::getColision(){
    return spriteItem.getGlobalBounds();
}

void Artefacto::recogerItemSuelo(){
    suelo = 0;
}

void Artefacto::usarItem(Jugador * jugador){
    jugador->usarArtefacto();
}
int Artefacto::getSuelo(){
    return suelo;
}
void Artefacto::pintarItemInventario(RenderWindow *ventana, int x, int y){
    spriteItem.setTexture(texturaArtefacto);
    if (Artefacto::suelo == 0){
        spriteItem.setPosition(x,y);
        ventana->draw(spriteItem);
    } else {
        return;
    }
}

Artefacto::~Artefacto(){
}