//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONES_H
#define PROYECTOJUEGO_POCIONES_H

#include <SFML/Graphics.hpp>
#include "Item.h"

class Pociones : public Item{
public:
    Pociones();
    virtual void usarPocion() = 0;
};


#endif //PROYECTOJUEGO_POCIONES_H
