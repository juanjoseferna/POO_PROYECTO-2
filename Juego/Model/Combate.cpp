//
// Created by finch on 24/05/2021.
//

#include "Combate.h"
Combate::Combate() {
}

void Combate::mostrarCombate(RenderWindow * ventana, Jugador * jugador, Enemigo * enemigo) {
    fondoPelea.loadFromFile("../Img/peleaMenu2.png");
    fuente1 = new Font();
    fuente1->loadFromFile("../Fonts/Combate.ttf");
    vidaTxt = new Text();
    vidaTxt->setFont(*fuente1);
    vidaTxt->setString("Hertz: ");
    vidaTxt->setPosition(789,433);
    vidaTxt->setColor(Color::Black);
    ///////////
    vidaNumero = new Text();
    vidaNumero->setFont(*fuente1);
    vidaNumero->setPosition(789,500);
    vidaNumero->setColor(Color::Black);
    /////////
    vidaEnemigoTxt = new Text();
    vidaEnemigoTxt->setFont(*fuente1);
    vidaEnemigoTxt->setString("Enemigo: ");
    vidaEnemigoTxt->setPosition(47,105);
    vidaEnemigoTxt->setColor(Color::Black);
    /////////
    vidaEnemigoNumero = new Text();
    vidaEnemigoNumero->setFont(*fuente1);
    vidaEnemigoNumero->setPosition(47,160);
    vidaEnemigoNumero->setColor(Color::Black);
    ///////////
    danoRealizado = new Text();
    danoRealizado->setFont(*fuente1);
    danoRealizado->setString("Dano realizado: ");
    danoRealizado->setCharacterSize(12);
    danoRealizado->setPosition(60,659);
    danoRealizado->setColor(Color::Black);
    //////////
    danoRecibido = new Text();
    danoRecibido->setFont(*fuente1);
    danoRecibido->setString("Dano recibido: ");
    danoRecibido->setCharacterSize(12);
    danoRecibido->setPosition(60,715);
    danoRecibido->setColor(Color::Black);
    bool salida = false;
    sprite.setTexture(fondoPelea);
    while(!salida){
        Event evento{};
        ventana->clear();
        ventana->draw(sprite);
        ventana->draw(*vidaTxt);
        vidaNumero->setString(std::to_string(jugador->getVida()));
        ventana->draw(*vidaNumero);
        ventana->draw(*vidaEnemigoTxt);
        vidaEnemigoNumero->setString(std::to_string(enemigo->getVida()));
        ventana->draw(*vidaEnemigoNumero);
        ventana->draw(*danoRealizado);
        ventana->draw(*danoRecibido);
        if(Mouse::getPosition(*ventana).x >= x1Rosa &&
           Mouse::getPosition(*ventana).x <= x2Rosa &&
           Mouse::getPosition(*ventana).y >= y1Rosa &&
           Mouse::getPosition(*ventana).y <= y2Rosa &&
           sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)){
                enemigo->perderVida(jugador->getDamage());
                jugador->perderVida(enemigo->getDamage());
                std::cout << "Boton Rosado" << std::endl;
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Verde &&
                Mouse::getPosition(*ventana).x <= x2Verde &&
                Mouse::getPosition(*ventana).y >= y1Verde &&
                Mouse::getPosition(*ventana).y <= y2Verde &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {
                enemigo->perderVida(jugador->getDamage());
                jugador->perderVida(enemigo->getDamage());
                std::cout << "Puntos vida: " << jugador->getVida() << std::endl;
                std::cout << "Puntos vida enemigo: " << enemigo->getVida() << std::endl;
                std::cout << "Boton Verde" << std::endl;
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Naranja &&
                Mouse::getPosition(*ventana).x <= x2Naranja &&
                Mouse::getPosition(*ventana).y >= y1Naranja &&
                Mouse::getPosition(*ventana).y <= y2Naranja &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {
                enemigo->perderVida(jugador->getAtaqueEspecial());
                jugador->perderVida(enemigo->getDamage());
                std::cout << "Boton Naranja" << std::endl;

            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Azul &&
                Mouse::getPosition(*ventana).x <= x2Azul &&
                Mouse::getPosition(*ventana).y >= y1Azul &&
                Mouse::getPosition(*ventana).y <= y2Azul &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {
                std::cout << "Boton Azul" << std::endl; //Boton de Huida
                srand(time(nullptr));
                posibilidadHuir = (1+rand()%5)-1;// posibilidades de 1 a 100
                std::cout << "Numero: " << posibilidadHuir << std::endl;
                if(!posibilidadHuir){
                    salida = true;
                }
                else{
                    jugador->perderVida(enemigo->getDamage());
                    std::cout << "Puntos vida: " << jugador->getVida() << std::endl;
                    salida = false;
                }
            }
        }
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana->close();
        }
        if (enemigo->getVida() <= 0){
            std::cout << "Ganaste" << std::endl;
            salida = true;
        }
        if (jugador->getVida() <= 0){
            std::cout << "Perdiste" << std::endl;
            salida = true;
        }
        ventana->display();
    }
}