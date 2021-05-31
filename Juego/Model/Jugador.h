//
// Created by finch on 20/05/2021.
//

#ifndef PROYECTOJUEGO_JUGADOR_H
#define PROYECTOJUEGO_JUGADOR_H

#include <SFML/Graphics.hpp>
#include "Personaje.h"
#include <iostream>

using namespace sf;

class Jugador : public Personaje{
private:
    Texture Herz;                                           //Imagen de Herz
    View camara;                                            //Camara de Herz
    int fotogram = 0, direccion = 0, sizeA = 48, sizeB = 48;//Fotograma de animacion, direccion de jugador y tamaño recuadro
    int ataqueEspecial;                                     //Daño del ataque especial
    Clock reloj;                                            //Reloj, usado para la animacion
public:
    bool artefacto = false;                                 //variable para saber si el artefacto esta
    Sprite spriteHerz;                                      //Sprite de Herz
    float cordX, cordY;                                     //Coordenadas Y/X invertidas jaja
    float velocidad;                                        //Velocidad a la que se mueve Herz
    Jugador();//Constructor default de inventario
    virtual ~Jugador();
    void usarArtefacto();                                   //funcion cambia el valor de artefacto
    void crearJugador();                                    //Le carga la imagen y el sprite
    void mostrarJugador(RenderWindow * ventana);            //Dibuja el jugador
    void moverse();                                         //Mueve al jugador
    int getAtaqueEspecial();                                //Retorna el daño del ataque especial
    FloatRect getColision();                                //Retorna el rectangulo de
};


#endif //PROYECTOJUEGO_JUGADOR_H
