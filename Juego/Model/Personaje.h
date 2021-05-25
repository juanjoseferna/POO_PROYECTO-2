//
// Created by finch on 24/05/2021.
//

#ifndef PROYECTOJUEGO_PERSONAJE_H
#define PROYECTOJUEGO_PERSONAJE_H


class Personaje{
private:
    int vida, puntosDamage;
protected:
    Personaje();
    Personaje(int,int);

public:
    int getVida();

    void perderVida(int);

    int getDamage();

    void realizarAtaque();
};


#endif //PROYECTOJUEGO_PERSONAJE_H
