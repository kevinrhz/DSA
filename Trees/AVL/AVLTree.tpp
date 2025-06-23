#include "AVLTree.h"

namespace dsa {

    template<typename T>
    AVLTree<T>::AVLTree() : root_(nullptr) {}

    template<typename T>
    AVLTree<T>::~AVLTree() = default;

    template<typename T>
    void AVLTree<T>::insert(const T& value) {
        root_ = insertNode(std::move(root_), value);
    }

    template<typename T>
    void AVLTree<T>::remove(const T& value) {
        root_ = removeNode(std::move(root_), value);
    }

    template<typename T>
    bool AVLTree<T>::contains(const T& value) const {
        return containsNode(root_.get(), value);
    }

    template<typename T>
    int AVLTree<T>::height() const {
        return getHeight(root_.get());
    }

    // Recursive insert
    template<typename T>
    std::unique_ptr<typename AVLTree<T>::Node> AVLTree<T>::insertNode(std::unique_ptr<Node> node, const T& value) {
        if (!node) return std::make_unique<Node>(value);
        if (value < node->data)
            node->left = insertNode(std::move(node->left), value);
        else if (value > node->data)
            node->right = insertNode(std::move(node->right), value);
        else
            return node; // no duplicates

        updateHeight(node.get());
        return balanceNode(std::move(node));
    }

    // Recursive remove
    template<typename T>
    std::unique_ptr<typename AVLTree<T>::Node> AVLTree<T>::removeNode(std::unique_ptr<Node> node, const T& value) {
        if (!node) return nullptr;
        if (value < node->data)
            node->left = removeNode(std::move(node->left), value);
        else if (value > node->data)
            node->right = removeNode(std::move(node->right), value);
        else {
            // one or zero child
            if (!node->left) return std::move(node->right);
            if (!node->right) return std::move(node->left);
            // two children
            Node* minNode = findMin(node->right.get());
            node->data = minNode->data;
            node->right = removeNode(std::move(node->right), minNode->data);
        }
        updateHeight(node.get());
        return balanceNode(std::move(node));
    }

    // Recursive contains
    template<typename T>
    bool AVLTree<T>::containsNode(const Node* node, const T& value) const {
        if (!node) return false;
        if (value < node->data) return containsNode(node->left.get(), value);
        if (value > node->data) return containsNode(node->right.get(), value);
        return true;
    }

    // Utilities
    template<typename T>
    int AVLTree<T>::getHeight(const Node* node) const {
        return node ? node->height : 0;
    }

    template<typename T>
    int AVLTree<T>::getBalance(const Node* node) const {
        return node ? getHeight(node->left.get()) - getHeight(node->right.get()) : 0;
    }

    template<typename T>
    void AVLTree<T>::updateHeight(Node* node) {
        node->height = 1 + std::max(getHeight(node->left.get()), getHeight(node->right.get()));
    }

    template<typename T>
    typename AVLTree<T>::Node* AVLTree<T>::findMin(Node* node) const {
        while (node->left) node = node->left.get();
        return node;
    }

    // Rotations
    template<typename T>
    std::unique_ptr<typename AVLTree<T>::Node> AVLTree<T>::rotateRight(std::unique_ptr<Node> y) {
        auto x = std::move(y->left);
        y->left = std::move(x->right);
        x->right = std::move(y);
        updateHeight(x->right.get());
        updateHeight(x.get());
        return x;
    }

    template<typename T>
    std::unique_ptr<typename AVLTree<T>::Node> AVLTree<T>::rotateLeft(std::unique_ptr<Node> x) {
        auto y = std::move(x->right);
        x->right = std::move(y->left);
        y->left = std::move(x);
        updateHeight(y->left.get());
        updateHeight(y.get());
        return y;
    }

    // Balance node
    template<typename T>
    std::unique_ptr<typename AVLTree<T>::Node> AVLTree<T>::balanceNode(std::unique_ptr<Node> node) {
        int bf = getBalance(node.get());
        if (bf > 1) {
            if (getBalance(node->left.get()) < 0)
                node->left = rotateLeft(std::move(node->left));
            return rotateRight(std::move(node));
        }
        if (bf < -1) {
            if (getBalance(node->right.get()) > 0)
                node->right = rotateRight(std::move(node->right));
            return rotateLeft(std::move(node));
        }
        return node;
    }

} // namespace dsa
