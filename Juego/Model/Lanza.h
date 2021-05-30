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
    Texture texturaLanza;
    int suelo = 1;
public:
    Lanza();
    virtual ~Lanza();
    void cargarTexturas() override;
    void reducirResistenciaLanza();
    void pintarItem(RenderWindow *ventana, int x, int y) override;
    FloatRect getColision() override;
    void recogerItemSuelo() override;
    int getSuelo() override;
    void pintarItemInventario(RenderWindow *ventana, int x, int y) override;
};


#endif //PROYECTOJUEGO_LANZA_H
