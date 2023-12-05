#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Node { //Created a node struct to show necessary characteristics to complete algorithm
    int x;
    int y;
    double g;
    double h;
    double f;
    Node& parent;
    bool isObstacle;

    Node(int x, int y, const Node& parentNode) : x(x), y(y), g(0), h(0), f(0), parent(parentNode), isObstacle(false) {}

    double heuristic(const Node& end) const {

        return abs(x - end.x) + abs(y - end.y);

    }
};

struct NodeEqual {
    int x;
    int y;

    NodeEqual(int x, int y) : x(x), y(y) {}

    bool operator()(const Node& node) const {
        return node.x == x && node.y == y;
    }
};

struct PickNode {
    bool operator()(const Node& left, const Node& right) const {

        return left.f > right.f;

    }
};

// Function to check if a given position is valid in the grid
bool checkValid(int x, int y, const vector<vector<int>>& grid) {

    return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !grid[x][y].isObstacle;

}

// Function to get neighboring nodes based on the grid
vector<Node*> findNeighbors(const Node& node, const vector<vector<int>>& grid) {

    vector<Node> neighbors;
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; ++i) {

        int tempX = node.x + dx[i];
        int tempY = node.y + dy[i];

        if (checkValid(tempX, tempY, grid)) {

            neighbors.emplace_back(tempX, tempY, node));

        }
    }

    return neighbors;

}

// A* algorithm function
void astar(const vector<vector<int>>& grid, Node begin, Node end) {

    priority_queue<Node, vector<Node>, PickNode> openSet;
    vector<Node*> closedSet;

    openSet.push(begin);

    while (!openSet.empty()) {

        Node nodeCurr = openSet.top();
        openSet.pop();

        closedSet.push_back(nodeCurr);

        if (nodeCurr.x == end.x && nodeCurr.y == end.y) {

            // Reconstruct and print the path
            Node* path = &nodeCurr;

            while (path != nullptr) {

                pathNode = &path->parent;

            }

            break;

        }

        vector<Node> neighbors = findNeighbors(nodeCurr, grid);

        for (const Node& neighbor : neighbors) {

            // Check if the neighbor is in the closed set
            auto val = find_if(closedSet.begin(), closedSet.end(), NodeEqual(neighbor.x, neighbor.y));

            if (val != closedSet.end()) {
                continue;
            }

            double tempGVal = nodeCurr.g + 1; //Uniform costs

            // Check if neighbor is in open set or alternate path is optimal
            auto valOpen = find_if(openSet.c.begin(), openSet.c.end(), NodeEqual(neighbor.x, neighbor.y)});

            if (valOpen == openSet.end() || tempGVal < neighbor.g) {

                neighbor.g = tempGVal;
                neighbor.h = neighbor.heuristic(end);
                neighbor.f = neighbor.g + neighbor.h;

                if (valOpen == openSet.end()) {

                    openSet.push(neighbor);

                }
            }
        }
    }
}


/*
 * int main() { //Example main for input and implementation
    // Example 96x54 grid
    vector<vector<Node>> grid(96, vector<Node>(54, Node(0,0)));

    // Example begin and end nodes
    // Could possibly prompt for inputted begin and end nodes
    Node begin(0, 0);
    Node end(95, 53);

    astar(grid, begin, end);

    return 0;
}
*/