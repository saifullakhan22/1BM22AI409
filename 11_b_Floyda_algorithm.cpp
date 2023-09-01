#include <iostream>
#include <climits>

using namespace std;

const int MAX_V = 100; // Maximum number of vertices
const int INF = INT_MAX; // Infinity

void floydWarshall(int graph[MAX_V][MAX_V], int V) {
    int dist[MAX_V][MAX_V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between all pairs of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    int graph[MAX_V][MAX_V];

    // Initialize the graph with infinity
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }

    cout << "Enter the edges and their weights (source, destination, weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // Initialize diagonal elements to 0
    for (int i = 0; i < V; i++) {
        graph[i][i] = 0;
    }

    floydWarshall(graph, V);

    return 0;
}
