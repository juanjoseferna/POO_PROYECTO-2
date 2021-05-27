//
// Created by finch on 20/05/2021.
//

#include "Ventana.h"
const int Ventana::ancho = 1280;
const int Ventana::alto = 804;

Ventana::Ventana() {
};


void Ventana::menuDificultad() {
    while (!salida){
        Event evento{};
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            ventana.close();
        }
        sprite.setTexture(dificultad);
        ventana.draw(sprite);
        if (Mouse::getPosition(ventana).x >= x1Global &&
            Mouse::getPosition(ventana).x <= x2Global &&
            Mouse::getPosition(ventana).y >= y1Facil &&
            Mouse::getPosition(ventana).y <= y2Facil &&
            (sprite.getTexture() == &dificultad ||
             sprite.getTexture() == &dificultadNormal ||
             sprite.getTexture() == &dificultadFacil ||
             sprite.getTexture() == &dificultadVolver)){
            sprite.setTexture(dificultadFacil);
            ventana.draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)){
                cantEnemegosPesadilla = 14;
                jugador.crearJugador();
                mapa.mostrarMapa(&ventana,&jugador,cantEnemegosPesadilla);
                ventana.setView(ventana.getDefaultView());
            }
        } else if (Mouse::getPosition(ventana).x >= x1Global &&
                   Mouse::getPosition(ventana).x <= x2Global &&
                   Mouse::getPosition(ventana).y >= y1Normal &&
                   Mouse::getPosition(ventana).y <= y2Normal &&
                   (sprite.getTexture() == &dificultad ||
                    sprite.getTexture() == &dificultadNormal ||
                    sprite.getTexture() == &dificultadFacil ||
                    sprite.getTexture() == &dificultadVolver)){
                sprite.setTexture(dificultadNormal);
                ventana.draw(sprite);
                sleep(milliseconds(100));
                if (Mouse::isButtonPressed(Mouse::Left)){
                    cantEnemigosInfernal = 16;
                    jugador.crearJugador();
                    mapa.mostrarMapa(&ventana,&jugador,cantEnemigosInfernal);
                    ventana.setView(ventana.getDefaultView());
                }
        } else if (Mouse::getPosition(ventana).x >= x1Global &&
                   Mouse::getPosition(ventana).x <= x2Global &&
                   Mouse::getPosition(ventana).y >= y1Volver &&
                   Mouse::getPosition(ventana).y <= y2Volver &&
                   (sprite.getTexture() == &dificultad ||
                    sprite.getTexture() == &dificultadNormal ||
                    sprite.getTexture() == &dificultadFacil ||
                    sprite.getTexture() == &dificultadVolver)) {
            sprite.setTexture(dificultadVolver);
            ventana.draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)) {
                salida = true;
            }
        }else {
            sprite.setTexture(dificultad);
            ventana.draw(sprite);
            }
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana.close();
        }
        ventana.display();
    }
}

void Ventana::crearVentana() {
    ventana.create(VideoMode(ancho, alto), "LA GUERRA DE LOS FLIP FLOPS");
    menu.loadFromFile("../Img/mainMenu.png");
    menuSalida.loadFromFile("../Img/seleccionarSalir.png");
    menuJugar.loadFromFile("../Img/seleccionarIniciar.png");
    icono.loadFromFile("../Img/Icono.png");
    dificultad.loadFromFile("../Img/menuJugador.png");
    dificultadNormal.loadFromFile("../Img/opcionInfernal.png");
    dificultadFacil.loadFromFile("../Img/opcionPesadilla.png");
    dificultadVolver.loadFromFile("../Img/opcionRegresar.png");
    //musica.loadFromFile("../Sounds/cave.wav");
    ventana.setIcon(icono.getSize().x, icono.getSize().y, icono.getPixelsPtr());
    //sonido.setBuffer(musica);
    //sonido.play();
    while (ventana.isOpen()){
        //if (reloj.getElapsedTime().asSeconds() == 120){
            //sonido.stop();
            //sonido.resetBuffer();
            //sonido.play();
            //reloj.restart();
        //}
        salida = false;
        sprite.setTexture(menu);
        Event evento{};
        ventana.clear();
        ventana.draw(sprite);
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            ventana.close();
        }
        if (Mouse::getPosition(ventana).x >= x1Global &&
                Mouse::getPosition(ventana).x <= x2Global &&
                Mouse::getPosition(ventana).y >= y1Salida &&
                Mouse::getPosition(ventana).y <= y2Salida &&
                (sprite.getTexture() == &menu ||
                 sprite.getTexture() == &menuJugar ||
                 sprite.getTexture() == &menuSalida)){
            sprite.setTexture(menuSalida);
            ventana.draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left) &&
                sprite.getTexture() == &menuSalida){
                ventana.close();
            }
        } else if (Mouse::getPosition(ventana).x >= x1Global &&
                Mouse::getPosition(ventana).x <= x2Global &&
                Mouse::getPosition(ventana).y >= y1Inicio &&
                Mouse::getPosition(ventana).y <= y2Inicio &&
                (sprite.getTexture() == &menu ||
                 sprite.getTexture() == &menuJugar ||
                 sprite.getTexture() == &menuSalida)){
            sprite.setTexture(menuJugar);
            ventana.draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left) &&
                sprite.getTexture() == &menuJugar){
                menuDificultad();
            }
        }
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana.close();
        }
        ventana.display();
    }
}

RenderWindow *Ventana::getVentana() {
    return &ventana;
}
