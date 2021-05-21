//
// Created by finch on 20/05/2021.
//

#ifndef PROYECTOJUEGO_VIEW_H
#define PROYECTOJUEGO_VIEW_H

#include "../Controller/Controller.h"


class Viewer {
private:
    Controller controller;
public:
    Viewer();
    void iniciar();
};


#endif //PROYECTOJUEGO_VIEW_H
