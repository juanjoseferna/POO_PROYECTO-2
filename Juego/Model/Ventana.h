//
// Created by finch on 20/05/2021.
//

#ifndef PROYECTOJUEGO_VENTANA_H
#define PROYECTOJUEGO_VENTANA_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Jugador.h"
#include "Combate.h"
#include "Mapa.h"
#include "Tile.h"


using namespace sf;

class Ventana {
private:
    RenderWindow ventana;  // aqui se crea la ventana que se va a desplegar una vez vayamos a jugar
    //SoundBuffer musica;
    //Sound sonido;
    const static int ancho, alto;  // variables que definen el ancho y alto de la ventana
    int x1Global = 518, x2Global = 766, y1Inicio = 374, y2Inicio = 445; // se crean dos variables en el eje x que van a ser las mismas para todos los botones y sus respectivos puntos en y.
    int y1Salida = 473, y2Salida = 543; // variables que representan los puntos y del boton salir.
    int y1Facil = 375, y2Facil = 443;   // variables que representan los puntos y del boton pesadilla.
    int y1Normal = 473, y2Normal = 540; // variables que representan los puntos y del boton infernal.
    int y1Volver = 570, y2Volver = 639; // variables que representan los puntos y del boton regresar.
    float cordX, cordY;
    bool salida{};
    Texture menu, menuSalida, menuJugar, dificultad, dificultadFacil, dificultadNormal, dificultadVolver, pj;
    Image icono;
    Clock reloj;
    Sprite sprite;
    Jugador jugador;
    Combate combate;
    Mapa mapa;
public:
    Ventana();
    void crearVentana();
    void menuDificultad();
    RenderWindow * getVentana();
};


#endif //PROYECTOJUEGO_VENTANA_H
