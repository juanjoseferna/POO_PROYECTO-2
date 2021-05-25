//
// Created by finch on 24/05/2021.
//

#include "Combate.h"
Combate::Combate() {
    this->turno = 0;
    this->turnoEnemigo = 0;
}

void Combate::mostrarCombate(RenderWindow * ventana, Jugador * jugador) {
    fondoPelea.loadFromFile("../Img/peleaMenu2.png");
    bool salida = false;
    sprite.setTexture(fondoPelea);
    while(!salida){
        if (!enemigo.getVida())
            salida = true;
        if (!jugador->getVida())
            salida = true;
        Event evento{};
        ventana->clear();
        ventana->draw(sprite);
        if(Mouse::getPosition(*ventana).x >= x1Huir &&
           Mouse::getPosition(*ventana).x <= x2Huir &&
           Mouse::getPosition(*ventana).y >= y1Huir &&
           Mouse::getPosition(*ventana).y <= y2Huir &&
           sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)){
                enemigo.perderVida(jugador->getDamage());
                jugador->perderVida(enemigo.getDamage());
                std::cout << "Puntos vida: " << jugador->getVida() << std::endl;
                std::cout << "Puntos vida enemigo: " << enemigo.getVida() << std::endl;
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Rojo &&
           Mouse::getPosition(*ventana).x <= x2Rojo &&
           Mouse::getPosition(*ventana).y >= y1Rojo &&
           Mouse::getPosition(*ventana).y <= y2Rojo &&
           sprite.getTexture() == &fondoPelea &&
           Mouse::isButtonPressed(Mouse::Left)){
        }
        else if(Mouse::getPosition(*ventana).x >= x1Verde &&
                Mouse::getPosition(*ventana).x <= x2Verde &&
                Mouse::getPosition(*ventana).y >= y1Verde &&
                Mouse::getPosition(*ventana).y <= y2Verde &&
                sprite.getTexture() == &fondoPelea &&
                Mouse::isButtonPressed(Mouse::Left)){
        }
        else if(Mouse::getPosition(*ventana).x >= x1Naranja &&
                Mouse::getPosition(*ventana).x <= x2Naranja &&
                Mouse::getPosition(*ventana).y >= y1Naranja &&
                Mouse::getPosition(*ventana).y <= y2Naranja &&
                sprite.getTexture() == &fondoPelea &&
                 Mouse::isButtonPressed(Mouse::Left)){
        }
        else if(Mouse::getPosition(*ventana).x >= x1Azul &&
                Mouse::getPosition(*ventana).x <= x2Azul &&
                Mouse::getPosition(*ventana).y >= y1Azul &&
                Mouse::getPosition(*ventana).y <= y2Azul &&
                sprite.getTexture() == &fondoPelea &&
                Mouse::isButtonPressed(Mouse::Left)){
        }
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana->close();
        }
        ventana->display();
    }
}