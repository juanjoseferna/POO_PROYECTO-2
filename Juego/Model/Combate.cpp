//
// Created by finch on 24/05/2021.
//

#include "Combate.h"
Combate::Combate() {
}

//Se muestra combate en la ventana del juego
void Combate::mostrarCombate(RenderWindow * ventana, Jugador * jugador, Enemigo * enemigo, Inventario * inventario) {
    int danoR = 0, danoRecibido2 = 0;
    ventana->setView(ventana->getDefaultView());
    fondoPelea.loadFromFile("../Img/peleaMenu3.png"); // se cargar el fondo de combate
    fuente1 = new Font();
    fuente1->loadFromFile("../Fonts/Combate.ttf"); //se carga el tipo de letra en el texto del juego
    vidaTxt = new Text();
    vidaTxt->setFont(*fuente1); // Se implementa el texto de la vida de hertz
    vidaTxt->setString("Hertz: ");
    vidaTxt->setPosition(789,433);
    vidaTxt->setColor(Color::Black);
    ///////////
    vidaNumero = new Text();   // se implementa la cantidad de vida de hertz
    vidaNumero->setFont(*fuente1);
    vidaNumero->setPosition(789,500);
    vidaNumero->setColor(Color::Black);
    /////////
    vidaEnemigoTxt = new Text(); // Se implementa el texto de la vida del enemigo
    vidaEnemigoTxt->setFont(*fuente1);
    vidaEnemigoTxt->setString("Enemigo: ");
    vidaEnemigoTxt->setPosition(47,105);
    vidaEnemigoTxt->setColor(Color::Black);
    /////////
    vidaEnemigoNumero = new Text();  // se implementa la cantidad de vida del enemigo
    vidaEnemigoNumero->setFont(*fuente1);
    vidaEnemigoNumero->setPosition(47,160);
    vidaEnemigoNumero->setColor(Color::Black);
    ///////////
    danoRealizado = new Text();  // Se implementa el texto de daño realizado
    danoRealizado->setFont(*fuente1);
    danoRealizado->setString("Dano realizado: ");
    danoRealizado->setCharacterSize(12);
    danoRealizado->setPosition(60,659);
    danoRealizado->setColor(Color::Black);
    //////////
    danoRecibido = new Text();  // Se implementa el texto de daño recibido
    danoRecibido->setFont(*fuente1);
    danoRecibido->setString("Dano recibido: ");
    danoRecibido->setCharacterSize(12);
    danoRecibido->setPosition(60,715);
    danoRecibido->setColor(Color::Black);
    //////////
    ataqueBasico = new Text(); // Se implementa el ataque flip flop como boton
    ataqueBasico->setFont(*fuente1);
    ataqueBasico->setString("Flip-Flop Trueno");
    ataqueBasico->setCharacterSize(15);
    ataqueBasico->setPosition(697,651);
    ataqueBasico->setColor(Color::Black);
    //////////
    ataqueEspecial = new Text(); // Se implementa el ataque von neumann como boton
    ataqueEspecial->setFont(*fuente1);
    ataqueEspecial->setString("Von-Neumann");
    ataqueEspecial->setCharacterSize(17);
    ataqueEspecial->setPosition(1019,651);
    ataqueEspecial->setColor(Color::Black);
    //////////
    huir = new Text();  // Se implementa huir como boton
    huir->setFont(*fuente1);
    huir->setString("Huir");
    huir->setCharacterSize(20);
    huir->setPosition(1070,743);
    huir->setColor(Color::Black);
    //////////
    pociones = new Text();
    pociones->setFont(*fuente1);
    pociones->setString("Inventario");
    pociones->setCharacterSize(20);
    pociones->setPosition(700,743);
    pociones->setColor(Color::Black);
    //////////
    danoRealizadoNumero = new Text();  // Se implementa el daño realizado para que lo muestre en cada ataque
    danoRealizadoNumero->setFont(*fuente1);
    danoRealizadoNumero->setCharacterSize(20);
    danoRealizadoNumero->setPosition(339,659);
    danoRealizadoNumero->setColor(Color::Black);
    //////////
    danoRecibidodoNumero = new Text();  // Se implementa el daño recibido para que lo muestre en cada ataque
    danoRecibidodoNumero->setFont(*fuente1);
    danoRecibidodoNumero->setCharacterSize(20);
    danoRecibidodoNumero->setPosition(339,715);
    danoRecibidodoNumero->setColor(Color::Black);
    bool salida = false;
    sprite.setTexture(fondoPelea);
    while(!salida && ventana->isOpen()){
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
            if(Mouse::isButtonPressed(Mouse::Left)){ //Boton rosa funcionalidades de ataque flip flop
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
            if(Mouse::isButtonPressed(Mouse::Left)) { //Boton verde es para abrir el inventario
                jugador->perderVida(enemigo->getDamage());
                inventario->mostrarInventario(ventana,jugador);
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Naranja &&
                Mouse::getPosition(*ventana).x <= x2Naranja &&
                Mouse::getPosition(*ventana).y >= y1Naranja &&
                Mouse::getPosition(*ventana).y <= y2Naranja &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {//Boton naranja funcionalidades de ataque von neumann
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
                posibilidadHuir = (1+rand()%5)-1;// posibilidades de 0 a 4
                if(!posibilidadHuir){ //si es igual a cero puede huir
                    enemigo->perderVida(enemigo->getVida());
                    salida = true;
                }
                else{  //si es diferente a cero no podra huir y recibira daño del enemigo
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
        if (enemigo->getVida() <= 0){ // si la vida enemigo es menor a cero aparece que has ganado
            ganaste.loadFromFile("../Img/victory.png");
            sprite.setTexture(ganaste);
            ventana->draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)){
                salida = true;
            }
        }
        if (jugador->getVida() <= 0){  // si la vida de hertz es menor a cero aparece que has ganado
            perdiste.loadFromFile("../Img/derrota.png");
            sprite.setTexture(perdiste);
            ventana->draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)){
                ventana->close();
            }
        }
        ventana->display();
    }
}
// mostrar combate boss es lo mismo de mostrar combate
void Combate::mostrarCombateBoss(RenderWindow * ventana, Jugador * jugador, Boss * boss, Inventario * inventario){
    int danoR = 0, danoRecibido2 = 0;
    ventana->setView(ventana->getDefaultView());
    fondoPelea.loadFromFile("../Img/peleaMenu2.png");//cargar texturas
    fuente1 = new Font();
    fuente1->loadFromFile("../Fonts/Combate.ttf");//cargar la textura de la letra en el juego
    vidaTxt = new Text();
    vidaTxt->setFont(*fuente1);
    vidaTxt->setString("Hertz: ");//texto dentro de la ventana
    vidaTxt->setPosition(789,433);
    vidaTxt->setColor(Color::Black);
    ///////////
    vidaNumero = new Text();
    vidaNumero->setFont(*fuente1);//texto dentro de la ventana de la vida de Hertz
    vidaNumero->setPosition(789,500);
    vidaNumero->setColor(Color::Black);
    /////////
    vidaBossTxt = new Text();
    vidaBossTxt->setFont(*fuente1);
    vidaBossTxt->setString("Boss: ");//texto dentro de la ventana
    vidaBossTxt->setPosition(47,105);
    vidaBossTxt->setColor(Color::Black);
    /////////
    vidaBossNumero = new Text();
    vidaBossNumero->setFont(*fuente1);
    vidaBossNumero->setPosition(47,160);//texto dentro de la ventana de la vida dele el numero
    vidaBossNumero->setColor(Color::Black);
    ///////////
    danoRealizado = new Text();
    danoRealizado->setFont(*fuente1);
    danoRealizado->setString("Dano realizado: ");//texto dentro de la ventana
    danoRealizado->setCharacterSize(12);
    danoRealizado->setPosition(60,659);
    danoRealizado->setColor(Color::Black);
    //////////
    danoRecibido = new Text();
    danoRecibido->setFont(*fuente1);
    danoRecibido->setString("Dano recibido: ");//texto dentro de la ventana
    danoRecibido->setCharacterSize(12);
    danoRecibido->setPosition(60,715);
    danoRecibido->setColor(Color::Black);
    //////////
    ataqueBasico = new Text();
    ataqueBasico->setFont(*fuente1);
    ataqueBasico->setString("Flip Flop Trueno");//texto dentro de la ventana
    ataqueBasico->setCharacterSize(15);
    ataqueBasico->setPosition(697,651);
    ataqueBasico->setColor(Color::Black);
    //////////
    ataqueEspecial = new Text();
    ataqueEspecial->setFont(*fuente1);
    ataqueEspecial->setString("Von-Neumann");//texto dentro de la ventana
    ataqueEspecial->setCharacterSize(17);
    ataqueEspecial->setPosition(1019,651);
    ataqueEspecial->setColor(Color::Black);
    //////////
    huir = new Text();
    huir->setFont(*fuente1);
    huir->setString("Huir");//texto dentro de la ventana
    huir->setCharacterSize(20);
    huir->setPosition(1070,743);
    huir->setColor(Color::Black);
    //////////
    pociones = new Text();
    pociones->setFont(*fuente1);
    pociones->setString("Inventario");//texto dentro de la ventana
    pociones->setCharacterSize(20);
    pociones->setPosition(700,743);
    pociones->setColor(Color::Black);
    //////////
    danoRealizadoNumero = new Text();
    danoRealizadoNumero->setFont(*fuente1);
    danoRealizadoNumero->setCharacterSize(20);//texto dentro de la ventana de daño realizado el numero
    danoRealizadoNumero->setPosition(339,659);
    danoRealizadoNumero->setColor(Color::Black);
    //////////
    danoRecibidodoNumero = new Text();
    danoRecibidodoNumero->setFont(*fuente1);
    danoRecibidodoNumero->setCharacterSize(20);//texto dentro de la ventana de daño recibido el numero
    danoRecibidodoNumero->setPosition(339,715);
    danoRecibidodoNumero->setColor(Color::Black);
    bool salida = false;
    sprite.setTexture(fondoPelea);
    while(!salida && ventana->isOpen()){
        Event evento{};
        ventana->clear();
        ventana->draw(sprite);//dibuja el fondo de la batalla en la ventana
        ventana->draw(*vidaTxt);//dibuja texto en la ventana
        vidaNumero->setString(std::to_string(jugador->getVida()));
        ventana->draw(*vidaNumero);//dibuja texto en la ventana
        ventana->draw(*vidaBossTxt);//dibuja texto en la ventana
        vidaBossNumero->setString(std::to_string(boss->getVida()));
        ventana->draw(*vidaBossNumero);//dibuja texto en la ventana
        ventana->draw(*danoRealizado);//dibuja texto en la ventana
        ventana->draw(*danoRecibido);//dibuja texto en la ventana
        ventana->draw(*ataqueBasico);//dibuja texto en la ventana
        ventana->draw(*ataqueEspecial);//dibuja texto en la ventana
        ventana->draw(*huir);//dibuja texto en la ventana
        ventana->draw(*pociones);//dibuja texto en la ventana
        ////////////////
        danoRealizadoNumero->setString(std::to_string(danoR));
        ventana->draw(*danoRealizadoNumero);//dibuja texto en la ventana
        danoRecibidodoNumero->setString(std::to_string(danoRecibido2));
        ventana->draw(*danoRecibidodoNumero);//dibuja texto en la ventana
        //////////////////
        if(Mouse::getPosition(*ventana).x >= x1Rosa &&
           Mouse::getPosition(*ventana).x <= x2Rosa &&//coordenadas del boton rosa
           Mouse::getPosition(*ventana).y >= y1Rosa &&
           Mouse::getPosition(*ventana).y <= y2Rosa &&
           sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)){//si da click sobre el boton hara el daño a enemigo y recibira el ataque de enemigo
                danoR=jugador->getDamage();
                danoRecibido2=boss->getDamage();
                boss->perderVida(jugador->getDamage());//ataque de jugador
                jugador->perderVida(boss->getDamage());//ataque deenemigo
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Verde &&
                Mouse::getPosition(*ventana).x <= x2Verde &&//coordenadas del boton
                Mouse::getPosition(*ventana).y >= y1Verde &&
                Mouse::getPosition(*ventana).y <= y2Verde &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {//si da click sobre el boton abrira el inventario
                jugador->perderVida(boss->getDamage());
                inventario->mostrarInventario(ventana,jugador);//mostrar inventario
            }
        }
        else if(Mouse::getPosition(*ventana).x >= x1Naranja &&
                Mouse::getPosition(*ventana).x <= x2Naranja &&//coordenadas boton
                Mouse::getPosition(*ventana).y >= y1Naranja &&
                Mouse::getPosition(*ventana).y <= y2Naranja &&
                sprite.getTexture() == &fondoPelea){
            sleep(milliseconds(100));
            if(Mouse::isButtonPressed(Mouse::Left)) {//si da click sobre el boton hara el ataque von neumann
                danoR=jugador->getAtaqueEspecial();
                danoRecibido2=boss->getDamage();
                boss->perderVida(jugador->getAtaqueEspecial());//el enemiga recibe el ataque
                jugador->perderVida(boss->getDamage());//el enemigo ataca

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
                posibilidadHuir = (1+rand()%5)-1;// posibilidades de 0 a 5
                if(!posibilidadHuir){ //si posibilidad huir es igual a 0 podra huir
                    boss->perderVida(boss->getVida());
                    salida = true;
                }
                else{
                    danoRecibido2=boss->getDamage();//si posibilidad huir no es igual a 0 perdera vida y no podra escapar
                    jugador->perderVida(boss->getDamage());
                    salida = false;
                }
            }
        }
        while (ventana->pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana->close();
        }
        if (boss->getVida() <= 0){//si la vida del enemigo es cero ganaremos
            ganaste.loadFromFile("../Img/victory.png");
            sprite.setTexture(ganaste);
            ventana->draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)){
                salida = true;
            }
        }
        if (jugador->getVida() <= 0){ //si la vida de hertz es igual 0 perderemos
            perdiste.loadFromFile("../Img/derrota.png");
            sprite.setTexture(perdiste);
            ventana->draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)){
                ventana->close();
            }
        }
        ventana->display();
    }
}