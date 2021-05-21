//
// Created by finch on 20/05/2021.
//

#ifndef PROYECTOJUEGO_VENTANA_H
#define PROYECTOJUEGO_VENTANA_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Ventana {
private:
    RenderWindow ventana;
    int ancho, largo;
    int x1Inico = 224, x2Inicio = 503, y1Inicio = 191, y2Inicio = 273; //TODO: cambiar las imagenes a unas mas bonitas
    int x1Salida = 244, x2Salida = 480, y1Salida = 308, y2Salida = 376;//Con eso cambiar estas variables
    int x1Facil = 284, x2Facil = 464, y1Facil = 204, y2Facil = 260;    //Provisional
    int x1Normal = 223, x2Normal = 508, y1Normal = 306, y2Normal = 360;//Provisional
    int x1Volver = 570, x2Volver = 715, y1Volver = 433, y2Volver = 469;//Provisional
    bool salida;
    Texture menu, menuSalida, menuJugar, dificultad, dificultadFacil, dificultadNormal, dificultadVolver;
    Image icono;
    Sprite sprite;
public:
    Ventana();
    void crearVentana();
    void menuDificultad();
};


#endif //PROYECTOJUEGO_VENTANA_H
