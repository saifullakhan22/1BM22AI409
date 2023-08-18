#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Graph {
    int V;
    int** adjacencyMatrix;
};

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = vertices;

    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    graph->adjacencyMatrix[u][v] = 1;
}

void topologicalSortUtil(struct Graph* graph, int v, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1;

    for (int i = 0; i < graph->V; i++) {
        if (graph->adjacencyMatrix[v][i] && !visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, stackIndex);
        }
    }

    stack[(*stackIndex)++] = v;
}

void topologicalSort(struct Graph* graph) {
    int visited[MAX_VERTICES] = {0};
    int stack[MAX_VERTICES];
    int stackIndex = 0;

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }

    printf("Topological Ordering: ");
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
