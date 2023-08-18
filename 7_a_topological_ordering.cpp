#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adjacencyMatrix;

    Graph(int vertices) {
        V = vertices;
        adjacencyMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
    }

    void topologicalSortUtil(int v, vector<int>& visited, vector<int>& stack) {
        visited[v] = 1;

        for (int i = 0; i < V; i++) {
            if (adjacencyMatrix[v][i] && !visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        stack.push_back(v);
    }

    void topologicalSort() {
        vector<int> visited(V, 0);
        vector<int> stack;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        cout << "Topological Ordering: ";
        for (int i = stack.size() - 1; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int vertices = 6;
    Graph graph(vertices);

    graph.addEdge(5, 2);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.topologicalSort();

    return 0;
}
