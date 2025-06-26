#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace dsa {

    template<typename T>
    class Graph {
    public:
        Graph() = default;
        ~Graph() = default;

        void addVertex(const T& vertex);
        void addEdge(const T& v1, const T& v2);
        void removeVertex(const T& vertex);
        void removeEdge(const T& v1, const T& v2);

        bool hasVertex(const T& vertex) const;
        bool hasEdge(const T& v1, const T& v2) const;

        const std::unordered_set<T>& getNeighbors(const T& vertex) const;
        std::vector<T> getAllVertices() const;
        bool isEmpty() const;
        int size() const;

    private:
        std::unordered_map<T, std::unordered_set<T>> adjacencyList_;
    };



    template<typename T>
    void Graph<T>::addVertex(const T& vertex) {
        adjacencyList_[vertex];
    }

    template<typename T>
    void Graph<T>::addEdge(const T& v1, const T& v2) {
        adjacencyList_[v1].insert(v2);
        adjacencyList_[v2].insert(v1); // undirected
    }

    template<typename T>
    void Graph<T>::removeVertex(const T& vertex) {
        for (auto& [key, neighbors] : adjacencyList_) {
            neighbors.erase(vertex);
        }
        adjacencyList_.erase(vertex);
    }

    template<typename T>
    void Graph<T>::removeEdge(const T& v1, const T& v2) {
        adjacencyList_[v1].erase(v2);
        adjacencyList_[v2].erase(v1);
    }

    template<typename T>
    bool Graph<T>::hasVertex(const T& vertex) const {
        return adjacencyList_.find(vertex) != adjacencyList_.end();
    }

    template<typename T>
    bool Graph<T>::hasEdge(const T& v1, const T& v2) const {
        auto it = adjacencyList_.find(v1);
        return it != adjacencyList_.end() && it->second.count(v2);
    }

    template<typename T>
    const std::unordered_set<T>& Graph<T>::getNeighbors(const T& vertex) const {
        return adjacencyList_.at(vertex);
    }

    template<typename T>
    std::vector<T> Graph<T>::getAllVertices() const {
        std::vector<T> vertices;
        for (const auto& [vertex, _] : adjacencyList_) {
            vertices.push_back(vertex);
        }
        return vertices;
    }

    template<typename T>
    bool Graph<T>::isEmpty() const {
        return adjacencyList_.empty();
    }

    template<typename T>
    int Graph<T>::size() const {
        return static_cast<int>(adjacencyList_.size());
    }

} // namespace dsa
