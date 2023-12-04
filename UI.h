#pragma once
#include <SFML/Graphics.hpp>

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

void drawRectangle(int x, int y, sf::RenderWindow& window) {
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f(20, 20));
    rect.setOutlineColor(sf::Color::White);
    rect.setFillColor(sf::Color::Black);
    rect.setOutlineThickness(1);
    rect.setPosition(x, y);
    window.draw(rect);
}

void drawGrid(int w, int h, sf::RenderWindow& window, int rect_width=20) {
    for (int i = 40; i < w-40; i += rect_width) {
        for (int j = 150; j < h-150; j += rect_width) {
            drawRectangle(i, j, window);
        }
    }
}

void drawButtons(int w, int h, sf::RenderWindow& window, sf::Event& e) {
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
}

void drawBoard(int w, int h, sf::RenderWindow& window, sf::Event& e) {
    drawGrid(w, h, window);
    drawButtons(w, h, window, e);
}