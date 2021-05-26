//
// Created by Usuario on 24/05/2021.
//

#ifndef PROYECTOJUEGO_MAPA_H
#define PROYECTOJUEGO_MAPA_H
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include <vector>
#include "Jugador.h"
#include "Enemigo.h"
#include "Combate.h"

using namespace sf;

class Mapa{
private:
    Enemigo enemigo;
    Texture texturaMapa;
    Sprite spriteMapa, cofre;
    FloatRect colisionCofre;
    Vector2i posicionSalida;
    Vector2i posicionJugador;
    Texture texturaMuro;
    Sprite spriteMuro;
    std::vector<Vector2i> posicionEnemigos;
public:
    Mapa();
    virtual ~Mapa();
    std::vector<std::vector<Tile*> > tiles;
    int sizeMapa;
    void colisiones(Jugador * jugador, Sprite& objeto);
    void mostrarMapa(RenderWindow *ventana, Jugador * jugador);
    void dibujarCofre(RenderWindow *ventana);
    void crearMapa(RenderWindow *ventana, Jugador * jugador);
    //void colisionesEnemigo(Jugador * jugador, )

};

#endif //PROYECTOJUEGO_MAPA_H
