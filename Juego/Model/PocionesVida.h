//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONESVIDA_H
#define PROYECTOJUEGO_POCIONESVIDA_H

#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Jugador.h"

class PocionesVida : public Item{
private:
    int efectoPocion;
    sf::Texture texturaPocionVida; //carga la textura
    int suelo = 1;
public:
    sf::Sprite spritePocion;
    PocionesVida();
    void usarPocion(Jugador *jugador); //efecto de la pocion
    void cargarTexturas() override; //carga la textura
    void pintarItem(RenderWindow *ventana, int x, int y) override; //pinta el item en ventana
    FloatRect getColision() override;// colision con el objeto
    void recogerItemSuelo() override; //recoge item del suelo
    int getSuelo() override;
    void usarItem(Jugador * jugador) override;//usa el item y hace el efecto
    void pintarItemInventario(RenderWindow *ventana, int x, int y) override; //pinta el item en el inventario
};


#endif //PROYECTOJUEGO_POCIONESVIDA_H
