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
    int botonx1 = 220, botonx2 = 400 ,botonx3 = 444, botonx4 = 621, botonx5 = 670, botonx6 = 840, botonx7 = 890, botonx8 = 1060;
    int botony1 = 180, botony2 = 342, botony3 = 370, botony4 = 530, botony5 = 550, botony6 = 717;
    int menuSalidax1 = 1226, menuSalidax2 = 1280, menuSaliday1 = 0, menuSaliday2 = 42;
public:
    Sprite spriteInventario;
    Inventario();
    virtual ~Inventario();
    void mostarItemsInventario(RenderWindow * ventana);
    void mostrarInventario(RenderWindow * ventana, Jugador * jugador);
    void botonesInventario(RenderWindow * ventana, Jugador * jugador);
    void agregarItemsInventario(Item* item);
    void eliminarItem(Item * item);
    vector<Item *> &getListaItems();
};


#endif //PROYECTOJUEGO_INVENTARIO_H
