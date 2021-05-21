//
// Created by finch on 20/05/2021.
//

#include "Ventana.h"

Ventana::Ventana() {
    largo = 740;
    ancho = 500;
}

void Ventana::crearVentana() {
    RenderWindow ventana(VideoMode(largo, ancho), "La guerra de los flip flops: La venganza de marnivel");
    menu.loadFromFile("../Img/estrellas.jpg");
    menuSalida.loadFromFile("../Img/estrellasSalida.jpg");
    menuInicio.loadFromFile("../Img/estrellasJugar.jpg");
    icono.loadFromFile("../Img/Icono.png");
    ventana.setIcon(icono.getSize().x, icono.getSize().y, icono.getPixelsPtr());
    Sprite sprite1(menu);
    while (ventana.isOpen()){
        Event evento{};
        ventana.clear();
        ventana.draw(sprite1);
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            ventana.close();
        }
        if (Mouse::getPosition(ventana).x >= x1Salida &&
            Mouse::getPosition(ventana).x <= x2Salida &&
            Mouse::getPosition(ventana).y >= y1Salida &&
            Mouse::getPosition(ventana).y <= y2Salida){
            Sprite spray(menuSalida);
            ventana.draw(spray);
            if (Mouse::isButtonPressed(Mouse::Left)){
                ventana.close();
            }
        } else if (Mouse::getPosition(ventana).x >= x1Inico &&
            Mouse::getPosition(ventana).x <= x2Inicio &&
            Mouse::getPosition(ventana).y >= y1Inicio &&
            Mouse::getPosition(ventana).y <= y2Inicio){
            Sprite sprite3(menuInicio);
            ventana.draw(sprite3);
            if (Mouse::isButtonPressed(Mouse::Left)){
                ventana.close();
            }
        } else {
            ventana.draw(sprite1);
        }
        while (ventana.pollEvent(evento)){
            if (evento.type == Event::Closed)
                ventana.close();
        }
        ventana.display();
    }

}
