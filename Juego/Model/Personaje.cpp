//
// Created by finch on 24/05/2021.
//

#include "Personaje.h"

Personaje::Personaje() {
    this->vida = 50;
    this->puntosDamage = 10;
}

Personaje::Personaje(int vida, int puntosDamage){
    this->vida = vida;
    this->puntosDamage = puntosDamage;
}

void Personaje::perderVida(int puntosDamage) {
    vida -= puntosDamage;
}
int Personaje::getVida(){
    return vida;
}
int Personaje::getDamage() {
    return puntosDamage;
}

