#include <iostream>
using namespace std;

// Node structure
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// BinaryTree class
class BinaryTree {
private:
    TreeNode* root;

    // Helper function for adding nodes
    TreeNode* addNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = addNode(node->left, value);
        } else {
            node->right = addNode(node->right, value);
        }

        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    // Helper function for pre-order traversal
    void preOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Helper function for post-order traversal
    void postOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }

    // Helper function for finding a node
    bool search(TreeNode* node, int value) {
        if (node == nullptr) return false;

        if (node->value == value) return true;
        if (value < node->value) return search(node->left, value);
        return search(node->right, value);
    }

    // Helper function for deleting a node
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) return nullptr;

        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children
            TreeNode* temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }

        return node;
    }

    // Helper function to find the minimum value node
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    // Constructor
    BinaryTree() : root(nullptr) {}

    // Add node
    void add(int value) {
        root = addNode(root, value);
    }

    // In-order traversal
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    // Pre-order traversal
    void preOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    // Post-order traversal
    void postOrder() {
        postOrderTraversal(root);
        cout << endl;
    }

    // Search for a value
    bool search(int value) {
        return search(root, value);
    }

    // Delete a node
    void remove(int value) {
        root = deleteNode(root, value);
    }
};

// Main function
int main() {
    BinaryTree tree;

    // Adding nodes
    tree.add(50);
    tree.add(30);
    tree.add(70);
    tree.add(20);
    tree.add(40);
    tree.add(60);
    tree.add(80);

    cout << "In-order Traversal: ";
    tree.inOrder();

    cout << "Pre-order Traversal: ";
    tree.preOrder();

    cout << "Post-order Traversal: ";
    tree.postOrder();

    // Search for a value
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    // Delete a node
    cout << "Deleting 70..." << endl;
    tree.remove(70);
    cout << "In-order Traversal After Deletion: ";
    tree.inOrder();

    return 0;
}
