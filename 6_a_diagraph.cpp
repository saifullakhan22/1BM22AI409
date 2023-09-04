#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 7;

class Graph {
public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int src, int dest) {
        adjacencyList[src][dest] = true;
    }

    void BFS(int startNode) {
        bool visited[MAX_VERTICES] = {false};
        queue<int> q;
        q.push(startNode);
        visited[startNode] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor = 0; neighbor < V; ++neighbor) {
                if (adjacencyList[current][neighbor] && !visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

private:
    int V; // Number of vertices
    bool adjacencyList[MAX_VERTICES][MAX_VERTICES] = {false};
};

int main() {
    int vertices = 7; // Total number of vertices

    Graph graph(vertices);

    // Adding edges to the graph
    graph.addEdge(0, 1);
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
