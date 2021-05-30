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
    void usarPocion(Jugador *jugador) override;
    void cargarTexturas() override;
    void pintarItem(RenderWindow *ventana, int x, int y) override;
    FloatRect getColision() override;
};


#endif //PROYECTOJUEGO_POCIONESVIDA_H
