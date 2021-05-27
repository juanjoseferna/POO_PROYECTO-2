//
// Created by finch on 24/05/2021.
//

#include "Combate.h"
Combate::Combate() {
}

void Combate::mostrarCombate(RenderWindow * ventana, Jugador * jugador, Enemigo * enemigo) {
    int danoR = 0, danoRecibido2 = 0;
    ventana->setView(ventana->getDefaultView());
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
    //////////
    ataqueBasico = new Text();
    ataqueBasico->setFont(*fuente1);
    ataqueBasico->setString("Flip-Flop Trueno");
    ataqueBasico->setCharacterSize(15);
    ataqueBasico->setPosition(697,651);
    ataqueBasico->setColor(Color::Black);
    //////////
    ataqueEspecial = new Text();
    ataqueEspecial->setFont(*fuente1);
    ataqueEspecial->setString("Von-Neumann");
    ataqueEspecial->setCharacterSize(17);
    ataqueEspecial->setPosition(1019,651);
    ataqueEspecial->setColor(Color::Black);
    //////////
    huir = new Text();
    huir->setFont(*fuente1);
    huir->setString("Huir");
    huir->setCharacterSize(20);
    huir->setPosition(1070,743);
    huir->setColor(Color::Black);
    //////////
    pociones = new Text();
    pociones->setFont(*fuente1);
    pociones->setString("Pociones");
    pociones->setCharacterSize(20);
    pociones->setPosition(725,743);
    pociones->setColor(Color::Black);
    //////////
    danoRealizadoNumero = new Text();
    danoRealizadoNumero->setFont(*fuente1);
    danoRealizadoNumero->setCharacterSize(20);
    danoRealizadoNumero->setPosition(339,659);
    danoRealizadoNumero->setColor(Color::Black);
    //////////
    danoRecibidodoNumero = new Text();
    danoRecibidodoNumero->setFont(*fuente1);
    danoRecibidodoNumero->setCharacterSize(20);
    danoRecibidodoNumero->setPosition(339,715);
    danoRecibidodoNumero->setColor(Color::Black);
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
        ventana->draw(*ataqueBasico);
        ventana->draw(*ataqueEspecial);
        ventana->draw(*huir);
        ventana->draw(*pociones);
        ////////////////
        danoRealizadoNumero->setString(std::to_string(danoR));
        ventana->draw(*danoRealizadoNumero);
        danoRecibidodoNumero->setString(std::to_string(danoRecibido2));
        ventana->draw(*danoRecibidodoNumero);
        //////////////////
        if(Mouse::getPosition(*ventana).x >= x1Rosa &&
           Mouse::getPosition(*ventana).x <= x2Rosa &&
           Mouse::getPosition(*ventana).y >= y1Rosa &&
           Mouse::getPosition(*ventana).y <= y2Rosa &&
           sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)){
                danoR=jugador->getDamage();
                danoRecibido2=enemigo->getDamage();
                enemigo->perderVida(jugador->getDamage());
                jugador->perderVida(enemigo->getDamage());
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
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Naranja &&
                Mouse::getPosition(*ventana).x <= x2Naranja &&
                Mouse::getPosition(*ventana).y >= y1Naranja &&
                Mouse::getPosition(*ventana).y <= y2Naranja &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {
                danoR=jugador->getAtaqueEspecial();
                danoRecibido2=enemigo->getDamage();
                enemigo->perderVida(jugador->getAtaqueEspecial());
                jugador->perderVida(enemigo->getDamage());

            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Azul &&
                Mouse::getPosition(*ventana).x <= x2Azul &&
                Mouse::getPosition(*ventana).y >= y1Azul &&
                Mouse::getPosition(*ventana).y <= y2Azul &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {
                srand(time(nullptr));
                posibilidadHuir = (1+rand()%5)-1;// posibilidades de 1 a 100
                if(!posibilidadHuir){
                    enemigo->perderVida(enemigo->getVida());
                    salida = true;
                }
                else{
                    danoRecibido2=enemigo->getDamage();
                    jugador->perderVida(enemigo->getDamage());
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