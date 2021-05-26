//
// Created by finch on 24/05/2021.
//

#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Tile{
public:
    Tile();
    bool esPasable, esSalida;
    Vector2f posicion;
    Texture textura;
    Sprite sprite;
    virtual ~Tile();
    Tile(std::string, float, float, bool, bool);
    bool configurarTextura(std::string);
    void dibujarTile(RenderWindow * ventana);
};


#endif
