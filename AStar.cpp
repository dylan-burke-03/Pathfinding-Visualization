#include "graph.h"
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

  bool operator()(const AdjMatrix::node& node) const
  {
    return node.x == x && node.y == y;
  }
};

struct PickNode { //Allows for the comparing of two neighboring nodes to check cost
  bool operator()(const AdjMatrix::node* left, const AdjMatrix::node* right) const
  {

    return left->f > right->f;
  }
};

// Function to check if a given position is valid in the grid
bool checkValid(int x, int y, const vector<vector<int> >& grid)
{

  return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !grid[x][y].isObstacle;
}

// Function to get neighboring nodes based on the grid
vector<AdjMatrix::node*> findNeighbors(const AdjMatrix::node& node, const vector<vector<int> >& grid)
{

  vector<AdjMatrix::node*> neighbors;
  const int dx[] = { 1, -1, 0, 0 };
  const int dy[] = { 0, 0, 1, -1 };

  for (int i = 0; i < 4; ++i) {

    int tempX = node.x + dx[i];
    int tempY = node.y + dy[i];

    if (checkValid(tempX, tempY, grid)) {

      neighbors.push_back(new AdjMatrix::node(tempX, tempY));
    }
  }

  return neighbors;
}

// A* algorithm function
void astar(const vector<vector<int> >& grid, AdjMatrix::node begin, AdjMatrix::node end)
{

  priority_queue<AdjMatrix::node*, vector<AdjMatrix::node*>, PickNode> openSet;
  vector<AdjMatrix::node*> closedSet;

  openSet.push(new AdjMatrix::node(begin));

  while (!openSet.empty()) {

    AdjMatrix::node* nodeCurr = openSet.top();
    openSet.pop();

    closedSet.push_back(nodeCurr);

    if (nodeCurr->x == end.x && nodeCurr->y == end.y) {

      // Reconstruct and print the path
      AdjMatrix::node* path = nodeCurr;

      while (path != nullptr) {

        pathNode = path->parent;
      }

      break;
    }

    vector<AdjMatrix::node*> neighbors = findNeighbors(*nodeCurr, grid);

    for (AdjMatrix::node* neighbor : neighbors) {

      // Check if the neighbor is in the closed set
      auto val = find_if(closedSet.begin(), closedSet.end(), [&](const AdjMatrix::node* temp) { return temp->x == neighbor->x && temp->y == neighbor->y; });

      if (val != closedSet.end()) {
        continue;
      }

      double tempGVal = nodeCurr->g + 1; // Uniform costs

      // Check if neighbor is in open set or alternate path is optimal
      auto valOpen = find_if(openSet.c.begin(), openSet.c.end(), [&](const AdjMatrix::node* temp) { return temp->x == neighbor->x && temp->y == neighbor->y; });

      if (valOpen == openSet.end() || tempGVal < neighbor->g) {

        neighbor->g = tempGVal;
        neighbor->h = neighbor->heuristic(end);
        neighbor->f = neighbor->g + neighbor->h;
        neighbor->parent = nodeCurr;

        if (valOpen == openSet.end()) {

          openSet.push(neighbor);
        }
      }
    }
  }

  // Clean up allocated memory
  for (AdjMatrix::node* node : closedSet) {
    delete node;
  }
  for (AdjMatrix::node* node : openSet) {
    delete node;
  }
}
Node

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
