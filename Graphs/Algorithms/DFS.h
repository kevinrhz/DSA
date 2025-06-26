#pragma once

#include "../Structures/graph.h"
#include <vector>
#include <unordered_set>
#include <stack>

namespace dsa {

    template<typename T>
    std::vector<T> dfs(const Graph<T>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::invalid_argument("Start vertex does not exist in the graph.");

        std::unordered_set<T> visited;
        std::vector<T> result;

        dfsHelper(graph, start, visited, result);
        return result;
    }

    template<typename T>
    void dfsHelper(const Graph<T>& graph, const T& current, std::unordered_set<T>& visited, std::vector<T>& result) {
        visited.insert(current);
        result.push_back(current);

        for (const T& neighbor : graph.getNeighbors(current)) {
            if (visited.find(neighbor) == visited.end()) {
                dfsHelper(graph, neighbor, visited, result);
            }
        }
    }


    template<typename T>
    std::vector<T> dfsIterative(const Graph<T>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::invalid_argument("Start vertex does not exist in the graph.");

        std::unordered_set<T> visited;
        std::vector<T> result;
        std::stack<T> s;

        s.push(start);

        while (!s.empty()) {
            T current = s.top();
            s.pop();

            if (visited.find(current) != visited.end())
                continue;

            visited.insert(current);
            result.push_back(current);

            const auto& neighbors = graph.getNeighbors(current);
            std::vector<T> reversed(neighbors.begin(), neighbors.end());
            std::sort(reversed.rbegin(), reversed.rend());  // sort for predictable order

            for (const T& neighbor : reversed) {
                if (visited.find(neighbor) == visited.end()) {
                    s.push(neighbor);
                }
            }
        }

        return result;
    }

} // namespace dsa