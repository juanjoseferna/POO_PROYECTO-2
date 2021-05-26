//
// Created by criska on 24/05/2021.
//

#include "Mapa.h"
const int ancho = 1440;
const int alto = 960;

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
        dibujarCofre(ventana);
        colisiones(jugador, cofre);
        ventana->display();

    }
}

void Mapa::dibujarCofre(RenderWindow *ventana) {
    Texture cofreTexture;
    cofreTexture.loadFromFile("../Img/cofreCerrado2.png");
    cofre.setTexture(cofreTexture);
    cofre.setPosition(ancho/2,alto/2);
    ventana->draw(cofre);
}

void Mapa::colisiones(Jugador *jugador, const Sprite& objeto) {
    FloatRect colisionObjeto = objeto.getGlobalBounds();
    if (jugador->getColision().intersects(colisionObjeto) &&
        jugador->cordY > cofre.getPosition().x){
        jugador->cordY +=jugador->velocidad;
    } else if (jugador->getColision().intersects(colisionObjeto) &&
               jugador->cordY < cofre.getPosition().x){
        jugador->cordY -=jugador->velocidad;
    }
    if (jugador->getColision().intersects(colisionObjeto) &&
        jugador->cordX > cofre.getPosition().y){
        jugador->cordX +=jugador->velocidad;
    } else if (jugador->getColision().intersects(colisionObjeto) &&
               jugador->cordX < cofre.getPosition().y){
        jugador->cordX -=jugador->velocidad;
    }
}
