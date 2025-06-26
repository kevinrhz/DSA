#pragma once

#include "../Structures/Graph.h"
#include <queue>
#include <unordered_set>
#include <vector>

namespace dsa {
    /**
     * @brief Performs a Breadth-First Search (BFS) on a graph.
     *
     * BFS explores the graph level by level from a given starting vertex.
     * It is guaranteed to find the shortest path in terms of number of edges
     * in an unweighted graph.
     *
     * @tparam T The data type of the vertices in the graph.
     * @param graph The graph to traverse.
     * @param start The starting vertex for the traversal.
     * @return A vector containing the vertices in the order they were visited.
     * @throws std::invalid_argument if the start vertex is not in the graph.
     */
    template<typename T>
    std::vector<T> bfs(const Graph<T>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::invalid_argument("Start vertex does not exist in the graph");

        std::vector<T> traversal;
        std::unordered_set<T> visited;
        std::queue<T> q;

        visited.insert(start);
        q.push(start);

        while (!q.empty()) {
            T curr = q.front(); q.pop();
            traversal.push_back(curr);

            // now getNeighbors returns map<neighbor,weight>
            for (auto const& [nbr, w] : graph.getNeighbors(curr)) {
                if (!visited.count(nbr)) {
                    visited.insert(nbr);
                    q.push(nbr);
                }
            }
        }

        return traversal;
    }

} // namespace dsa
