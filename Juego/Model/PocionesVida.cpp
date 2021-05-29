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