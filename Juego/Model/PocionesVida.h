//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONESVIDA_H
#define PROYECTOJUEGO_POCIONESVIDA_H

#include <SFML/Graphics.hpp>
#include "Pociones.h"
#include "Jugador.h"

class PocionesVida : public Pociones{
private:
    int efectoPocion;
public:
    PocionesVida();
    void utilizarPocionVida(Jugador *jugador);
};


#endif //PROYECTOJUEGO_POCIONESVIDA_H
