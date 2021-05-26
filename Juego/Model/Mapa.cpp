//
// Created by criska on 24/05/2021.
//

#include "Mapa.h"

Mapa::Mapa()
{
}


Mapa::~Mapa(){
}

void Mapa::mostrarMapa(sf::RenderWindow *ventana, Jugador * jugador){
    Event evento{};
    while(!Keyboard::isKeyPressed(Keyboard::Escape)) {
        ventana->clear();
        texturaMapa.loadFromFile("../Img/Map002.png");
        spriteMapa.setTexture(texturaMapa);
        ventana->draw(spriteMapa);
        jugador->mostrarJugador(ventana);
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana->close();
        }
        ventana->display();
    }
}
