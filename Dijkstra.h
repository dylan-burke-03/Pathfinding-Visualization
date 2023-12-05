#include <cmath>
#include <queue>
#include "graph.h"
using namespace std;

struct compareNodes {
    bool operator()(const AdjMatrix::node& a, const AdjMatrix::node& b) const {
        return a.weight > b.weight;
    }
};

void dijkstra(AdjMatrix::node graph[96][54], AdjMatrix::node &start, AdjMatrix::node& end) {
    priority_queue<AdjMatrix::node, vector<AdjMatrix::node>, compareNodes> pq;
    pq.push(start);
    start.weight = 0;

    while (!pq.empty()) {
        AdjMatrix::node curr_node = pq.top();
        pq.pop();

        if (curr_node.prev_visited) continue;

        curr_node.prev_visited = true;

        if ((curr_node.x == end.x) && (curr_node.y == end.y)) break;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;

                int x = curr_node.x+i, y = curr_node.y+i;
                if (x >= 0 && x < 96 && y >= 0 && y < 54) {
                    AdjMatrix::node& adj = graph[x][y];
                    double weight = curr_node.weight + sqrt(i*i + j*j);
                    if (weight < adj.weight) {
                        adj.weight = weight;
                        adj.parent = &curr_node;
                        pq.push(adj);
                    }
                }
            }
        }
    }
}