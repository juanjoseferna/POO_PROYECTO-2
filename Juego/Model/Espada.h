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
    Texture texturaEspada;//textura de la espada
    int suelo = 1;
public:
    Espada();
    virtual ~Espada();//destructor
    void cargarTexturas() override;//carga la textura de espada
    void reducirResistenciaEspada();//reducir resistencia del arma
    void pintarItem(RenderWindow * ventana, int x, int y) override;//pintar item en ventana
    void recogerItemSuelo() override;//recoger item del suelo
    FloatRect getColision() override;//colision del personaje
    int getSuelo() override;
    void usarItem(Jugador * jugador) override;//utiliza el item y hace su funcion
    void pintarItemInventario(RenderWindow *ventana, int x, int y) override;//pintar item en inventario
};


#endif //PROYECTOJUEGO_ESPADA_H
