#include <SFML/Graphics.hpp>
#include <iostream>
#include "UI.h"
using namespace std;

int main()
{
    unsigned const int window_width = 1920, window_height = 1080;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Pathfinding Algorithm Visualizer");

    while (window.isOpen())
    {
        sf::Event event;
        sf::Mouse mouse;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                auto pos = mouse.getPosition(window);
                cout << pos.x << " " << pos.y << endl;
            }
                
        }
        window.clear();
        drawBoard(window_width, window_height, window, event);
        window.display();
    }

    return 0;
}