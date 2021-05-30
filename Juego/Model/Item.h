//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_ITEM_H
#define PROYECTOJUEGO_ITEM_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Item {
public:
    Item();
    Sprite spriteItem;
    virtual ~Item();
    virtual void pintarItem(RenderWindow *ventana, int x, int y) = 0;
    virtual void cargarTexturas() = 0;
    virtual FloatRect getColision() = 0;
    virtual void recogerItemSuelo() = 0;
    virtual int getSuelo() = 0;
    virtual void pintarItemInventario(RenderWindow *ventana, int x, int y) = 0;
};


#endif //PROYECTOJUEGO_ITEM_H
