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
#include "Item.h"
#include "Espada.h"
#include "Lanza.h"
#include "PocionesVida.h"

using namespace sf;
using std::vector;

class Mapa{
private:
    Inventario inventario;
    int itemsMapa = 10;
    vector<Item *> items;
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
    void mostrarItems(RenderWindow * ventana,Jugador * jugador);
    void colisionItems(Jugador * jugador, Item * item);
};

#endif //PROYECTOJUEGO_MAPA_H
