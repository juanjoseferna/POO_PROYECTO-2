//
// Created by criska on 24/05/2021.
//


#ifndef PROYECTOJUEGO_MAPA_H
#define PROYECTOJUEGO_MAPA_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Jugador.h"

class Mapa{
private:
    sf::Texture texturaMapa;
    sf::Sprite spriteMapa;
    sf::Texture texturaMuro;
    sf::Sprite spriteMuro;
public:
    Mapa();
    virtual ~Mapa();
    void mostrarMapa(sf::RenderWindow *ventana, Jugador * jugador);
};



#endif //PROYECTOJUEGO_MAPA_H
