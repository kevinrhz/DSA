#include <iostream>
#include <vector>
#include <string>

#include "Structures/Graph.h"
#include "Algorithms/BFS.h"
#include "Algorithms/DFS.h"
#include "Algorithms/Dijkstra.h"

using namespace dsa;

template<typename T>
void printTraversal(const std::vector<T>& seq, const std::string& name) {
    std::cout << name << ": [ ";
    for (const auto& v : seq) {
        std::cout << v << " ";
    }
    std::cout << "]\n";
}

int main() {
    // --- sample weighted directed graph ---
    Graph<std::string> graph;

    for (auto v : {"A","B","C","D","E","F","G"}) {
        graph.addVertex(std::string(v));
    }

    graph.makeUndirectedEdge("A", "B", 8);
    graph.makeUndirectedEdge("A", "C", 7);
    graph.makeUndirectedEdge("A", "D", 3);
    graph.makeUndirectedEdge("B", "E", 6);
    graph.makeUndirectedEdge("C", "D", 1);
    graph.makeUndirectedEdge("C", "E", 2);
    graph.makeUndirectedEdge("D", "F", 15);
    graph.makeUndirectedEdge("D", "G", 12);
    graph.makeUndirectedEdge("E", "F", 4);
    graph.makeUndirectedEdge("F", "G", 1);

    std::cout << "Vertices:";
    for (auto& v : graph.getAllVertices()) {
        std::cout << " " << v;
    }
    std::cout << "\n";

    std::cout << "Edges from A:\n";
    for (auto const& [nbr, w] : graph.getNeighbors("A")) {
        std::cout << "  A -> " << nbr << " (weight=" << w << ")\n";
    }

    // --- Run BFS from A ---
    auto bfsOrder = bfs(graph, std::string("A"));
    printTraversal(bfsOrder, "BFS");

    // --- Run DFS from A ---
    auto dfsRec = dfs(graph, std::string("A"));
    printTraversal(dfsRec, "DFS recursive");


    // --- Run Dijkstra from A -> G ---
    std::string start = "A";
    std::string end = "G";

    auto [distances, previous] = dijkstra(graph, start);

    // Print shortest distance
    std::cout << "Shortest distance from " << start << " to " << end << ": "
              << distances[end] << "\n";

    // Reconstruct and print path
    std::vector<std::string> path;
    for (std::string at = end; at != ""; at = previous[at]) {
        path.push_back(at);
    }
    std::reverse(path.begin(), path.end());

    std::cout << "Path: ";
    for (const auto& node : path) {
        std::cout << node << " ";
    }
    std::cout << "\n";


    return 0;
}
