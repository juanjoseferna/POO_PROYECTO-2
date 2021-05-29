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
public:
    PocionesDamage();
    void utilizarPocionDamage(Jugador *jugador);
};


#endif //PROYECTOJUEGO_POCIONESDAMAGE_H
