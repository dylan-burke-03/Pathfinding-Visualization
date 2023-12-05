#include <SFML/Graphics.hpp>
#include "UI.h"
using namespace std;

int main()
{
    unsigned const int window_width = 1920, window_height = 1080;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Pathfinding Algorithm Visualizer");
    AdjMatrix graph = AdjMatrix();
    generateGraph(window_width, window_height, window, graph);
    auto start_end = generateStartEnd(window, graph, 448, 321, 1805, 461);
    //drawDijkstra(window, graph, start_end.first, start_end.second);

    sf::Event event;
    sf::Mouse mouse;
    bool start_clicked = false, a_star_clicked = false, dijkstra_clicked = false;
    bool start_point = true, end_point = true;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                case sf::Event::MouseButtonPressed:
                    cout << "Mouse button pressed" << endl;
                    if (sf::Mouse::isButtonPressed) {
                        auto pos = mouse.getPosition(window);
                        cout << pos.x << " " << pos.y << endl;
                        if (((pos.x >= 950) && (pos.x <= 1100)) && ((pos.y >= 978) && (pos.y <= 1028))) {
                            start_clicked = true;
                            cout << start_clicked << endl;
                        }
                    }
            }
        }
        window.clear();
        drawBoard(window_width, window_height, window, event, mouse, graph, start_point, end_point);
        window.display();
    }

    return 0;
}