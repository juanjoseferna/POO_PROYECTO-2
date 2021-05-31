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
#include "Artefacto.h"

using namespace sf;
using std::vector;

class Mapa{
private:
    Inventario inventario; // objeto de la clase inventario
    vector<Item *> items;//vector utilizado para items
    vector<Enemigo> enemigos;//vector de enemigos
    Texture texturaMapa, salidaTexture;
    Sprite spriteMapa, cofre, salida;
    Combate combate;
    Texture texturaMuro;
    Sprite spriteMuro;
public:
    Mapa();
    virtual ~Mapa();//destructor
    int sizeMapa;
    void colisiones(Jugador * jugador, Sprite& objeto);//colisiones en mapa
    void mostrarMapa(RenderWindow *ventana, Jugador * jugador, int cantEnemigos);//mostrar mapa en ventana
    void dibujarCofre(RenderWindow *ventana);//dibuja el cofre en el mapa
    void crearMapa(RenderWindow *ventana, Jugador * jugador);//crea mapa en ventana
    void colisionesEnemigo(RenderWindow * ventana,Jugador * jugador, Enemigo * enemigo);//colisiones con los enemigos
    void crearEnemigos(RenderWindow *ventana, Jugador *jugador, int cantEnemigos);//crear enemigos en el mapa
    void abrirInventario(RenderWindow * ventana,Jugador * jugador);//abrir inventario en mapa
    void crearItems(RenderWindow * ventana,Jugador * jugador);//crear items en mapa
    void colisionItems(Jugador * jugador, Item * item);//colisiones con los items en mapa
    void colisionBoss(RenderWindow * ventana, Jugador * jugador, Boss * boss);//colision con el boss
    void colisionSalida(RenderWindow * ventana, Jugador * jugador, Sprite * salida);//colision de salida del juego
};

#endif //PROYECTOJUEGO_MAPA_H
