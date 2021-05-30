//
// Created by finch on 28/05/2021.
//

#ifndef PROYECTOJUEGO_POCIONESDAMAGE_H
#define PROYECTOJUEGO_POCIONESDAMAGE_H

#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Jugador.h"

class PocionesDamage : public Item{
private:
    int efectoPocion;
    sf::Texture texturaPocionDamage; //textura de pocion daño
    int suelo = 1;
public:
    sf::Sprite spritePocionD;
    PocionesDamage();
    virtual ~PocionesDamage(); //destructor
    void usarPocion(Jugador * jugador); //efecto pocion
    void cargarTexturas() override; //carga texturas
    void pintarItem(RenderWindow *ventana, int x, int y) override; //pintar item en pantalla
    virtual FloatRect getColision() override; //cuando colisione con el objeto
    void recogerItemSuelo() override; //recoger item del suelo
    int getSuelo() override;
    void usarItem(Jugador * jugador) override; //aplicar pocion a jugador
    void pintarItemInventario(RenderWindow *ventana, int x, int y) override; //pone el item en el inventario
};


#endif //PROYECTOJUEGO_POCIONESDAMAGE_H