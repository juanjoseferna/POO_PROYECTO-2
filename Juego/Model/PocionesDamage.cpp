//
// Created by finch on 28/05/2021.
//

#include "PocionesDamage.h"

#include "PocionesDamage.h"
PocionesDamage::PocionesDamage() {
    efectoPocion = 15;
}

void PocionesDamage::utilizarPocionDamage(Jugador *jugador){
    jugador->setDamage(jugador->getDamage() + efectoPocion);
}