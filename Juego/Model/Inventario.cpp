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
        botonesInventario(ventana, jugador);
        while (ventana->pollEvent(evento)){
            if (evento.type == Event::Closed)
                ventana->close();
        }
        ventana->display();
    }
}

void Inventario::mostarItemsInventario(RenderWindow * ventana) {
    int x, y, contx = 0, conty = 0;
    for (int i = 0; i < pItems.size(); i++) {
        x = (botonx1 + 50 + (220 * contx));
        y = botony1 + 45 + (180 * conty);
        contx++;
        if( x >= botonx7 ){
            contx = 0;
            conty++;
        }
        if(pItems[i] != nullptr) {
            pItems[i]->pintarItemInventario(ventana, x, y);
        }
    }
}

void Inventario::eliminarItem(Item * item){
    int contx = 0;
    for (int i = 0; i <= pItems.size() - 1; i++) {
        contx++;
        if(item == pItems[i]){
            pItems.erase(pItems.begin() + i);
        }
    }
}

void Inventario::botonesInventario(RenderWindow * ventana, Jugador * jugador) {
    if (Mouse::getPosition(*ventana).x >= botonx1 &&
        Mouse::getPosition(*ventana).x <= botonx2 &&
        Mouse::getPosition(*ventana).y >= botony1 &&
        Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)){
            if(pItems[0] != nullptr){
                pItems[0]->usarItem(jugador);
            }
        } else if (Mouse::isButtonPressed(Mouse::Right)){
            eliminarItem(pItems[0]);
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx3 &&
               Mouse::getPosition(*ventana).x <= botonx4 &&
               Mouse::getPosition(*ventana).y >= botony1 &&
               Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[1] != nullptr){
                pItems[1]->usarItem(jugador);
            }
        } else if (Mouse::isButtonPressed(Mouse::Right)){
            eliminarItem(pItems[1]);
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx5 &&
              Mouse::getPosition(*ventana).x <= botonx6 &&
              Mouse::getPosition(*ventana).y >= botony1 &&
              Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            std::cout << "Boton3" << std::endl;
            if(pItems[2] != nullptr){
                pItems[2]->usarItem(jugador);
            }
        } else if (Mouse::isButtonPressed(Mouse::Right)){
            eliminarItem(pItems[2]);
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx7 &&
               Mouse::getPosition(*ventana).x <= botonx8 &&
               Mouse::getPosition(*ventana).y >= botony1 &&
               Mouse::getPosition(*ventana).y <= botony2){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[3] != nullptr){
                pItems[3]->usarItem(jugador);
            }
        } else if (Mouse::isButtonPressed(Mouse::Right)){
            eliminarItem(pItems[3]);
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx1 &&
               Mouse::getPosition(*ventana).x <= botonx2 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[4] != nullptr){
                pItems[4]->usarItem(jugador);
            }
        }else if (Mouse::isButtonPressed(Mouse::Right)){
            eliminarItem(pItems[4]);
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx3 &&
               Mouse::getPosition(*ventana).x <= botonx4 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[5] != nullptr){
                pItems[5]->usarItem(jugador);
            }
        }else if (Mouse::isButtonPressed(Mouse::Right)){
            eliminarItem(pItems[5]);
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx5 &&
               Mouse::getPosition(*ventana).x <= botonx6 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[6] != nullptr){
                pItems[6]->usarItem(jugador);
            }
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx7 &&
               Mouse::getPosition(*ventana).x <= botonx8 &&
               Mouse::getPosition(*ventana).y >= botony3 &&
               Mouse::getPosition(*ventana).y <= botony4){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[7] != nullptr){
                pItems[7]->usarItem(jugador);
            }
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx1 &&
               Mouse::getPosition(*ventana).x <= botonx2 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[8] != nullptr){
                pItems[8]->usarItem(jugador);
            }
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx3 &&
               Mouse::getPosition(*ventana).x <= botonx4 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[9] != nullptr){
                pItems[9]->usarItem(jugador);
            }
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx5 &&
               Mouse::getPosition(*ventana).x <= botonx6 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[10] != nullptr){
                pItems[10]->usarItem(jugador);
            }
        }
    } else if (Mouse::getPosition(*ventana).x >= botonx7 &&
               Mouse::getPosition(*ventana).x <= botonx8 &&
               Mouse::getPosition(*ventana).y >= botony5 &&
               Mouse::getPosition(*ventana).y <= botony6){
        sleep(milliseconds(100));
        if (Mouse::isButtonPressed(Mouse::Left)) {
            if(pItems[11] != nullptr){
                pItems[11]->usarItem(jugador);
            }
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
    if(item->getSuelo() == 1 && pItems.size() < 12) {
        std::cout << "agregado" << std::endl;
        item->recogerItemSuelo();
        this->pItems.push_back(item);
    }
}

vector<Item *> &Inventario::getListaItems() {
    return pItems;
}

