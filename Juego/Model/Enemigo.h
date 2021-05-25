//
// Created by finch on 24/05/2021.
//

#ifndef PROYECTOJUEGO_ENEMIGO_H
#define PROYECTOJUEGO_ENEMIGO_H

#include "Personaje.h"

class Enemigo : public Personaje{
public:
    Enemigo();
    void perderVidaEnemigo();
    void RealizarAtaqueEnemigo();

};


#endif //PROYECTOJUEGO_ENEMIGO_H
