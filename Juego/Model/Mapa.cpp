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
        if (Keyboard::isKeyPressed(Keyboard::P)) {//al presionar p se ira al menu de dificultad
            return;
        }
        ventana->clear();
        texturaMapa.loadFromFile("../Img/Map002.png");//carga la textura del mapa
        spriteMapa.setTexture(texturaMapa);
        salidaTexture.loadFromFile("../Img/salidaJugador.png");//carga textura de la salida del juego
        salida.setTexture(salidaTexture);
        salida.setPosition(1300,0);//Ubicacion de la textura salida del juego
        ventana->draw(spriteMapa);//dibuja el mapa en ventana
        ventana->draw(salida);//al chocar el jugador y la salida se finaliza el juego
        jugador->mostrarJugador(ventana);//muestra el jugador en el mapa
        crearMapa(ventana, jugador);
        dibujarCofre(ventana);//dibuja el cofre en ventana
        colisiones(jugador, cofre);
        crearItems(ventana, jugador);//crear items en mapa
        crearEnemigos(ventana,jugador,cantEnemigos);//crear enemigos en mapa
        colisionSalida(ventana,jugador, &salida);//
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {//al presionar escape saldra del juego
            ventana->close();
        }
        if (Keyboard::isKeyPressed(Keyboard::E)) {//al presionar E mostrara el inventario en el mapa
            abrirInventario(ventana,jugador);
        }
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                ventana->close();
            }
        }

        if(cantEnemigos == 16){//cantidad de enemigos en mapa
            boss1.dibujarBoss(ventana, ancho - 100, 20);//posicion donde debe dibujar el boss
            colisionBoss(ventana,jugador,&boss1);//colision con el boss
            boss2.dibujarBoss(ventana, ancho - 160, 20);//posicion donde debe dibujar el boss
            colisionBoss(ventana,jugador,&boss2);//colision con el boss
        } else {
            boss.dibujarBoss(ventana,ancho - 150, 20);//posicion donde debe dibujar el boss
            colisionBoss(ventana,jugador,&boss);//colision con el boss
        }
        ventana->display();
    }
}

void Mapa::dibujarCofre(RenderWindow *ventana) {//dibujar cofre
    Texture cofreTexture;//textura del cofre
    cofreTexture.loadFromFile("../Img/cofreCerrado.png");//carga textura del cofre cerrado
    cofre.setTexture(cofreTexture);
    cofre.setPosition(ancho-100 , 100);//posicion del cofre
    ventana->draw(cofre);//dibujar cobre en el mapa
}

void Mapa::colisiones(Jugador *jugador, Sprite& objeto) {//colisiones en el mapa
    FloatRect colisionObjeto = objeto.getGlobalBounds();
    if (jugador->getColision().intersects(colisionObjeto)) {//jugador colisiona
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
    texturaMuro.loadFromFile("../Img/suelo.png");//carga textura del suelo
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

void Mapa::colisionesEnemigo(RenderWindow * ventana, Jugador *jugador, Enemigo *enemigo) {//colision con un enemigo para entrar a combate
    if (enemigo->getVida() > 0 && jugador->getColision().intersects(enemigo->spriteEnemigo.getGlobalBounds())){
        ventana->setView(ventana->getDefaultView());
        combate.mostrarCombate(ventana, jugador, enemigo, &inventario);//entra al combate
    } else {
        return;
    }
}
//crear enemigos en mapa
void Mapa::crearEnemigos(RenderWindow *ventana, Jugador *jugador, int cantEnemigos){
    int x = 100, y = 200;
    for (int canEnem = 0; canEnem < cantEnemigos; canEnem++){
        enemigos.push_back(new Enemigo);
        enemigos[canEnem].dibujarEnemigo(ventana, x, y);//dibuja enemigo en mapa
        y += 200;
        if (y >= alto){
            x += 400;
            y = 200;
        }
        colisionesEnemigo(ventana,jugador,&enemigos[canEnem]);//colision con un enemigo
    }
}

void Mapa::abrirInventario(RenderWindow * ventana,Jugador * jugador){//abrir inventario en mapa
    ventana->setView(ventana->getDefaultView());
    inventario.mostrarInventario(ventana, jugador);
}

void Mapa::crearItems(RenderWindow *ventana,Jugador * jugador) {//crear items en el mapa
    int contx = 0;
    int conty = 50;
    items.push_back(new Espada);
    items.push_back(new PocionesVida);
    items.push_back(new PocionesDamage);
    items.push_back(new Lanza);
    items.push_back(new Artefacto);
    for (int i = 0; i < 5; i++) {
        conty += 500;
        if (conty >= alto) {
            contx += 400;
            conty = 500;
        }
        if(contx >= ancho){
            contx= 1350;
            conty = 10;
        }
        items[i]->pintarItem(ventana, contx, conty);//coordenadas para pintar el item
        colisionItems(jugador, items[i]);//colisionar con un item
    }
}

void Mapa::colisionItems(Jugador * jugador, Item * item){//colision con item
    if (jugador->getColision().intersects(item->spriteItem.getGlobalBounds()) && item->getSuelo() == 1){
        inventario.agregarItemsInventario(item);//agrega item al inventario
    }
}

void Mapa::colisionBoss(RenderWindow * ventana, Jugador * jugador, Boss * boss){//colision con el boss
    if (boss->getVida() > 0 && jugador->getColision().intersects(boss->boss.getGlobalBounds())){//si hay una colision con un boss
        ventana->setView(ventana->getDefaultView());
        combate.mostrarCombateBoss(ventana, jugador, boss, &inventario);//empezara en mapa el combate con el boss
    } else {
        return;
    }
}
//al colisionar se termina el juego es decir la salida del mismo
void Mapa::colisionSalida(RenderWindow * ventana, Jugador * jugador, Sprite * salida){
    if (jugador->getColision().intersects(salida->getGlobalBounds())){
        Texture final;//textura final
        Sprite finalSprite;//sprite final
        final.loadFromFile("../Img/salida.png");//carga la textura final
        finalSprite.setTexture(final);
        while(jugador->artefacto){
            ventana->clear();
            ventana->setView(ventana->getDefaultView());
            ventana->draw(finalSprite);
            if(Mouse::isButtonPressed(Mouse::Left)) {//al mostrar el el sprite final y dar click se cierra la ventana diciendo que el juego a terminado
                ventana->close();
            }
            ventana->display();
        }
    }
}