#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow w(VideoMode(750,500),"Prueba");
    sleep(milliseconds(20000));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
