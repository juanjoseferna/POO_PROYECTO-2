//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONESDAMAGE_H
#define PROYECTOJUEGO_POCIONESDAMAGE_H

#include <SFML/Graphics.hpp>
#include "Pociones.h"
#include "Jugador.h"

class PocionesDamage : public Pociones{
private:
    int efectoPocion;
    sf::Texture texturaPocionDamage;
public:
    sf::Sprite spritePocionD;
    PocionesDamage();
    virtual ~PocionesDamage();
    void usarPocion(Jugador * jugador) override;
    void cargarTexturas() override;
    void pintarItem(RenderWindow *ventana, int x, int y) override;
    FloatRect getColision() override;
};


#endif //PROYECTOJUEGO_POCIONESDAMAGE_H