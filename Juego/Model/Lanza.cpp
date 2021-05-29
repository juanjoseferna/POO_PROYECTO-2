//
// Created by finch on 28/05/2021.
//

#include "Lanza.h"

Lanza::Lanza()
{
    this->cantidadUsos = 3;
    this->cantidadDano = 10;
}

Lanza::~Lanza(){}

void Lanza::cargarTexturas()
{
    texturaLanza.loadFromFile("../Img/enemigo2.png");
    spriteLanza.setTexture(texturaLanza);
}

void Lanza::reducirResistencia()
{
    this->cantidadUsos = this->cantidadUsos-1;
}
