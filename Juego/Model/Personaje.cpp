//
// Created by finch on 24/05/2021.
//

#include "Personaje.h"

Personaje::Personaje() {
    this->vida = 50;
    this->puntosDamage = 10;
    this->vidaAdicional = 0;
    this->damageAdicional = 0;
}

Personaje::Personaje(int vida, int puntosDamage){
    this->vida = vida;
    this->puntosDamage = puntosDamage;
    this->vidaAdicional = 0;
    this->damageAdicional = 0;
}

void Personaje::perderVida(int puntosDamage) {
    vida -= puntosDamage; //pierde vida personaje con un ataque
}
int Personaje::getVida(){
    return vida + vidaAdicional; //obtiene la vida actual
}
int Personaje::getDamage() {
    return puntosDamage + damageAdicional; //obtiene el daño
}

void Personaje::setVida(int vida) {
    this->vidaAdicional += vida; //envia la vida actual
}

void Personaje::setDamage(int puntosDamage) {
    this->damageAdicional = puntosDamage; //envia el daño actual
}



