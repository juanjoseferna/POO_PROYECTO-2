//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_ESPADA_H
#define PROYECTOJUEGO_ESPADA_H

#include "Item.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Espada : public Item{
private:
    int cantidadUsos;
    int cantidadDano;
    Texture texturaEspada;
public:
    Sprite spriteEspada;
    Espada();
    virtual ~Espada();
    void cargarTexturas() override;
    void reducirResistencia() override;
    void pintarItem(RenderWindow * ventana, int x, int y);
    FloatRect getColision() override;
};


#endif //PROYECTOJUEGO_ESPADA_H
