//
// Created by Usuario on 24/05/2021.
//

#ifndef PROYECTOJUEGO_MAPA_H
#define PROYECTOJUEGO_MAPA_H
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>

class Mapa{
private:
    sf::Vector2i posicionSalida;
    sf::Vector2i posicionJugador;
    std::vector<sf::Vector2i> posicionEnemigos;
    void configurarTiles();
    void configurarPosicionEnemigos();
    void configurarEstadoInicial();
public:
    Mapa();
    virtual ~Mapa();
    std::vector<std::vector<Tile*> > tiles;
    int sizeMapa;
    void mostrarMapa(sf::RenderWindow *ventana);

};

#endif //PROYECTOJUEGO_MAPA_H
