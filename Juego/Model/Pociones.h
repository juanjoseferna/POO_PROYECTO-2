//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONES_H
#define PROYECTOJUEGO_POCIONES_H

#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Jugador.h"

class Pociones : public Item{
public:
    Pociones();
    virtual ~Pociones();
    virtual void usarPocion(Jugador * jugador) = 0;
    virtual void pintarItem(RenderWindow *ventana, int x, int y) = 0;
    virtual void cargarTexturas() = 0;
    virtual FloatRect getColision() = 0;
};


#endif //PROYECTOJUEGO_POCIONES_H
