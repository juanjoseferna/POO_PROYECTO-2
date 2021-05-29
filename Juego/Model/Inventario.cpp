//
// Created by finch on 28/05/2021.
//

#include "Inventario.h"

const int Inventario::CANTIDAD_MAX_ITEMS = 12;

Inventario::Inventario(){
}

Inventario::~Inventario() {
}

void Inventario::mostrarInventario(RenderWindow * ventana, Jugador * jugador){
    Event evento{};
    salida = false;
    texturaInventario.loadFromFile("../Img/inventario.png");
    spriteInventario.setTexture(texturaInventario);
    sleep(milliseconds(100));
    while(!Keyboard::isKeyPressed(Keyboard::E) && ventana->isOpen() && !salida) {
        ventana->clear();
        spriteInventario.setPosition(0,0);
        ventana->draw(spriteInventario);
        botonesInventario(ventana);
        while (ventana->pollEvent(evento)){
            if (evento.type == Event::Closed)
                ventana->close();
        }
        ventana->display();
    }
}

void Inventario::botonesInventario(RenderWindow * ventana) {
    int botonx1 = 220, botonx2 = 400 ,botonx3 = 444, botonx4 = 621, botonx5 = 670, botonx6 = 840, botonx7 = 890, botonx8 = 1060;
    int botony1 = 180, botony2 = 342, botony3 = 370, botony4 = 530, botony5 = 550, botony6 = 717;
    int menuSalidax1 = 1226, menuSalidax2 = 1280, menuSaliday1 = 0, menuSaliday2 = 42;
    if (Mouse::getPosition(*ventana).x >= botonx1 &&
        Mouse::getPosition(*ventana).x <= botonx2 &&
        Mouse::getPosition(*ventana).y >= botony1 &&
        Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton1" << std::endl;
            ////// x1y1
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx3 &&
               Mouse::getPosition(*ventana).x <= botonx4 &&
               Mouse::getPosition(*ventana).y >= botony1 &&
               Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton2" << std::endl;
            ////// x2y1
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx5 &&
              Mouse::getPosition(*ventana).x <= botonx6 &&
              Mouse::getPosition(*ventana).y >= botony1 &&
              Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton3" << std::endl;
            ////// x3y1
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx7 &&
               Mouse::getPosition(*ventana).x <= botonx8 &&
               Mouse::getPosition(*ventana).y >= botony1 &&
               Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton4" << std::endl;
            ////// x4y1
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx1 &&
               Mouse::getPosition(*ventana).x <= botonx2 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton5" << std::endl;
            ////// x1y2
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx3 &&
               Mouse::getPosition(*ventana).x <= botonx4 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton6" << std::endl;
            ////// x2y2
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx5 &&
               Mouse::getPosition(*ventana).x <= botonx6 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton7" << std::endl;
            ////// x3y2
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx7 &&
               Mouse::getPosition(*ventana).x <= botonx8 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton8" << std::endl;
            ////// x4y2
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx1 &&
               Mouse::getPosition(*ventana).x <= botonx2 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton9" << std::endl;
            ////// x1y3
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx3 &&
               Mouse::getPosition(*ventana).x <= botonx4 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton10" << std::endl;
            ////// x2y3
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx5 &&
               Mouse::getPosition(*ventana).x <= botonx6 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton11" << std::endl;
            ////// x3y3
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx7 &&
               Mouse::getPosition(*ventana).x <= botonx8 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton12" << std::endl;
            ////// x4y3
        }
    } else if (Mouse::getPosition(*ventana).x >= menuSalidax1 &&
               Mouse::getPosition(*ventana).x <= menuSalidax2 &&
               Mouse::getPosition(*ventana).y >= menuSaliday1 &&
               Mouse::getPosition(*ventana).y <= menuSaliday2) {
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton salir" << std::endl;
            salida = true;
        }
    }
}


void Inventario::agregarItemsInventario(Item* item){
    this->pItems.push_back(item);
}

vector<Item *> &Inventario::getListaItems() {
    return pItems;
}

