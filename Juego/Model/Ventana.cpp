//
// Created by finch on 20/05/2021.
//

#include "Ventana.h"

Ventana::Ventana() {
    largo = 740;
    ancho = 500;
}

void Ventana::menuDificultad() {
    while (!salida){
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            ventana.close();
        }
        sprite.setTexture(dificultad);
        ventana.draw(sprite);
        if (Mouse::getPosition(ventana).x >= x1Facil &&
            Mouse::getPosition(ventana).x <= x2Facil &&
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
                salida = true;
            }
        } else if (Mouse::getPosition(ventana).x >= x1Normal &&
                   Mouse::getPosition(ventana).x <= x2Normal &&
                   Mouse::getPosition(ventana).y >= y1Normal &&
                   Mouse::getPosition(ventana).y <= y2Normal &&
                   (sprite.getTexture() == &dificultad ||
                    sprite.getTexture() == &dificultadNormal ||
                    sprite.getTexture() == &dificultadFacil ||
                    sprite.getTexture() == &dificultadVolver)){
            sprite.setTexture(dificultadNormal);
            ventana.draw(sprite);
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)) {
                salida = true;
            }
        } else if (Mouse::getPosition(ventana).x >= x1Volver &&
                   Mouse::getPosition(ventana).x <= x2Volver &&
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
        }
        ventana.display();
    }
}

void Ventana::crearVentana() {
    ventana.create(VideoMode(largo, ancho), "La guerra de los flip flops");
    menu.loadFromFile("../Img/estrellas.jpg");
    menuSalida.loadFromFile("../Img/estrellasSalida.jpg");
    menuJugar.loadFromFile("../Img/estrellasJugar.jpg");
    icono.loadFromFile("../Img/Icono.png");
    dificultad.loadFromFile("../Img/Dificultad.jpg");
    dificultadNormal.loadFromFile("../Img/Normal.jpg");
    dificultadFacil.loadFromFile("../Img/Facil.jpg");
    dificultadVolver.loadFromFile("../Img/Volver.jpg");
    ventana.setIcon(icono.getSize().x, icono.getSize().y, icono.getPixelsPtr());
    while (ventana.isOpen()){
        salida = false;
        sprite.setTexture(menu);
        Event evento{};
        ventana.clear();
        ventana.draw(sprite);
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            ventana.close();
        }
        if (Mouse::getPosition(ventana).x >= x1Salida &&
                Mouse::getPosition(ventana).x <= x2Salida &&
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
        } else if (Mouse::getPosition(ventana).x >= x1Inico &&
                Mouse::getPosition(ventana).x <= x2Inicio &&
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
        while (ventana.pollEvent(evento)){
            if (evento.type == Event::Closed)
                ventana.close();
        }
        ventana.display();
    }

}
