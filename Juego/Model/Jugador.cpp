//
// Created by finch on 20/05/2021.
//

#include "Jugador.h"
const int ancho = 1280;
const int alto = 804;

Jugador::Jugador() : Personaje(100,10) {
    cordX = 0;
    cordY = 0;
    ataqueEspecial = 20;
    velocidad = 5;
}

void Jugador::crearJugador(){
    Herz.loadFromFile("../Img/personaje.png");
    spriteHerz.setTexture(Herz);
}

void Jugador::mostrarJugador(RenderWindow * ventana) {
    crearJugador();
    camara = View(FloatRect (0,0,1280,804));
    spriteHerz.setPosition(cordY,cordX);
    camara.setCenter(cordY,cordX);
    spriteHerz.setTextureRect(IntRect(fotogram, direccion, sizeA, sizeB));
    ventana->draw(spriteHerz);
    moverse();
    ventana->setView(camara);
    camara.zoom(1.0f + Mouse::Wheel::VerticalWheel);
    camara.setCenter(cordY, cordX);
}

void Jugador::moverse() {
    if (Keyboard::isKeyPressed(Keyboard::Right) &&
        cordY <= ancho - 48) {
        cordY += velocidad;
        direccion = 96;
        if (reloj.getElapsedTime().asSeconds() > 0.5f) {
            fotogram += 48;
            reloj.restart();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Left) &&
        cordY >= 0) {
        cordY -= velocidad;
        direccion = 48;
        if (reloj.getElapsedTime().asSeconds() > 0.5f) {
            fotogram += 48;
            reloj.restart();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Up) &&
        cordX >= 0) {
        cordX -= velocidad;
        direccion = 144;
        if (reloj.getElapsedTime().asSeconds() > 0.5f) {
            fotogram += 48;
            reloj.restart();
        }
    }
    if (Keyboard::isKeyPressed(Keyboard::Down) &&
        cordX <= alto - 48) {
        cordX += velocidad;
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

int Jugador::getAtaqueEspecial() {
    return ataqueEspecial;
}
