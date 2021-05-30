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
    virtual ~Lanza();//destructor
    void cargarTexturas() override;//carga la textura del arma
    void reducirResistenciaLanza();//reducir la resistencia del arma
    void pintarItem(RenderWindow *ventana, int x, int y) override;//pinta el item en ventana
    FloatRect getColision() override;
    void recogerItemSuelo() override;//recoge item del suelo
    int getSuelo() override;
    void usarItem(Jugador *jugador) override;//usa el hacha y hace el efecto de hacha
    void pintarItemInventario(RenderWindow *ventana, int x, int y) override;//ubica el hacha en inventario
};


#endif //PROYECTOJUEGO_LANZA_H
