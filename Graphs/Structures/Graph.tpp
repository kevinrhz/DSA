namespace dsa {

    template<typename T>
    void Graph<T>::addVertex(const T& vertex) {
        adjacencyList_[vertex];
    }

    template<typename T>
    void Graph<T>::addEdge(const T& from, const T& to, int weight) {
        adjacencyList_[from][to] = weight;
        addVertex(to); // ensure 'to' node exists
    }

    template<typename T>
    void Graph<T>::makeUndirectedEdge(const T& v1, const T& v2, int weight) {
        addEdge(v1, v2, weight);
        addEdge(v2, v1, weight);
    }

    template<typename T>
    void Graph<T>::removeVertex(const T& vertex) {
        adjacencyList_.erase(vertex);
        for (auto& [v, edges] : adjacencyList_) {
            edges.erase(vertex);
        }
    }

    template<typename T>
    void Graph<T>::removeEdge(const T& from, const T& to) {
        auto it = adjacencyList_.find(from);
        if (it != adjacencyList_.end()) {
            it->second.erase(to);
        }
    }

    template<typename T>
    bool Graph<T>::hasVertex(const T& vertex) const {
        return adjacencyList_.count(vertex);
    }

    template<typename T>
    bool Graph<T>::hasEdge(const T& from, const T& to) const {
        auto it = adjacencyList_.find(from);
        return it != adjacencyList_.end() && it->second.count(to);
    }

    template<typename T>
    int Graph<T>::getWeight(const T& from, const T& to) const {
        auto it = adjacencyList_.find(from);
        if (it == adjacencyList_.end() || it->second.find(to) == it->second.end()) {
            throw std::invalid_argument("Edge not found");
        }
        return it->second.at(to);
    }

    template<typename T>
    const std::unordered_map<T, int>& Graph<T>::getNeighbors(const T& vertex) const {
        auto it = adjacencyList_.find(vertex);
        if (it == adjacencyList_.end()) {
            throw std::invalid_argument("Vertex not found");
        }
        return it->second;
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

    template<typename T>
    void Graph<T>::clear() {
        adjacencyList_.clear();
    }

} // namespace dsa