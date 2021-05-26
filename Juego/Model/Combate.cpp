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
        if (enemigo.getVida() <= 0){
            std::cout << "Ganaste" << std::endl;
            salida = true;
        }
        if (jugador->getVida() <= 0){
            std::cout << "Perdiste" << std::endl;
            salida = true;
        }
        Event evento{};
        ventana->clear();
        ventana->draw(sprite);
        if(Mouse::getPosition(*ventana).x >= x1Rosa &&
           Mouse::getPosition(*ventana).x <= x2Rosa &&
           Mouse::getPosition(*ventana).y >= y1Rosa &&
           Mouse::getPosition(*ventana).y <= y2Rosa &&
           sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)){
                enemigo.perderVida(jugador->getDamage());
                jugador->perderVida(enemigo.getDamage());
                std::cout << "Puntos vida: " << jugador->getVida() << std::endl;
                std::cout << "Puntos vida enemigo: " << enemigo.getVida() << std::endl;
                std::cout << "Boton Rosado" << std::endl;
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Verde &&
                Mouse::getPosition(*ventana).x <= x2Verde &&
                Mouse::getPosition(*ventana).y >= y1Verde &&
                Mouse::getPosition(*ventana).y <= y2Verde &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {
                std::cout << "Boton Verde" << std::endl;
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Naranja &&
                Mouse::getPosition(*ventana).x <= x2Naranja &&
                Mouse::getPosition(*ventana).y >= y1Naranja &&
                Mouse::getPosition(*ventana).y <= y2Naranja &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
                if(Mouse::isButtonPressed(Mouse::Left)) {
                    std::cout << "Boton Naranja" << std::endl;
                }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Azul &&
                Mouse::getPosition(*ventana).x <= x2Azul &&
                Mouse::getPosition(*ventana).y >= y1Azul &&
                Mouse::getPosition(*ventana).y <= y2Azul &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {
                std::cout << "Boton Azul" << std::endl;
            }
        }
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana->close();
        }
        ventana->display();
    }
}