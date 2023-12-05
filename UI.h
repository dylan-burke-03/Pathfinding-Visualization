#pragma once
#include <utility>
#include <SFML/Graphics.hpp>
#include "graph.h"
#include "Dijkstra.h"
using namespace std;

void generateGraph(int w, int h, sf::RenderWindow& window, AdjMatrix& graph, int rect_width=20) {
    for (int i = 40; i < w-40; i+=rect_width) {
        for (int j = 140; j < h-140; j+=rect_width) {
            sf::RectangleShape rect; rect.setSize(sf::Vector2f(20, 20));
            rect.setPosition(i, j); rect.setOutlineColor(sf::Color::Black);
            rect.setOutlineThickness(1); rect.setFillColor(sf::Color::White);
            graph.insertNode(floor(i/20), floor(j/20), i, j, rect);
            graph.drawWall(i, j);
        }
    }
}

void drawGraph(sf::RenderWindow& window, AdjMatrix& graph, int rect_width=20) {
    for (int i = 40; i < 1920-40; i+=rect_width) {
        for (int j = 140; j < 1080-140; j+=rect_width) {
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

    bool start_clicked = false, a_star_clicked = false, dijkstra_clicked = false;
    if (e.type == sf::Event::MouseButtonPressed) {
        if (sf::Mouse::isButtonPressed) {
            cout << "Clicked" << endl;
        }
        /*
        if (e.mouseButton.button == m.Left) {
            auto pos = m.getPosition(window);
            if ((e.mouseButton.x >= 950 && e.mouseButton.x <= 1100) && (e.mouseButton.y >= 978 && e.mouseButton.y <= 1028)) {
                start_clicked = true;
                cout << "START" << endl;
            }
        }
        
        if ((pos.x >= 950 && pos.x <= 1100) && (pos.y >= 978 && pos.y <= 1028))
            start_clicked = true;
        if ((pos.x >= 400 && pos.x <= 550) && (pos.y >= 978 && pos.y <= 1028))

        if (pos.y >= 978 && pos.y <= 1028) {
            if (pos.x >= 950 && pos.x <= 1100) {
                start_clicked = true;
                cout << "START" << endl;
            }
            if (pos.x >= 400 && pos.x <= 550) a_star_clicked = true;
            if (pos.x >= 1500 && pos.x <= 1650) dijkstra_clicked = true;
        }
        */
    }
}

sf::Vector2i drawStart(sf::RenderWindow& window, AdjMatrix& graph, sf::Event& e, sf::Mouse& m, bool& start) {
    sf::Vector2i pos;
    if (e.type == sf::Event::MouseButtonPressed) {
        if (sf::Mouse::isButtonPressed) {
            if (start) {
                pos = m.getPosition(window);
                graph.getNodeElement(pos.x, pos.y).grid_element.setFillColor(sf::Color::Green);
                start = false;
            }
        }
    }
    return pos;
}

sf::Vector2i drawEnd(sf::RenderWindow& window, AdjMatrix& graph, sf::Event& e, sf::Mouse& m, bool& start, bool& end) {
    sf::Vector2i pos;
    if (e.type == sf::Event::MouseButtonPressed) {
        if (sf::Mouse::isButtonPressed) {
            if (end && !start) {
                pos = m.getPosition(window);
                graph.getNodeElement(pos.x, pos.y).grid_element.setFillColor(sf::Color::Red);
                end = false;
            }
        }
    }
    return pos;
}

pair<AdjMatrix::node, AdjMatrix::node> generateStartEnd(sf::RenderWindow& window, AdjMatrix& graph, int x1, int y1, int x2, int y2) {
    AdjMatrix::node& start_node = graph.getNodeElement(x1, y1);
    AdjMatrix::node& end_node = graph.getNodeElement(x2, y2);
    start_node.grid_element.setFillColor(sf::Color::Green);
    end_node.grid_element.setFillColor(sf::Color::Red);
    pair<AdjMatrix::node, AdjMatrix::node> start_end(start_node, end_node);
    return start_end;
}

void drawBoard(int w, int h, sf::RenderWindow& window, sf::Event& e, sf::Mouse& m, AdjMatrix& graph, bool& s, bool& end) {
    drawGraph(window, graph);
    drawButtons(w, h, window, e, m);
}

/*
void drawDijkstra(sf::RenderWindow& window, AdjMatrix& graph, AdjMatrix::node& start, AdjMatrix::node& end) {
    dijkstra(graph.graph, start, end);
    for (auto n : graph.graph) {
        if (n->prev_visited) {
            n->grid_element.setFillColor(sf::Color::Blue);
        }
    }
}
*/