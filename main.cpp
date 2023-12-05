#include <SFML/Graphics.hpp>
#include "UI.h"
using namespace std;

int main()
{
    // Create a 1920x1080 window
    unsigned const int window_width = 1920, window_height = 1080;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Pathfinding Algorithm Visualizer");
    // Make graph
    AdjMatrix graph = AdjMatrix();
    generateGraph(window_width, window_height, window, graph);
    // Generate start and end points for algorithm
    auto start_end = generateStartEnd(window, graph, 448, 321, 1805, 461);
    //drawDijkstra(window, graph, start_end.first, start_end.second);

    // Variables for event polling
    sf::Event event;
    sf::Mouse mouse;
    bool start_clicked = false, a_star_clicked = false, dijkstra_clicked = false;
    bool start_point = true, end_point = true;

    // Window loop
    while (window.isOpen())
    {
        // Poll events
        while (window.pollEvent(event))
        {
            switch (event.type) {
                // Close window
                case sf::Event::Closed:
                    window.close();
                // Mouse click
                case sf::Event::MouseButtonPressed:
                    cout << "Mouse button pressed" << endl;
                    if (sf::Mouse::isButtonPressed) {
                        // Get position of mouse click
                        auto pos = mouse.getPosition(window);
                        cout << pos.x << " " << pos.y << endl;
                        if (((pos.x >= 950) && (pos.x <= 1100)) && ((pos.y >= 978) && (pos.y <= 1028))) {
                            start_clicked = true;
                            cout << start_clicked << endl;
                        }
                    }
            }
        }
        // Draw window
        window.clear();
        drawBoard(window_width, window_height, window, event, mouse, graph, start_point, end_point);
        window.display();
    }

    return 0;
}
