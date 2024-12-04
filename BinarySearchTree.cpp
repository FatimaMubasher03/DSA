#include <iostream>
using namespace std;

// Definition of a TreeNode
struct TreeNode {
    int value;             // Data stored in the node
    TreeNode* left;        // Pointer to the left child
    TreeNode* right;       // Pointer to the right child

    // Constructor to initialize a new node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) Class
class BinarySearchTree {
private:
    TreeNode* root;        // Root of the BST

    // Recursive function to insert a value
    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value); // Create a new node if current is null
        }

        if (value < node->value) {
            node->left = insertNode(node->left, value); // Insert in left subtree
        } else if (value > node->value) {
            node->right = insertNode(node->right, value); // Insert in right subtree
        }

        return node; // Return unchanged node pointer
    }

    // Recursive function for in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }

    // Recursive function for pre-order traversal
    void preOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        cout << node->value << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    // Recursive function for post-order traversal
    void postOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;

        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->value << " ";
    }

    // Recursive function to search for a value
    bool searchNode(TreeNode* node, int value) {
        if (node == nullptr) return false; // Base case: not found

        if (value == node->value) return true; // Base case: found

        if (value < node->value) {
            return searchNode(node->left, value); // Search in left subtree
        }

        return searchNode(node->right, value); // Search in right subtree
    }

    // Helper function to find the minimum value node in a subtree
    TreeNode* findMinNode(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left; // Minimum value is in the leftmost node
        }
        return node;
    }

    // Recursive function to delete a node
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) return node; // If node is null, return

        if (value < node->value) {
            node->left = deleteNode(node->left, value); // Delete in left subtree
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value); // Delete in right subtree
        } else {
            // Node found; handle deletion
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node; // Free memory
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node; // Free memory
                return temp;
            }

            // Node with two children: find the inorder successor
            TreeNode* temp = findMinNode(node->right);
            node->value = temp->value; // Replace with successor value
            node->right = deleteNode(node->right, temp->value); // Delete successor
        }

        return node; // Return updated node
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Insert a value into the BST
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Perform in-order traversal
    void inOrder() {
        cout << "In-order Traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

    // Perform pre-order traversal
    void preOrder() {
        cout << "Pre-order Traversal: ";
        preOrderTraversal(root);
        cout << endl;
    }

    // Perform post-order traversal
    void postOrder() {
        cout << "Post-order Traversal: ";
        postOrderTraversal(root);
        cout << endl;
    }

    // Search for a value
    bool search(int value) {
        return searchNode(root, value);
    }

    // Delete a value from the BST
    void remove(int value) {
        root = deleteNode(root, value);
    }
};

// Main function to test the BST
int main() {
    BinarySearchTree bst;

    // Insert values
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Perform traversals
    bst.inOrder();
    bst.preOrder();
    bst.postOrder();

    // Search for values
    cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;

    // Delete a value
    cout << "Deleting 30..." << endl;
    bst.remove(30);
    bst.inOrder();

    return 0;
}
