#pragma once
#include <vector>
#include <random>
#include <ctime> 
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

bool generateRandBool() { // generates random boolean value for wall generation
    static std::default_random_engine generator(std::random_device{}());
    static std::bernoulli_distribution distribution(0.85);
    return distribution(generator);
}

class AdjMatrix {
    public:
        struct node {
            bool traversible, prev_visited = false; // (window_width / rect_size) 
            sf::RectangleShape grid_element;
            node* parent;
            int x, y, weight=INT_MAX; // variables for Dijkstra's
            double g, h, f; // variables for A*
            
            double heuristic(const node& end) const { // helper function for A*
               return abs(x - end.x) + abs(y - end.y);
            }

            node() {};
            node(bool t, sf::RectangleShape& element, int p_x, int p_y) : traversible(t), grid_element(element), x(p_x), y(p_y) {};
        };

        node graph[96][54];

        AdjMatrix() {}; // default constructor

        void insertNode(int m, int n, int x, int y, sf::RectangleShape grid_e) {
            bool trav = generateRandBool();
            graph[m][n] = node(trav, grid_e, x, y); // inserts node at position (m, n) in graph
        }

        node& getNodeElement(int x, int y) { // retrieves the node element from graph given coords
            int m = floor(x/20), n = floor(y/20);
            return graph[m][n];
        }

        void drawWall(int x, int y) { // constructs wall on the screen if graph element is not traversible
            int m = floor(x/20), n = floor(y/20);
            if (!graph[m][n].traversible) {
                graph[m][n].grid_element.setFillColor(sf::Color::Black);
            }
        }
};