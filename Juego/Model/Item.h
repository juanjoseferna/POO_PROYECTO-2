//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_ITEM_H
#define PROYECTOJUEGO_ITEM_H
#include <iostream>
#include <SFML/Graphics.hpp>



class Item {
public:
    Item();
    virtual ~Item();
    virtual void cargarTexturas() = 0;
    virtual void reducirResistencia() = 0;
};


#endif //PROYECTOJUEGO_ITEM_H
