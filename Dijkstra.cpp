#include <SFML/Graphics.hpp>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

class Node {
public:
    int x, y;
    bool prevVisited;
    double distance;
    Node* parent;

    Node(int x, int y, Node* defaultParent) : x(x), y(y), prevVisited(false), distance(INT_MAX), parent(defaultParent) {}
};

struct CompareNodes {
    bool operator()(const Node& a, const Node& b) const {
        return a.distance > b.distance;
    }
};

void dijkstra(const vector<vector<Node>>& adjacencyMatrix, vector<vector<Node>>& grid, Node& begin, Node& end) {
    priority_queue<Node, vector<Node>, CompareNodes> pq;
    pq.push(begin);
    begin.distance = 0;

    while (!pq.empty()) {

        Node& now = pq.top();
        pq.pop();

        if (now.prevVisited) continue;

        now.prevVisited = true;

        if (now == end) break;

        for (int i = -1; i <= 1; i++) {

            for (int j = -1; j <= 1; j++) {

                if (i == 0 && j == 0) continue;

                int x = now.x + i;
                int y = now.y + j;

                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && adjacencyMatrix[x][y] != 0) {

                    Node& adj = grid[x][y];
                    double distance = now.distance + sqrt(i * i + j * j);

                    if (distance < adj.distance) {

                        adj.distance = distance;
                        adj.parent = &now;
                        pq.push(adj);

                    }
                }
            }
        }
    }
}

