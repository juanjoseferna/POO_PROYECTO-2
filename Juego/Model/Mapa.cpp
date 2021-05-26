//
// Created by Usuario on 24/05/2021.
//

#include "Mapa.h"

Mapa::Mapa()
{
    sizeMapa = 15;
    configurarEstadoInicial();
}

Mapa::~Mapa()
{
}

void Mapa::configurarEstadoInicial()
{
    posicionSalida = sf::Vector2i(15, 15);
    posicionJugador = sf::Vector2i(0,0);
    //configurarPosicionEnemigos();
    configurarTiles();
}

void Mapa::configurarPosicionEnemigos()
{
    posicionEnemigos.clear();
    posicionEnemigos.push_back(sf::Vector2i(sizeMapa, sizeMapa));
    posicionEnemigos.push_back(sf::Vector2i(5,7));
    posicionEnemigos.push_back(sf::Vector2i(12,9));
}

void Mapa::configurarTiles()
{
    tiles.clear();
    std::vector<Tile*> primeraFila;
    primeraFila.push_back(new Tile("../Img/suelo.png", 0,0,false,false));
    primeraFila.push_back(new Tile("../Img/suelo.png", 50,0,false,false));
    primeraFila.push_back(new Tile("../Img/suelo.png",100,0,false,false));
    primeraFila.push_back(new Tile("../Img/suelo.png", 150,0,false,false));
    primeraFila.push_back(new Tile("../Img/suelo.png", 200,0,false,false));
    //primeraFila.push_back(new Tile("../Img/enemigo.png", 200,0,true,false));
    tiles.push_back(primeraFila);
}

void Mapa::mostrarMapa(RenderWindow *ventana){
    Event evento{};
    ventana->clear();
    configurarEstadoInicial();
    for(int i = 0; i < sizeof(tiles); i++)
    {
        for(int j = 0; j < sizeof(tiles[i]); j++)
        {
            tiles[i][j]->dibujarTile(ventana);
        }
    }
    ventana->display();
    sleep(milliseconds(200));
    while (ventana->pollEvent(evento)) {
        if (evento.type == Event::Closed)
            ventana->close();
    }
}
