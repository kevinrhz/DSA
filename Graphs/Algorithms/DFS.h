#pragma once

#include "../Structures/Graph.h"
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>

namespace dsa {
    /**
     * @brief Performs a recursive Depth-First Search (DFS) on a graph.
     *
     * DFS explores as far as possible along each branch before backtracking.
     * This implementation uses recursion.
     *
     * @tparam T The data type of the vertices.
     * @param graph The graph to traverse.
     * @param start The vertex to begin the search from.
     * @return A vector of vertices in one possible DFS traversal order.
     * @throws std::invalid_argument if the start vertex is not in the graph.
     */
    template<typename T>
    std::vector<T> dfs(const Graph<T>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::invalid_argument("Start vertex does not exist in the graph.");

        std::unordered_set<T> visited;
        std::vector<T> result;
        dfsHelper(graph, start, visited, result);
        return result;
    }

    /**
     * @brief A recursive helper function for the main DFS traversal.
     */
    template<typename T>
    void dfsHelper(const Graph<T>& graph, const T& curr, std::unordered_set<T>& visited, std::vector<T>& result) {
        visited.insert(curr);
        result.push_back(curr);

        for (auto const& [nbr, w] : graph.getNeighbors(curr)) {
            if (!visited.count(nbr)) {
                dfsHelper(graph, nbr, visited, result);
            }
        }
    }

    /**
     * @brief Performs an iterative Depth-First Search (DFS) on a graph.
     *
     * This version uses an explicit stack to avoid deep recursion issues on large graphs.
     * The order of visiting neighbors is reversed before pushing to the stack to ensure
     * a deterministic traversal order (matching a typical recursive implementation).
     *
     * @tparam T The data type of the vertices.
     * @param graph The graph to traverse.
     * @param start The vertex to begin the search from.
     * @return A vector of vertices in DFS traversal order.
     * @throws std::invalid_argument if the start vertex is not in the graph.
     */
    template<typename T>
    std::vector<T> dfsIterative(const Graph<T>& graph, const T& start) {
        if (!graph.hasVertex(start))
            throw std::invalid_argument("Start vertex does not exist in the graph.");

        std::unordered_set<T> visited;
        std::vector<T> result;
        std::stack<T> st;
        st.push(start);

        while (!st.empty()) {
            T curr = st.top(); st.pop();
            if (visited.count(curr)) continue;
            visited.insert(curr);
            result.push_back(curr);

            // extract neighbors into a vector, then reverse for deterministic order
            auto const& m = graph.getNeighbors(curr);
            std::vector<T> temp;
            temp.reserve(m.size());
            for (auto const& [nbr, w] : m) temp.push_back(nbr);
            std::reverse(temp.begin(), temp.end());

            for (auto const& nbr : temp) {
                if (!visited.count(nbr))
                    st.push(nbr);
            }
        }
        return result;
    }

} // namespace dsa