#include <iostream>
#include <climits>

const int MAX_V = 100; // Maximum number of vertices
const int INF = INT_MAX; // Infinity

void floydWarshall(int graph[MAX_V][MAX_V], int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    int V, E;
    std::cout << "Enter the number of vertices and edges: ";
    std::cin >> V >> E;

    int graph[MAX_V][MAX_V];

    // Initialize the graph with infinity
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    std::cout << "Enter the edges and their weights (source, destination, weight):" << std::endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floydWarshall(graph, V);

    // Print the shortest distances
    std::cout << "Shortest distances between all pairs of vertices:" << std::endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            std::cout << (graph[i][j] == INF ? "INF " : std::to_string(graph[i][j]) + " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
