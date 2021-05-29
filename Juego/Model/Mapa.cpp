//
// Created by criska on 24/05/2021.
//

#include "Mapa.h"
const int ancho = 1440;
const int alto = 960;

Mapa::Mapa(){}

Mapa::~Mapa(){}

void Mapa::mostrarMapa(sf::RenderWindow *ventana, Jugador * jugador, int cantEnemigos){
    Event evento{};
    jugador->cordX = 0;
    jugador->cordY = 0;
    while(ventana->isOpen()) {
        int x = 100, y = 200;
        if (Keyboard::isKeyPressed(Keyboard::P)) {
            return;
        }
        ventana->clear();
        texturaMapa.loadFromFile("../Img/Map002.png");
        spriteMapa.setTexture(texturaMapa);
        ventana->draw(spriteMapa);
        crearMapa(ventana, jugador);
        jugador->mostrarJugador(ventana);
        dibujarCofre(ventana);
        colisiones(jugador, cofre);
        crearEnemigos(ventana,jugador,cantEnemigos);
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            ventana->close();
        }
        if (Keyboard::isKeyPressed(Keyboard::E)) {
            abrirInventario(ventana,jugador);
        }
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                ventana->close();
            }
        }
        ventana->display();
    }
}

void Mapa::dibujarCofre(RenderWindow *ventana) {
    Texture cofreTexture;
    cofreTexture.loadFromFile("../Img/cofreCerrado.png");
    cofre.setTexture(cofreTexture);
    cofre.setPosition(ancho-100 , 100);
    ventana->draw(cofre);
}

void Mapa::colisiones(Jugador *jugador, Sprite& objeto) {
    FloatRect colisionObjeto = objeto.getGlobalBounds();
    if (jugador->getColision().intersects(colisionObjeto)) {
        //Parte de abajo del objeto
        if (jugador->getColision().top < colisionObjeto.top
            && jugador->getColision().top + jugador->getColision().height < colisionObjeto.top + colisionObjeto.height
            && jugador->getColision().left < colisionObjeto.left + colisionObjeto.width
            && jugador->getColision().left + jugador->getColision().width > colisionObjeto.left) {
            jugador->cordY = (jugador->getColision().left);
            jugador->cordX = (colisionObjeto.top - jugador->getColision().height);
        }//Parte de arriba del objeto
        else if (jugador->getColision().top > colisionObjeto.top
                 &&
                 jugador->getColision().top + jugador->getColision().height > colisionObjeto.top + colisionObjeto.height
                 && jugador->getColision().left < colisionObjeto.left + colisionObjeto.width
                 && jugador->getColision().left + jugador->getColision().width > colisionObjeto.left) {
            jugador->cordY = (jugador->getColision().left);
            jugador->cordX = (colisionObjeto.top + colisionObjeto.height);
        }//Parte derecha del objeto
        if (jugador->getColision().left < colisionObjeto.left
            && jugador->getColision().left + jugador->getColision().width < colisionObjeto.left + colisionObjeto.width
            && jugador->getColision().top < colisionObjeto.top + colisionObjeto.height
            && jugador->getColision().top + jugador->getColision().height > colisionObjeto.top) {
            jugador->cordY = (colisionObjeto.left - jugador->getColision().width);
            jugador->cordX = (jugador->getColision().top);
        }//Parte izquierda del objeto
        else if (jugador->getColision().left > colisionObjeto.left
                 &&
                 jugador->getColision().left + jugador->getColision().width > colisionObjeto.left + colisionObjeto.width
                 && jugador->getColision().top < colisionObjeto.top + colisionObjeto.height
                 && jugador->getColision().top + jugador->getColision().height > colisionObjeto.top) {
            jugador->cordY = (colisionObjeto.left + colisionObjeto.width);
            jugador->cordX = (jugador->getColision().top);
        }
    }
}

void Mapa::crearMapa(RenderWindow *ventana, Jugador * jugador){
    texturaMuro.loadFromFile("../Img/suelo.png");
    spriteMuro.setTexture(texturaMuro);
    int sumadorHaciaAbajo = 0;
    int sumadorHaciaArriba = 904;
    //primera columna
    for(int i = 0; i < 13; i++){
        spriteMuro.setPosition(300,sumadorHaciaAbajo);
        ventana->draw(spriteMuro);
        colisiones(jugador,spriteMuro);
        sumadorHaciaAbajo += 53;
    }
    //segunda columna
    for(int i = 0; i < 13; i++){
        spriteMuro.setPosition(700, sumadorHaciaArriba);
        ventana->draw(spriteMuro);
        colisiones(jugador,spriteMuro);
        sumadorHaciaArriba -= 53;
    }
    sumadorHaciaAbajo = 0;
    //tercera columna
    for(int i = 0; i < 13; i++){
        spriteMuro.setPosition(1100, sumadorHaciaAbajo);
        ventana->draw(spriteMuro);
        colisiones(jugador,spriteMuro);
        sumadorHaciaAbajo += 53;
    }
}

void Mapa::colisionesEnemigo(RenderWindow * ventana, Jugador *jugador, Enemigo *enemigo) {
    if (enemigo->getVida() > 0 && jugador->getColision().intersects(enemigo->spriteEnemigo.getGlobalBounds())) {
        ventana->setView(ventana->getDefaultView());
        combate.mostrarCombate(ventana, jugador, enemigo);
    } else {
        return;
    }
}

void Mapa::crearEnemigos(RenderWindow *ventana, Jugador *jugador, int cantEnemigos){
    int x = 100, y = 200;
    for (int canEnem = 0; canEnem < cantEnemigos; ++canEnem) {
        enemigos.push_back(new Enemigo);
        enemigos[canEnem].dibujarEnemigo(ventana, x, y);
        y *= 2;
        if (y >= alto){
            x += 400;
            y = 200;
        }
        colisionesEnemigo(ventana,jugador,&enemigos[canEnem]);
    }
}

void Mapa::abrirInventario(RenderWindow * ventana,Jugador * jugador){
    ventana->setView(ventana->getDefaultView());
    inventario.mostrarInventario(ventana, jugador);
}