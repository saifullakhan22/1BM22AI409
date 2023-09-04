#include <iostream>
#include <unordered_set>
#include <unordered_map>

void dfs(const std::unordered_map<std::string, std::unordered_set<std::string>>& graph, const std::string& node, std::unordered_set<std::string>& visited) {
    visited.insert(node);

    for (const std::string& neighbor : graph.at(node)) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, neighbor, visited);
        }
    }
}

bool isGraphConnected(const std::unordered_map<std::string, std::unordered_set<std::string>>& graph) {
    if (graph.empty()) {
        return false;
    }

    std::unordered_set<std::string> visited;

    // Start DFS from the first node in the graph
    dfs(graph, graph.begin()->first, visited);

    return visited.size() == graph.size();
}

int main() {
    std::unordered_map<std::string, std::unordered_set<std::string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"C", "D"}},
        {"C", {"D", "E"}},
        {"D", {"E"}},
        {"E", {"F"}},
        {"G", {"M"}}
    };

    if (isGraphConnected(graph)) {
        std::cout << "Connected Graph";
    } else {
        std::cout << "Disconnected Graph";
    }

    return 0;
}
