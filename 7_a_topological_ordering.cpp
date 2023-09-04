#include <iostream>

using namespace std;

class Graph {
public:
    int V;
    int** adjacencyMatrix;

    Graph(int vertices) {
        V = vertices;
        adjacencyMatrix = new int*[V];
        for (int i = 0; i < V; ++i) {
            adjacencyMatrix[i] = new int[V]();
        }
    }

    void addEdge(int u, int v) {
        adjacencyMatrix[u][v] = 1;
    }

    void topologicalSortUtil(int v, int* visited, int* stack, int& index) {
        visited[v] = 1;

        for (int i = 0; i < V; i++) {
            if (adjacencyMatrix[v][i] && !visited[i]) {
                topologicalSortUtil(i, visited, stack, index);
            }
        }

        stack[index++] = v;
    }

    void topologicalSort() {
        int* visited = new int[V]();
        int* stack = new int[V]();
        int index = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack, index);
            }
        }

        cout << "Topological Ordering: ";
        for (int i = index - 1; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;

        delete[] visited;
        delete[] stack;
    }

    ~Graph() {
        for (int i = 0; i < V; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
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
