#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    void inOrderTraversal(Node* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

    void preOrderTraversal(Node* root) {
        if (root != nullptr) {
            std::cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }

    void postOrderTraversal(Node* root) {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            std::cout << root->data << " ";
        }
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inOrderTraversal() {
        std::cout << "In-order traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }

    void preOrderTraversal() {
        std::cout << "Pre-order traversal: ";
        preOrderTraversal(root);
        std::cout << std::endl;
    }

    void postOrderTraversal() {
        std::cout << "Post-order traversal: ";
        postOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST bst;

    // Insert elements into BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Perform traversals
    bst.inOrderTraversal();
    bst.preOrderTraversal();
    bst.postOrderTraversal();

    return 0;
}
