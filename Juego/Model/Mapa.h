//
// Created by Usuario on 24/05/2021.
//

#ifndef PROYECTOJUEGO_MAPA_H
#define PROYECTOJUEGO_MAPA_H
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>
#include "Jugador.h"

using namespace sf;

class Mapa{
private:
    Texture texturaMapa;
    Sprite spriteMapa, cofre;
    FloatRect colisionCofre;
    Vector2i posicionSalida;
    Vector2i posicionJugador;
    std::vector<Vector2i> posicionEnemigos;
    void configurarTiles();
    void configurarPosicionEnemigos();
    void configurarEstadoInicial();
public:
    Mapa();
    virtual ~Mapa();
    std::vector<std::vector<Tile*> > tiles;
    int sizeMapa;
    void colisiones(Jugador * jugador, const Sprite& objeto);
    void mostrarMapa(RenderWindow *ventana, Jugador * jugador);
    void dibujarCofre(RenderWindow *ventana);

};

#endif //PROYECTOJUEGO_MAPA_H
