//Check if the given graph is connected or not using DFS method.
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <unordered_map>

void dfs(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& node, std::unordered_set<std::string>& visited) {
    visited.insert(node);

    for (const std::string& neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}

bool allNodesVisitedFromFirstNode(std::unordered_map<std::string, std::vector<std::string>>& graph) {
    std::unordered_set<std::string> visited;

    // Choose the first node as a starting point for DFS
    std::string start_node = graph.begin()->first;

    dfs(graph, start_node, visited);

    return visited.size() == graph.size();
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"C", "D"}},
        {"C", {"D", ""}},
        {"D", {""}},
        {"E", {""}}
    };

    if (allNodesVisitedFromFirstNode(graph)) {
        std::cout << "Graph is connected" << std::endl;
    } else {
        std::cout << "Graph is not connected" << std::endl;
    }

    return 0;
}
