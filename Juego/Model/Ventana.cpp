//
// Created by finch on 20/05/2021.
//

#include "Ventana.h"
const int Ventana::ancho = 1280;
const int Ventana::alto = 804;

Ventana::Ventana() {
};

Ventana::~Ventana() {
}

void Ventana::menuDificultad() {
    while (!salida && ventana.isOpen()){
        Event evento{};
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            ventana.close();
        }
        sprite.setTexture(dificultad);
        ventana.draw(sprite);//dibuja en ventana el menu de dificultad
        if (Mouse::getPosition(ventana).x >= x1Global &&
            Mouse::getPosition(ventana).x <= x2Global &&
            Mouse::getPosition(ventana).y >= y1Facil &&
            Mouse::getPosition(ventana).y <= y2Facil &&
            (sprite.getTexture() == &dificultad ||
             sprite.getTexture() == &dificultadNormal ||
             sprite.getTexture() == &dificultadFacil ||
             sprite.getTexture() == &dificultadVolver)){
            sprite.setTexture(dificultadFacil);
            ventana.draw(sprite);//pre selecciona la opcion al estar el mouse encima de el
            sleep(milliseconds(100));
            if (Mouse::isButtonPressed(Mouse::Left)){//si el mouse se para sobre el boton de dificultad pesadilla se selecciona y si da click lo manda al mapa
                cantEnemegosPesadilla = 14;//cantidad de enemigos en el mapa
                jugador.crearJugador();//crea el jugador
                mapa.mostrarMapa(&ventana,&jugador,cantEnemegosPesadilla);//muestra el mapa en ventana
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
                ventana.draw(sprite);//pre selecciona la opcion al estar el mouse encima de el
                sleep(milliseconds(100));
                if (Mouse::isButtonPressed(Mouse::Left)){//si el mouse se para sobre el boton de dificultad infernal se selecciona y si da click lo manda al mapa
                    cantEnemigosInfernal = 16;//cantidad de enemigos
                    jugador.crearJugador();//crea el jugador
                    mapa.mostrarMapa(&ventana,&jugador,cantEnemigosInfernal);//muestra el mapa del juego en ventana
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
            sprite.setTexture(dificultadVolver);//si el mouse se para sobre el boton volver se selecciona y si da click lo sacara al menu principal
            ventana.draw(sprite);//pre selecciona la opcion al estar el mouse encima de el
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
    ventana.create(VideoMode(ancho, alto), "LA GUERRA DE LOS FLIP FLOPS");//nombre de la ventana
    menu.loadFromFile("../Img/mainMenu.png");//cargar texturas a utilizar
    menuSalida.loadFromFile("../Img/seleccionarSalir.png");
    menuJugar.loadFromFile("../Img/seleccionarIniciar.png");
    icono.loadFromFile("../Img/Icono.png");
    dificultad.loadFromFile("../Img/menuJugador.png");
    dificultadNormal.loadFromFile("../Img/opcionInfernal.png");
    dificultadFacil.loadFromFile("../Img/opcionPesadilla.png");
    dificultadVolver.loadFromFile("../Img/opcionRegresar.png");
    ventana.setIcon(icono.getSize().x, icono.getSize().y, icono.getPixelsPtr());
    while (ventana.isOpen()){
        salida = false;
        sprite.setTexture(menu);
        Event evento{};
        ventana.clear();
        ventana.draw(sprite);//se dibuja en ventana la textura del menu
        if (Keyboard::isKeyPressed(Keyboard::Escape)){//si precionas escape se saldra del juego
            ventana.close();//cierra la ventana
        }
        if (Mouse::getPosition(ventana).x >= x1Global &&
                Mouse::getPosition(ventana).x <= x2Global &&
                Mouse::getPosition(ventana).y >= y1Salida &&
                Mouse::getPosition(ventana).y <= y2Salida &&
                (sprite.getTexture() == &menu ||
                 sprite.getTexture() == &menuJugar ||
                 sprite.getTexture() == &menuSalida)){//si el mouse se para sobre el boton salida se selecciona y si da click lo sacara del juego
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
            sleep(milliseconds(100));//si el mouse se para sobre el boton jugar se selecciona y si da click lo mada al menu de seleccionar dificultad
            if (Mouse::isButtonPressed(Mouse::Left) &&
                sprite.getTexture() == &menuJugar){//carga menu dificultad
                menuDificultad();
            }
        }
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed)
                ventana.close();
        }
        ventana.setFramerateLimit(120);
        ventana.display();
    }
}

RenderWindow *Ventana::getVentana() {//obtener ventana
    return &ventana;
}
