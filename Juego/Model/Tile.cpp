//
// Created by finch on 24/05/2021.
//

#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

Tile::Tile(std::string nombreTextura, float posEnX, float posEnY, bool esPasable, bool esSalida)
{
    posicion = sf::Vector2f(posEnX, posEnY);
    sprite.setPosition(posicion);
    this->esPasable = esPasable;
    this->esSalida = esSalida;
}

bool Tile::configurarTextura(std::string nombreTextura)
{
    if(!textura.loadFromFile(nombreTextura))
    {
        return false;
    }
    else
    {
        textura.setSmooth(true);
        sprite.setTexture(textura);
        sprite.setTextureRect(sf::IntRect(0,0,50,50));
        return true;
    }
}
void Tile::dibujarTile(RenderWindow * ventana){
    Event evento{};
    ventana->draw(sprite);
    ventana->display();
    while (ventana->pollEvent(evento)) {
        if (evento.type == Event::Closed)
            ventana->close();
    }
}
