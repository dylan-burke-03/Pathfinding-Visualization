#pragma once
#include <random>
#include <ctime> 
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

/*
    - graph
    - button generate obstacles
    - randomly generating obstacles, node class
*/
bool generateRandBool() {
    static std::default_random_engine generator(std::random_device{}());
    static std::bernoulli_distribution distribution(0.85);
    return distribution(generator);
}

class AdjMatrix {
    public:
        struct node {
            bool traversible; // (window_width / rect_size)
            sf::RectangleShape grid_element;
            int x, y;
            node() {};
            node(bool t, sf::RectangleShape& element, int p_x, int p_y) : traversible(t), grid_element(element), x(p_x), y(p_y) {};
        };

        node graph[96][54];
        AdjMatrix() {};

        void insertNode(int m, int n, int x, int y, sf::RectangleShape grid_e) {
            bool trav = generateRandBool();
            graph[m][n] = node(trav, grid_e, x, y);
        }

        node getNodeElement(int x, int y) {
            int m = floor(x/20), n = floor(y/20);
            return graph[m][n];
        }

        void drawWall(int x, int y) {
            int m = floor(x/20), n = floor(y/20);
            if (!graph[m][n].traversible) {
                graph[m][n].grid_element.setFillColor(sf::Color::Black);
            }
        }
};