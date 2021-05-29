//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_LANZA_H
#define PROYECTOJUEGO_LANZA_H

#include "Item.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Lanza : public Item{
protected:
    int cantidadUsos;
    int cantidadDano;
    sf::Texture texturaLanza;
public:
    sf::Sprite spriteLanza;
    Lanza();
    virtual ~Lanza();
    virtual void cargarTexturas() override;
    virtual void reducirResistencia() override;
    virtual void pintarItem(RenderWindow *ventana, int x, int y) override;
    virtual FloatRect getColision() override;
};


#endif //PROYECTOJUEGO_LANZA_H
