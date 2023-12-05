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

    //Node structure to allow for input of adjacency matrix with nodes
    Node(int x, int y, Node* defaultParent) : x(x), y(y), prevVisited(false), distance(INT_MAX), parent(defaultParent) {}
};

//Function to help the priority queue ensure it is prioritized based on distance
struct CompareNodes { 
    bool operator()(const Node& a, const Node& b) const {
        return a.distance > b.distance;
    }
};

//Dijkstra's algorithm function that takes in the adjacency matrix of nodes
//Also takes in specified start and end nodes
void dijkstra(const vector<vector<Node>>& adjacencyMatrix, vector<vector<Node>>& grid, Node& begin, Node& end) {
    priority_queue<Node, vector<Node>, CompareNodes> pq; //Priority queue that prioritizes based on distance
    pq.push(begin);
    begin.distance = 0;

    while (!pq.empty()) {

        Node& now = pq.top();
        pq.pop();

        if (now.prevVisited) continue; //Checks if current node has already been visited

        now.prevVisited = true;

        if (now == end) break; //Checks if current node is the set end node for the function

        for (int i = -1; i <= 1; i++) { //Loops through neighboring nodes

            for (int j = -1; j <= 1; j++) {

                if (i == 0 && j == 0) continue;

                int x = now.x + i; //Updates current node
                int y = now.y + j;

                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && adjacencyMatrix[x][y] != 0) {  //Updates distance based on current node

                    Node& adj = grid[x][y];
                    double distance = now.distance + sqrt(i * i + j * j);

                    if (distance < adj.distance) {

                        adj.distance = distance;
                        adj.parent = &now;
                        pq.push(adj); //Adds node to priority queue

                    }
                }
            }
        }
    }
}

