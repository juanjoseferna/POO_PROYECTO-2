//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_INVENTARIO_H
#define PROYECTOJUEGO_INVENTARIO_H
#include <SFML/Graphics.hpp>
#include "Item.h"
#include <vector>
#include "Jugador.h"
#include <iostream>

using std::vector;
using namespace sf;

class Inventario {
private:
    bool salida = false;
    Texture texturaInventario;
    vector<Item *> pItems;
    const static int CANTIDAD_MAX_ITEMS;
public:
    Sprite spriteInventario;
    Inventario();
    virtual ~Inventario();
    void mostrarInventario(RenderWindow * ventana, Jugador * jugador);
    void botonesInventario(RenderWindow * ventana);
    void agregarItemsInventario();
};


#endif //PROYECTOJUEGO_INVENTARIO_H
