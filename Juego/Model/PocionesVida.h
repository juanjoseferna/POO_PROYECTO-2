//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONESVIDA_H
#define PROYECTOJUEGO_POCIONESVIDA_H

#include <SFML/Graphics.hpp>
#include "Pociones.h"
#include "Jugador.h"

class PocionesVida : public Pociones{
private:
    int efectoPocion;
    sf::Texture texturaPocionVida;
public:
    sf::Sprite spritePocion;
    PocionesVida();
    virtual void utilizarPocionVida(Jugador *jugador);
    virtual void cargarTexturasPocionVida();
    virtual void pintarItem(RenderWindow *ventana, int x, int y);
    FloatRect getColision() override;
};


#endif //PROYECTOJUEGO_POCIONESVIDA_H
