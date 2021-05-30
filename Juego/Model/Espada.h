//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_ESPADA_H
#define PROYECTOJUEGO_ESPADA_H

#include "Item.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Espada : public Item{
private:
    int cantidadUsos;
    int cantidadDano;
    Texture texturaEspada;
    int suelo = 1;
public:
    Espada();
    virtual ~Espada();
    void cargarTexturas() override;
    void reducirResistenciaEspada();
    void pintarItem(RenderWindow * ventana, int x, int y) override;
    void recogerItemSuelo() override;
    FloatRect getColision() override;
    int getSuelo() override;
    void pintarItemInventario(RenderWindow *ventana, int x, int y) override;
};


#endif //PROYECTOJUEGO_ESPADA_H
