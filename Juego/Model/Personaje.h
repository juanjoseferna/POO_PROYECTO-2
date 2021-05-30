//
// Created by finch on 24/05/2021.
//

#ifndef PROYECTOJUEGO_PERSONAJE_H
#define PROYECTOJUEGO_PERSONAJE_H


class Personaje{
protected:
    int vida, puntosDamage, vidaAdicional = 0, damageAdicional = 0;
    Personaje();
    Personaje(int,int);

public:
    int getVida();// obtener vida jugador
    void setVida(int);// enviar vida jugador
    void setDamage(int);// enviar daño jugador
    void perderVida(int); //recibe el daño y el jugador pierde esa vida
    int getDamage(); // obtener daño jugador
};


#endif //PROYECTOJUEGO_PERSONAJE_H
