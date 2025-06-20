namespace dsa {

    template<typename K, typename V>
    std::vector<std::pair<K, V>> BinarySearchTree<K, V>::inOrderTraversal() const {
        std::vector<std::pair<K, V>> result;
        inOrderHelper(root_, result);
        return result;
    }

    template<typename K, typename V>
    void BinarySearchTree<K, V>::inOrderHelper(const std::unique_ptr<Node>& node,
                                               std::vector<std::pair<K, V>>& result) const {
        if (!node) return;
        inOrderHelper(node->left, result);
        result.emplace_back(node->key, node->value);
        inOrderHelper(node->right, result);
    }

    template<typename K, typename V>
    bool BinarySearchTree<K, V>::insert(const K& key, const V& value) {
        return insertHelper(root_, key, value);
    }

    template<typename K, typename V>
    bool BinarySearchTree<K, V>::insertHelper(std::unique_ptr<Node>& node, const K& key, const V& value) {
        if (!node) {
            node = std::make_unique<Node>(key, value);
            ++size_;
            return true;
        }

        if (key < node->key) {
            return insertHelper(node->left, key, value);
        } else if (key > node->key) {
            return insertHelper(node->right, key, value);
        } else {
            return false; // duplicate key
        }
    }

    template<typename K, typename V>
    bool BinarySearchTree<K, V>::remove(const K& key) {
        return removeHelper(root_, key);
    }

    template<typename K, typename V>
    bool BinarySearchTree<K, V>::removeHelper(std::unique_ptr<Node>& node, const K& key) {
        if (!node) return false;

        if (key < node->key) {
            return removeHelper(node->left, key);
        } else if (key > node->key) {
            return removeHelper(node->right, key);
        } else {
            // Match found
            if (!node->left && !node->right) {
                node.reset();
            } else if (!node->left) {
                node = std::move(node->right);
            } else if (!node->right) {
                node = std::move(node->left);
            } else {
                // Two children: find in-order successor
                Node* successor = node->right.get();
                while (successor->left) { successor = successor->left.get(); }

                node->key   = successor->key;
                node->value = successor->value;
                removeHelper(node->right, successor->key); // Remove successor node
            }
            return true;
        }
    }

    template<typename K, typename V>
    V* BinarySearchTree<K, V>::find(const K& key) {
        return findHelper(root_, key);
    }

    template<typename K, typename V>
    const V* BinarySearchTree<K, V>::find(const K& key) const {
        return findHelper(root_, key);
    }

    template<typename K, typename V>
    V* BinarySearchTree<K, V>::findHelper(const std::unique_ptr<Node>& node, const K& key) {
        if (!node)           return nullptr;
        if (key < node->key) return findHelper(node->left, key);
        if (key > node->key) return findHelper(node->right, key);
        return const_cast<V*>(&node->value);
    }

    template<typename K, typename V>
    const V* BinarySearchTree<K, V>::findHelper(const std::unique_ptr<Node>& node, const K& key) const {
        if (!node)           return nullptr;
        if (key < node->key) return findHelper(node->left, key);
        if (key > node->key) return findHelper(node->right, key);
        return &node->value;
    }

    template<typename K, typename V>
    V* BinarySearchTree<K, V>::findMin() {
        Node* curr = root_.get();
        if (!curr) return nullptr;

        while (curr->left) { curr = curr->left.get(); }
        return &curr->value;
    }

    template<typename K, typename V>
    const V* BinarySearchTree<K, V>::findMin() const {
        const Node* curr = root_.get();
        if (!curr) return nullptr;

        while (curr->left) { curr = curr->left.get(); }
        return &curr->value;
    }

    template<typename K, typename V>
    V* BinarySearchTree<K, V>::findMax() {
        Node* curr = root_.get();
        if (!curr) return nullptr;

        while (curr->right) { curr = curr->right.get(); }
        return &curr->value;
    }

    template<typename K, typename V>
    const V* BinarySearchTree<K, V>::findMax() const {
        const Node* curr = root_.get();
        if (!curr) return nullptr;

        while (curr->right) { curr = curr->right.get(); }
        return &curr->value;
    }

    template<typename K, typename V>
    int BinarySearchTree<K, V>::height() const {
        return heightHelper(root_);
    }

    template<typename K, typename V>
    int BinarySearchTree<K, V>::heightHelper(const std::unique_ptr<Node>& node) const {
        if (!node) return -1;
        int leftHeight = heightHelper(node->left);
        int rightHeight = heightHelper(node->right);
        return 1 + std::max(leftHeight, rightHeight);
    }

    template<typename K, typename V>
    void BinarySearchTree<K, V>::clear() {
        root_.reset();
        size_ = 0;
    }



} // namespace dsa