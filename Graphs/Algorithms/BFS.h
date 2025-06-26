#pragma once

#include "../Structures/graph.h"
#include <queue>
#include <unordered_set>
#include <vector>

namespace dsa {

    template<typename T>
    std::vector<T> bfs(const Graph<T>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::invalid_argument("Start vertex does not exist in the graph");

        std::vector<T> traversal;
        std::unordered_set<T> visited;
        std::queue<T> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            T current = q.front();
            q.pop();
            traversal.push_back(current);

            for (const T& neighbor : graph.getNeighbors(current)) {
                if (visited.count(neighbor) == 0) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return traversal;
    }

} // namespace dsa
