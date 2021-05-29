//
// Created by Usuario on 24/05/2021.
//

#ifndef PROYECTOJUEGO_MAPA_H
#define PROYECTOJUEGO_MAPA_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <vector>
#include "Jugador.h"
#include "Enemigo.h"
#include "Combate.h"
#include "Inventario.h"

using namespace sf;
using std::vector;

class Mapa{
private:
    Inventario inventario;
    vector<Enemigo> enemigos;
    Texture texturaMapa;
    Sprite spriteMapa, cofre;
    Combate combate;
    Vector2i posicionSalida;
    Vector2i posicionJugador;
    Texture texturaMuro;
    Sprite spriteMuro;
public:
    Mapa();
    virtual ~Mapa();
    int sizeMapa;
    void colisiones(Jugador * jugador, Sprite& objeto);
    void mostrarMapa(RenderWindow *ventana, Jugador * jugador, int cantEnemigos);
    void dibujarCofre(RenderWindow *ventana);
    void crearMapa(RenderWindow *ventana, Jugador * jugador);
    void colisionesEnemigo(RenderWindow * ventana,Jugador * jugador, Enemigo * enemigo);
    void crearEnemigos(RenderWindow *ventana, Jugador *jugador, int cantEnemigos);
    void abrirInventario(RenderWindow * ventana,Jugador * jugador);
};

#endif //PROYECTOJUEGO_MAPA_H
