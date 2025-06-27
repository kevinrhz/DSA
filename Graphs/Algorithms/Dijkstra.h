/**
 * @file Dijkstra.h
 * @brief Provides an implementation of Dijkstra's shortest path algorithm.
 */

#pragma once
#include "../Structures/Graph.h"
#include <unordered_map>
#include <queue>
#include <limits>gi

namespace dsa {

    /**
     * @brief Computes the shortest paths from a starting vertex to all other vertices using Dijkstra's algorithm.
     *
     * @tparam T The type of the vertex (e.g., int, std::string).
     * @param graph A weighted graph with positive edge weights.
     * @param start The starting vertex for shortest path calculation.
     * @return A pair of maps:
     *         - distances: mapping from each vertex to its minimum distance from the start.
     *         - previous: mapping from each vertex to its predecessor in the shortest path.
     */
    template<typename T>
    std::pair<std::unordered_map<T, int>, std::unordered_map<T, T>>
    dijkstra(const Graph<T>& graph, const T& start) {
        using pii = std::pair<int, T>;   // (distance, vertex)
        std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;

        std::unordered_map<T, int> dist; // (vertex, distance)
        std::unordered_map<T, T> prev;   // (vertex, previous vertex)

        for (const T& vertex : graph.getAllVertices()) {
            dist[vertex] = std::numeric_limits<int>::max();
        }

        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            auto [currDist, currV] = pq.top();
            pq.pop();

            if (currDist > dist[currV]) continue;

            for (const auto& [neighbor, weight] : graph.getNeighbors(currV)) {
                int newDist = dist[currV] + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    prev[neighbor] = currV;
                    pq.emplace(newDist, neighbor);
                }
            }
        }

        return {dist, prev};
    }

} // namespace dsa