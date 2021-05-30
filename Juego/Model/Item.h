//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_ITEM_H
#define PROYECTOJUEGO_ITEM_H

#include <SFML/Graphics.hpp>
#include "Jugador.h"

using namespace sf;

class Item {//clase abstracta
public:
    Item();
    Sprite spriteItem;
    virtual ~Item();//destructor
    virtual void pintarItem(RenderWindow *ventana, int x, int y) = 0; //pintar item en mapa
    virtual void cargarTexturas() = 0;//cargar las texturas
    virtual FloatRect getColision() = 0;
    virtual void recogerItemSuelo() = 0;//recoger item del suelo
    virtual void usarItem(Jugador * jugador) = 0;//utilizar un item y que haga su funcion
    virtual int getSuelo() = 0;
    virtual void pintarItemInventario(RenderWindow *ventana, int x, int y) = 0;//pintar item en el inventario
};


#endif //PROYECTOJUEGO_ITEM_H
