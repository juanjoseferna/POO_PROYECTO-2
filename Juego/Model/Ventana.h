//
// Created by finch on 20/05/2021.
//

#ifndef PROYECTOJUEGO_VENTANA_H
#define PROYECTOJUEGO_VENTANA_H

#include <SFML/Graphics.hpp>

using namespace sf;


class Ventana {
private:
    int ancho, largo;
    int x1Inico = 224, x2Inicio = 503, y1Inicio = 191, y2Inicio = 273;
    int x1Salida = 244, x2Salida = 480, y1Salida = 308, y2Salida = 376;
    Texture menu, menuSalida, menuInicio;
    Image icono;
public:
    Ventana();
    void crearVentana();
};


#endif //PROYECTOJUEGO_VENTANA_H
