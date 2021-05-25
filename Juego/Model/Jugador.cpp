//
// Created by finch on 20/05/2021.
//

#include "Jugador.h"
const int ancho = 1280;
const int alto = 804;

Jugador::Jugador() : Personaje(100,10) {
    cordX = 0;
    cordY = 0;
}

void Jugador::mostrarJugador(RenderWindow * ventana) {
    Herz.loadFromFile("../Img/personaje.png");
    spriteHerz.setTexture(Herz);
    camara = View(FloatRect (0,0,1280,804));
    while (!Keyboard::isKeyPressed(Keyboard::P)) {
        spriteHerz.setPosition(cordY,cordX);
        Event evento{};
        camara.setCenter(cordY,cordX);
        spriteHerz.setTextureRect(IntRect(fotogram, direccion, sizeA, sizeB));
        ventana->clear();
        ventana->draw(spriteHerz);
        moverse();
        ventana->setView(camara);
        ventana->display();
        if(Keyboard::isKeyPressed(Keyboard::Q)){
            camara.zoom(1000);
            camara.setCenter(cordY,cordX);
        }
        /*
        if (rectHerz.intersects(rectPrueba)){
            ventana->setView(ventana->getDefaultView());
            return;
        }*/
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana->close();
        }
    }
    ventana->setView(ventana->getDefaultView());
}

void Jugador::moverse() {
    if (Keyboard::isKeyPressed(Keyboard::Right) &&
        cordY <= ancho - 48) {
        cordY += 1;
        direccion = 96;
        if (reloj.getElapsedTime().asSeconds() > 0.5f) {
            fotogram += 48;
            reloj.restart();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Left) &&
        cordY >= 0) {
        cordY -= 1;
        direccion = 48;
        if (reloj.getElapsedTime().asSeconds() > 0.5f) {
            fotogram += 48;
            reloj.restart();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) &&
        cordX >= 0) {
        cordX -= 1;
        direccion = 144;
        if (reloj.getElapsedTime().asSeconds() > 0.5f) {
            fotogram += 48;
            reloj.restart();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) &&
        cordX <= alto - 48) {
        cordX += 1;
        direccion = 0;
        if (reloj.getElapsedTime().asSeconds() > 0.5f) {
            fotogram += 48;
            reloj.restart();
        }
    }
    if (fotogram > 96)
        fotogram = 0;
    spriteHerz.setPosition(cordY, cordX);
}