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
    while(ventana->isOpen() && !salida) {
        ventana->clear();
        spriteInventario.setPosition(0,0);
        ventana->draw(spriteInventario);
        mostarItemsInventario(ventana);
        botonesInventario(ventana);
        while (ventana->pollEvent(evento)){
            if (evento.type == Event::Closed)
                ventana->close();
        }
        ventana->display();
    }
}

void Inventario::mostarItemsInventario(RenderWindow * ventana) {
    int x, y, contx = 0, conty = 0;
    for (int i = 0; i <= pItems.size() - 1; i++) {
        x = (botonx1 + 50 + (220 * contx));
        y = botony1 + 45 + (180 * conty);
        contx++;
        if( x > botonx8 ){
            contx = 0;
            conty++;
        }
        pItems[i]->pintarItemInventario(ventana, x, y);
    }
}

void Inventario::botonesInventario(RenderWindow * ventana) {
    if (Mouse::getPosition(*ventana).x >= botonx1 &&
        Mouse::getPosition(*ventana).x <= botonx2 &&
        Mouse::getPosition(*ventana).y >= botony1 &&
        Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)){
            std::cout << "Boton1" << std::endl;
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


void Inventario::agregarItemsInventario(Item * item){
    if(item->getSuelo() == 1) {
        std::cout << "agregado" << std::endl;
        item->recogerItemSuelo();
        this->pItems.push_back(item);
    }
}

vector<Item *> &Inventario::getListaItems() {
    return pItems;
}

