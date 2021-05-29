//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_ESPADA_H
#define PROYECTOJUEGO_ESPADA_H

#include "Item.h"
#include <SFML/Graphics.hpp>

class Espada : public Item{
private:
    int cantidadUsos;
    int cantidadDano;
    sf::Texture texturaEspada;
public:
    sf::Sprite spriteEspada;
    Espada();
    virtual ~Espada();
    virtual void cargarTexturas();
    virtual void reducirResistencia();
};


#endif //PROYECTOJUEGO_ESPADA_H
