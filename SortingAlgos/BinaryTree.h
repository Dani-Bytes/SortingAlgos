#pragma once
#include"Node.h"
// BinaryTree class with insert and inorder traversal
class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void inorderTraversal(vector<int>& sortedArr) {
        inorderRec(root, sortedArr);
    }

private:
    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insertRec(node->left, value);
        }
        else {
            node->right = insertRec(node->right, value);
        }
        return node;
    }

    void inorderRec(Node* node, vector<int>& sortedArr) {
        if (node == nullptr) return;
        inorderRec(node->left, sortedArr);
        sortedArr.push_back(node->data);
        inorderRec(node->right, sortedArr);
    }
};
