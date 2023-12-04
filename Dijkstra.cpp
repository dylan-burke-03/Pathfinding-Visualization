#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include <cmath>
#include "UI.h"

using namespace std;

class Node {
public:
    int x, y;
    bool prevVisited;
    double distance;
    Node *parent;

    Node(int x, int y) : x(x), y(y), prevVisited(false), distance(INT_MAX), parent(nullptr) {}
};

void dijkstra(vector<vector<Node>> &grid, Node &begin, Node &end) {

    priority_queue<Node*, vector<Node*>, [](Node *a, Node *b) {return a->distance > b->distance;}> pq;
    pq.push(&begin);
    begin.distance = 0;

    while (!pq.empty()) {

        Node *now = pq.top();
        pq.pop();

        if (now->prevVisited) continue;

        now->prevVisited = true;

        if (now == &end) break;

        for (int i = -1; i <= 1; i++) {

            for (int j = -1; j <= 1; j++) {

                if (i == 0 && j == 0) continue;

                int x = now->x + i;
                int y = now->y + j;

                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) {

                    Node *adj = &grid[x][y];
                    double distance = now->distance + sqrt(i * i + j * j);

                    if (distance < adj->distance) {

                        adj->distance = distance;
                        adj->parent = now;
                        pq.push(adj);

                    }
                }
            }
        }
    }
}

int main() {
    int w = 1000;
    int h = 1000;
    int rect_width = 20;

    vector<vector<Node>> grid(w / rect_width, vector<Node>(h / rect_width));
    for (int i = 0; i < w / rect_width; i++) {
        for (int j = 0; j < h / rect_width; j++) {
            grid[i][j] = Node(i, j);
        }
    }

    // Initialize the begin and end nodes here.
    Node &begin = grid[0][0];
    Node &end = grid[w / rect_width - 1][h / rect_width - 1];

    sf::RenderWindow window(sf::VideoMode(w, h), "Dijkstra's Algorithm");

    while (window.isOpen()) {

        sf::Event e;
        while (window.pollEvent(e)) {

            if (e.type == sf::Event::Closed)
                window.close();

        }

        window.clear();
        dijkstra(grid, begin, end);

        for (int i = 0; i < w / rect_width; i++) {

            for (int j = 0; j < h / rect_width; j++) {

                sf::RectangleShape rect(sf::Vector2f(rect_width, rect_width));
                rect.setPosition(i * rect_width, j * rect_width);

                if (grid[i][j].prevVisited) {

                    rect.setFillColor(sf::Color::Red);

                } else {

                    rect.setFillColor(sf::Color::Green);

                }

                window.draw(rect);
            }
        }

        window.display();
    }

    return 0;
}
