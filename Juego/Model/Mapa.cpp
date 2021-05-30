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
    Boss boss, boss1, boss2;
    jugador->cordX = 0;
    jugador->cordY = 0;
    while(ventana->isOpen()){
        if (Keyboard::isKeyPressed(Keyboard::P)) {
            return;
        }
        ventana->clear();
        texturaMapa.loadFromFile("../Img/Map002.png");
        spriteMapa.setTexture(texturaMapa);
        salidaTexture.loadFromFile("../Img/salidaJugador.png");
        salida.setTexture(salidaTexture);
        salida.setPosition(1300,0);
        ventana->draw(spriteMapa);
        crearMapa(ventana, jugador);
        jugador->mostrarJugador(ventana);
        dibujarCofre(ventana);
        colisiones(jugador, cofre);
        ventana->draw(salida);
        crearItems(ventana, jugador);
        crearEnemigos(ventana,jugador,cantEnemigos);
        colisionSalida(ventana,jugador, &salida);
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

        if(cantEnemigos == 16){
            boss1.dibujarBoss(ventana, ancho - 100, 20);
            colisionBoss(ventana,jugador,&boss1);
            boss2.dibujarBoss(ventana, ancho - 160, 20);
            colisionBoss(ventana,jugador,&boss2);
        } else {
            boss.dibujarBoss(ventana,ancho - 150, 20);
            colisionBoss(ventana,jugador,&boss);
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
    if (enemigo->getVida() > 0 && jugador->getColision().intersects(enemigo->spriteEnemigo.getGlobalBounds())){
        std::cout << "Colision enemigo" << std::endl;
        ventana->setView(ventana->getDefaultView());
        combate.mostrarCombate(ventana, jugador, enemigo, &inventario);
    } else {
        return;
    }
}

void Mapa::crearEnemigos(RenderWindow *ventana, Jugador *jugador, int cantEnemigos){
    int x = 100, y = 200;
    for (int canEnem = 0; canEnem < cantEnemigos; canEnem++){
        enemigos.push_back(new Enemigo);
        enemigos[canEnem].dibujarEnemigo(ventana, x, y);
        y += 200;
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

void Mapa::crearItems(RenderWindow *ventana,Jugador * jugador){
    items.push_back(new Espada);
    items[0]->pintarItem(ventana, 100, 300);
    colisionItems(jugador, items[0]);
    int contx = 0;
    int conty = 50;
    for (int i = 1; i <= 2; i++) {
        conty += 200;
        if(conty >= alto){
            contx += 200;
            conty = 50;
        }
        items.push_back(new PocionesVida);
        items[i]->pintarItem(ventana, contx, conty);
        colisionItems(jugador, items[i]);
    }
}

void Mapa::colisionItems(Jugador * jugador, Item * item){
    if (jugador->getColision().intersects(item->spriteItem.getGlobalBounds()) && item->getSuelo() == 1){
        inventario.agregarItemsInventario(item);
    }
}

void Mapa::colisionBoss(RenderWindow * ventana, Jugador * jugador, Boss * boss){
    if (boss->getVida() > 0 && jugador->getColision().intersects(boss->boss.getGlobalBounds())){
        ventana->setView(ventana->getDefaultView());
        combate.mostrarCombateBoss(ventana, jugador, boss, &inventario);
        finalizado = true;
    } else {
        return;
    }
}

void Mapa::colisionSalida(RenderWindow * ventana, Jugador * jugador, Sprite * salida){
    if (jugador->getColision().intersects(salida->getGlobalBounds())){
        Texture final;
        Sprite finalSprite;
        final.loadFromFile("../Img/salida.png");
        finalSprite.setTexture(final);
        while(ventana->isOpen()){
            ventana->clear();
            ventana->setView(ventana->getDefaultView());
            ventana->draw(finalSprite);
            if(Mouse::isButtonPressed(Mouse::Left)) {
                ventana->close();
            }
            ventana->display();
        }
    }
}