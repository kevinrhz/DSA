#pragma once
#include "RedBlackTree.h"
#include <algorithm>
#include <cassert>

namespace dsa {

template<typename T>
RedBlackTree<T>::RedBlackTree()
  : size_(0)
{
    // create singleton NIL node
    nil_ = new Node(T(), Color::BLACK, nullptr);
    nil_->left   = nil_;
    nil_->right  = nil_;
    nil_->parent = nil_;
    // empty tree points at sentinel
    root_ = nil_;
}

template<typename T>
RedBlackTree<T>::~RedBlackTree() {
    clear();
    delete nil_;
}

template<typename T>
bool RedBlackTree<T>::isEmpty() const {
    return root_ == nil_;
}

template<typename T>
std::size_t RedBlackTree<T>::size() const {
    return size_;
}

template<typename T>
void RedBlackTree<T>::clear() {
    clearHelper(root_);
    root_ = nil_;
    size_ = 0;
}

template<typename T>
void RedBlackTree<T>::clearHelper(Node* x) {
    if (x == nil_) return;
    clearHelper(x->left);
    clearHelper(x->right);
    delete x;
}

template<typename T>
bool RedBlackTree<T>::contains(const T& value) const {
    return findNode(value) != nil_;
}

template<typename T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::findNode(const T& value) const {
    Node* curr = root_;
    while (curr != nil_) {
        if      (value < curr->data) curr = curr->left;
        else if (value > curr->data) curr = curr->right;
        else                          break;
    }
    return curr;
}

template<typename T>
int RedBlackTree<T>::height() const {
    return heightHelper(root_);
}

template<typename T>
int RedBlackTree<T>::heightHelper(Node* x) const {
    if (x == nil_) return 0;
    return 1 + std::max(heightHelper(x->left), heightHelper(x->right));
}

template<typename T>
bool RedBlackTree<T>::validate() const {
    if (root_ == nil_) return true;
    if (root_->color != Color::BLACK) return false;
    int expected = -1;
    return validateHelper(root_, 0, expected);
}

template<typename T>
bool RedBlackTree<T>::validateHelper(Node* x, int blackCount, int& expected) const {
    if (x == nil_) {
        if (expected < 0) expected = blackCount;
        return blackCount == expected;
    }
    if (x->color == Color::BLACK) blackCount++;
    // red node can't have red children
    if (x->color == Color::RED) {
        if (x->left->color  == Color::RED) return false;
        if (x->right->color == Color::RED) return false;
    }
    return validateHelper(x->left,  blackCount, expected)
        && validateHelper(x->right, blackCount, expected);
}

// —— BST splice helpers ——
template<typename T>
void RedBlackTree<T>::transplant(Node* u, Node* v) {
    if (u->parent == nil_) {
        root_ = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

template<typename T>
typename RedBlackTree<T>::Node* RedBlackTree<T>::treeMinimum(Node* x) const {
    while (x->left != nil_) x = x->left;
    return x;
}

// —— Rotations ——
template<typename T>
void RedBlackTree<T>::leftRotate(Node* x) {
    Node* y = x->right;
    assert(y != nil_);
    x->right = y->left;
    if (y->left != nil_) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nil_) {
        root_ = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

template<typename T>
void RedBlackTree<T>::rightRotate(Node* y) {
    Node* x = y->left;
    assert(x != nil_);
    y->left = x->right;
    if (x->right != nil_) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == nil_) {
        root_ = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

// —— Insertion + fixup ——
template<typename T>
void RedBlackTree<T>::insert(const T& value) {
    Node* z = new Node(value, Color::RED, nil_);
    // BST insert
    Node* y = nil_;
    Node* x = root_;
    while (x != nil_) {
        y = x;
        if (z->data < x->data) x = x->left;
        else if (z->data > x->data) x = x->right;
        else { // duplicate: discard
            delete z;
            return;
        }
    }
    z->parent = y;
    if (y == nil_)       root_ = z;
    else if (z->data < y->data) y->left  = z;
    else                         y->right = z;
    size_++;
    insertFixup(z);
}

template<typename T>
void RedBlackTree<T>::insertFixup(Node* z) {
    while (z->parent->color == Color::RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right; // uncle
            if (y->color == Color::RED) {
                z->parent->color = Color::BLACK;
                y->color         = Color::BLACK;
                z->parent->parent->color = Color::RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color         = Color::BLACK;
                z->parent->parent->color = Color::RED;
                rightRotate(z->parent->parent);
            }
        } else { // mirror case
            Node* y = z->parent->parent->left;
            if (y->color == Color::RED) {
                z->parent->color = Color::BLACK;
                y->color         = Color::BLACK;
                z->parent->parent->color = Color::RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color         = Color::BLACK;
                z->parent->parent->color = Color::RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root_->color = Color::BLACK;
}

// —— Removal + fixup ——
template<typename T>
void RedBlackTree<T>::remove(const T& value) {
    Node* z = findNode(value);
    if (z == nil_) return;
    Node* y = z;
    Color yOrigColor = y->color;
    Node* x = nullptr;

    if (z->left == nil_) {
        x = z->right;
        transplant(z, z->right);
    } else if (z->right == nil_) {
        x = z->left;
        transplant(z, z->left);
    } else {
        y = treeMinimum(z->right);
        yOrigColor = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    size_--;
    if (yOrigColor == Color::BLACK) {
        removeFixup(x);
    }
}

template<typename T>
void RedBlackTree<T>::removeFixup(Node* x) {
    while (x != root_ && x->color == Color::BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == Color::RED) {
                w->color            = Color::BLACK;
                x->parent->color    = Color::RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->right->color == Color::BLACK) {
                    w->left->color = Color::BLACK;
                    w->color       = Color::RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color         = x->parent->color;
                x->parent->color = Color::BLACK;
                w->right->color  = Color::BLACK;
                leftRotate(x->parent);
                x = root_;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == Color::RED) {
                w->color            = Color::BLACK;
                x->parent->color    = Color::RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->right->color == Color::BLACK && w->left->color == Color::BLACK) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->left->color == Color::BLACK) {
                    w->right->color = Color::BLACK;
                    w->color        = Color::RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color         = x->parent->color;
                x->parent->color = Color::BLACK;
                w->left->color   = Color::BLACK;
                rightRotate(x->parent);
                x = root_;
            }
        }
    }
    x->color = Color::BLACK;
}

} // namespace dsa
