#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void BFS(int startNode) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

private:
    int V; // Number of vertices
    vector<vector<int>> adjList;
};

int main() {
    int vertices = 7; // Total number of vertices
    int edges = 8;    // Total number of edges

    Graph graph(vertices);

    // Adding edges to the graph
    graph.addEdge(0, 1);
  //  graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 5);
    graph.addEdge(2, 6);
    graph.addEdge(4, 6);
    graph.addEdge(5, 6);

    int startNode = 0; // Starting node

    cout << "Nodes reachable from starting node " << startNode << " are: ";
    graph.BFS(startNode);

    return 0;
}
