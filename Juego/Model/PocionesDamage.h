//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONESDAMAGE_H
#define PROYECTOJUEGO_POCIONESDAMAGE_H

#include <SFML/Graphics.hpp>
#include "Pociones.h"
#include "Jugador.h"

class PocionesDamage {
private:
    int efectoPocion;
    sf::Texture texturaPocionDamage;
public:
    sf::Sprite spritePocionD;
    PocionesDamage();
    void utilizarPocionDamage(Jugador *jugador);
    virtual void cargarTexturasPocionDamage();
    virtual void pintarItem(RenderWindow *ventana, int x, int y);
};


#endif //PROYECTOJUEGO_POCIONESDAMAGE_H