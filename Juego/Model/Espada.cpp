//
// Created by finch on 28/05/2021.
//

#include "Espada.h"

Espada::Espada()
{
    this->cantidadUsos = 3;
    this->cantidadDano = 15;
}


Espada::~Espada(){}

void Espada::cargarTexturas()
{
    texturaEspada.loadFromFile("../Img/enemigo2.png");
    spriteEspada.setTexture(texturaEspada);

}

void Espada::reducirResistencia(){
    this->cantidadUsos = this->cantidadUsos - 1;
}





