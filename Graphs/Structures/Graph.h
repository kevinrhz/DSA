#pragma once

#include <unordered_map>
#include <vector>
#include <stdexcept>

namespace dsa {
    /**
     * @brief A generic, weighted, directed graph implementation using an adjacency list.
     *
     * This class represents a graph where each vertex can be of any hashable type.
     * Edges are directed and can have an associated integer weight. The structure
     * is implemented using a map of vertices to their neighbors, where each neighbor
     * mapping includes the weight of the connecting edge.
     *
     * @tparam T The data type for the vertices. Must be hashable to be used as a key
     * in std::unordered_map.
     */
    template<typename T>
    class Graph {
    public:
        /// @brief Constructs an empty graph.
        Graph() = default;
        /// @brief Default destructor.
        ~Graph() = default;

        /**
         * @brief Adds a vertex to the graph. If it already exists, this has no effect. O(1) average.
         * @param vertex The vertex to add.
         */
        void addVertex(const T& vertex);

        /**
         * @brief Adds a directed edge from one vertex to another. O(1) average.
         * If the 'from' or 'to' vertices do not exist, they are created.
         * If the edge already exists, its weight is updated.
         * @param from The source vertex.
         * @param to The destination vertex.
         * @param weight The weight of the edge (default is 1).
         */
        void addEdge(const T& from, const T& to, int weight = 1);

        /**
         * @brief Adds an undirected edge by creating two directed edges. O(1) average.
         * @param v1 The first vertex.
         * @param v2 The second vertex.
         * @param weight The weight for both directed edges.
         */
        void makeUndirectedEdge(const T& v1, const T& v2, int weight = 1);

        /**
         * @brief Removes a vertex and all incident edges. O(V + E).
         * @param vertex The vertex to remove.
         */
        void removeVertex(const T& vertex);

        /**
         * @brief Removes a directed edge. O(1) average.
         * @param from The source vertex.
         * @param to The destination vertex.
         */
        void removeEdge(const T& from, const T& to);

        /// @brief Checks if a vertex exists in the graph. O(1) average.
        bool hasVertex(const T& vertex) const;

        /// @brief Checks for a directed edge between two vertices. O(1) average.
        bool hasEdge(const T& from, const T& to) const;

        /**
         * @brief Gets the weight of a directed edge. O(1) average.
         * @throws std::invalid_argument if the edge does not exist.
         */
        int getWeight(const T& from, const T& to) const;

        /**
         * @brief Gets all neighbors of a given vertex.
         * @param vertex The vertex whose neighbors to retrieve.
         * @return A const reference to the map of neighbors and their edge weights.
         * @throws std::invalid_argument if the vertex does not exist.
         */
        const std::unordered_map<T, int>& getNeighbors(const T& vertex) const;

        /// @brief Returns a list of all vertices in the graph. O(V).
        std::vector<T> getAllVertices() const;

        /// @brief Checks if the graph is empty. O(1).
        bool isEmpty() const;

        /// @brief Returns the number of vertices in the graph. O(1).
        int size() const;

        /// @brief Removes all vertices and edges from the graph. O(V+E).
        void clear();

    private:
        // Adjacency list representation: vertex -> {neighbor -> weight}
        std::unordered_map<T, std::unordered_map<T, int>> adjacencyList_;
    };

} // namespace dsa

#include "Graph.tpp"