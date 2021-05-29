//
// Created by finch on 24/05/2021.
//

#ifndef PROYECTOJUEGO_PERSONAJE_H
#define PROYECTOJUEGO_PERSONAJE_H


class Personaje{
protected:
    int vida, puntosDamage;
    Personaje();
    Personaje(int,int);

public:
    int getVida();
    void setVida(int);
    void setDamage(int);
    void perderVida(int);
    int getDamage();
};


#endif //PROYECTOJUEGO_PERSONAJE_H
