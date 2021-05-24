//
// Created by finch on 20/05/2021.
//

#ifndef PROYECTOJUEGO_VENTANA_H
#define PROYECTOJUEGO_VENTANA_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Ventana {
private:
    RenderWindow ventana;  // aqui se crea la ventana que se va a desplegar una vez vayamos a jugar
    const static int ancho, alto;  // variables que definen el ancho y alto de la ventana
    int x1Global = 518, x2Global = 766, y1Inicio = 374, y2Inicio = 445; // se crean dos variables en el eje x que van a ser las mismas para todos los botones y sus respectivos puntos en y.
    int y1Salida = 473, y2Salida = 543; // variables que representan los puntos y del boton salir.
    int y1Facil = 375, y2Facil = 443;   // variables que representan los puntos y del boton pesadilla.
    int y1Normal = 473, y2Normal = 540; // variables que representan los puntos y del boton infernal.
    int y1Volver = 570, y2Volver = 639; // variables que representan los puntos y del boton regresar.
    float cordX, cordY;
    int a = 0, b = 0, c = 48, d = 48;
    bool salida{};
    Texture menu, menuSalida, menuJugar, dificultad, dificultadFacil, dificultadNormal, dificultadVolver, pj;
    Image icono;
    Clock reloj;
    Sprite sprite, nave;
    IntRect rectSource;
public:
    Ventana();
    void crearVentana();
    void menuDificultad();
    void moverse();
};


#endif //PROYECTOJUEGO_VENTANA_H
