//
// Created by finch on 28/05/2021.
//

#include "PocionesVida.h"
PocionesVida::PocionesVida() {
    efectoPocion = 50;
}

void PocionesVida::utilizarPocionVida(Jugador *jugador){
    jugador->setVida(jugador->getVida() + efectoPocion);
}
void PocionesVida::cargarTexturasPocionVida(){
    texturaPocionVida.loadFromFile("../Img/pocionVida.png");
    spritePocion.setTexture(texturaPocionVida);
}

void PocionesVida::pintarItem(RenderWindow *ventana, int x, int y){
    cargarTexturasPocionVida();
    spritePocion.setPosition(x,y);
    ventana->draw(spritePocion);
}

FloatRect PocionesVida::getColision() {
    return spritePocion.getGlobalBounds();
}