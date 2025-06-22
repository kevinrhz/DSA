#include "Trie.h"

namespace dsa {

    Trie::Trie() : root_(std::make_unique<Node>()) {}

    void Trie::insert(const std::string& word) {
        Node* curr = root_.get();
        for (char ch : word) {
            size_t idx = ch - 'a';
            if (idx >= 26) return;
            if (!curr->children[idx]) {
                curr->children[idx] = std::make_unique<Node>();
            }
            curr = curr->children[idx].get();
        }
        curr->isWord = true;
    }

    bool Trie::search(const std::string& word) const {
        const Node* curr = root_.get();
        for (char ch : word) {
            auto idx = ch - 'a';
            if (idx >= 26 || !curr->children[idx]) return false;
            curr = curr->children[idx].get();
        }
        return curr->isWord;
    }

    Trie::Node* Trie::findNode(const std::string& prefix) const {
        const Node* curr = root_.get();
        for (char ch : prefix) {
            auto idx = ch - 'a';
            if (idx >= 26 || !curr->children[idx]) return nullptr;
            curr = curr->children[idx].get();
        }
        return const_cast<Node*>(curr);
    }

    bool Trie::startsWith(const std::string& prefix) const {
        return findNode(prefix) != nullptr;
    }

    bool Trie::remove(const std::string& word) {
        if (!search(word)) return false;
        removeHelper(root_.get(), word, 0);
        return true;
    }

    bool Trie::removeHelper(Node* node, const std::string& word, int depth) {
        if (!node) return false;

        if (depth == word.size()) {
            if (!node->isWord) return false;
            node->isWord = false;
            return std::all_of(node->children.begin(), node->children.end(),
                               [](const std::unique_ptr<Node>& child) { return !child; });
        }

        char ch = word[depth];
        size_t idx = ch - 'a';
        if (!node->children[idx]) return false;

        bool shouldDeleteChild = removeHelper(node->children[idx].get(), word, depth + 1);

        if (shouldDeleteChild) {
            node->children[idx].reset();
            return !node->isWord && std::all_of(node->children.begin(), node->children.end(),
                                                [](const std::unique_ptr<Node>& child) { return !child; });
        }

        return false;
    }

} // namespace dsa