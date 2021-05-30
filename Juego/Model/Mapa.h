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
#include "PocionesDamage.h"
#include "Boss.h"

using namespace sf;
using std::vector;

class Mapa{
private:
    bool finalizado = false;
    Inventario inventario;
    vector<Item *> items;
    vector<Enemigo> enemigos;
    Texture texturaMapa, salidaTexture;
    Sprite spriteMapa, cofre, salida;
    Combate combate;
    Vector2i posicionSalida;
    Vector2i posicionJugador;
    Texture texturaMuro;
    Sprite spriteMuro;
    Espada espada;
    Lanza lanza;
    PocionesVida pocionVida;
    PocionesDamage pocionDamage;
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
    void crearItems(RenderWindow * ventana,Jugador * jugador);
    void colisionItems(Jugador * jugador, Item * item);
    void colisionBoss(RenderWindow * ventana, Jugador * jugador, Boss * boss);
    void colisionSalida(RenderWindow * ventana, Jugador * jugador, Sprite * salida);
};

#endif //PROYECTOJUEGO_MAPA_H
