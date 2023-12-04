#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include "graph.h"
using namespace std;


// key of map be node
// contents of list would be nodes pointing to it
/*
Sunday:
    - Board drawing and click registration
    - Graph representation of grid 

Monday:
    - Change Font
    - A* search on graph
    - A* visualization
    - Final touches
*/

void generateGraph(int w, int h, sf::RenderWindow& window, AdjMatrix& graph, int rect_width=20) {
    for (int i = 40; i < w-40; i+=rect_width) {
        for (int j = 150; j < h-150; j+=rect_width) {
            sf::RectangleShape rect; rect.setSize(sf::Vector2f(20, 20));
            rect.setPosition(i, j); rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1); rect.setFillColor(sf::Color::White);
            graph.insertNode(floor(i/20), floor(j/20), i, j, rect);
            graph.drawWall(i, j);
        }
    }
}

void drawGraph(sf::RenderWindow& window, AdjMatrix& graph) {
    for (int i = 40; i < 1920-40; i+=20) {
        for (int j = 150; j < 1080-150; j++) {
            //auto node = graph.getNodeElement(i, j);
            //if (node.traversible) node.grid_element.setFillColor(sf::Color::Black);
            auto node = graph.getNodeElement(i, j);
            window.draw(node.grid_element);
        }
    }
}

void drawButtons(int w, int h, sf::RenderWindow& window, sf::Event& e, sf::Mouse& m) {
    sf::RectangleShape start, a_star, dijkstra;
    sf::Vector2f rect_size = sf::Vector2f(150, 50);
    sf::Font serif; serif.loadFromFile("src/serif.otf");
    sf::Text start_txt("START", serif), a_star_txt("A*", serif), dijkstra_txt("Dijkstra's", serif);
    start_txt.setPosition(975, 978);
    start_txt.setStyle(sf::Text::Bold);
    a_star_txt.setPosition(425, 978);
    dijkstra_txt.setPosition(1525, 978);

    start.setSize(rect_size); a_star.setSize(rect_size); dijkstra.setSize(rect_size);
    start.setPosition(950, 978);
    start.setFillColor(sf::Color::Blue);
    a_star.setPosition(400, 978);
    a_star.setFillColor(sf::Color::Blue);
    dijkstra.setPosition(1500, 978); 
    dijkstra.setFillColor(sf::Color::Blue);

    window.draw(start);
    window.draw(a_star);
    window.draw(dijkstra);
    window.draw(start_txt);
    window.draw(a_star_txt);
    window.draw(dijkstra_txt);
    if (e.type == sf::Event::MouseButtonPressed)
        auto pos = m.getPosition(window);

}

void drawBoard(int w, int h, sf::RenderWindow& window, sf::Event& e, sf::Mouse& m, AdjMatrix& graph) {
    drawButtons(w, h, window, e, m);
    drawGraph(window, graph);
}