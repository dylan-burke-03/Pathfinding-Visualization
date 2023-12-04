#include <SFML/Graphics.hpp>
#include "UI.h"
using namespace std;

int main()
{
    unsigned const int window_width = 1920, window_height = 1080;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Pathfinding Algorithm Visualizer");
    AdjMatrix graph = AdjMatrix();
    generateGraph(window_width, window_height, window, graph);
    while (window.isOpen())
    {
        sf::Event event;
        sf::Mouse mouse;
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                case sf::Event::MouseButtonPressed:
                    auto pos = mouse.getPosition(window);
                    cout << pos.x << " " << pos.y << endl;
            }
        }
        window.clear();
        drawBoard(window_width, window_height, window, event, mouse, graph);
        window.display();
    }

    return 0;
}