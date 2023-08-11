//Check if the given graph is connected or not using DFS method.
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

bool allNodesReachable(std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start_node) {
    std::unordered_set<std::string> visited;

    dfs(graph, start_node, visited);

    return visited.size() == graph.size();
}

int main() {
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"C", "D"}},
        {"C", {"D", "E"}},
        {"D", {"E"}},
        {"E", {"F"}},
        {"G", {"M"}}
    };

    std::string start_node = "A";

    if (allNodesReachable(graph, start_node)) {
        std::cout << "Connected Graph";
    } else {
        std::cout << "Disconnected Graph";
    }

    return 0;
}

}
