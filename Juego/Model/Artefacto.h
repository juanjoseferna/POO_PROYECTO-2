//
// Created by Usuario on 30/05/2021.
//

#ifndef PROYECTOJUEGO_ARTEFACTO_H
#define PROYECTOJUEGO_ARTEFACTO_H

#include "Item.h"
#include <SFML/Graphics.hpp>

class Artefacto : public Item {
private:
    Texture texturaArtefacto;
    int suelo = 1;
public:
    Artefacto();
    virtual ~Artefacto();
    void pintarItem(RenderWindow *ventana, int x, int y) override; //pintar item en mapa
    void cargarTexturas() override;//cargar las texturas
    FloatRect getColision() override;
    void recogerItemSuelo() override;//recoger item del suelo
    void usarItem(Jugador * jugador) override;//utilizar un item y que haga su funcion
    int getSuelo() override;
    void pintarItemInventario(RenderWindow *ventana, int x, int y) override;//pintar item en el inventario
};

#endif //PROYECTOJUEGO_ARTEFACTO_H
