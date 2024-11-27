//
//  BinaryTree.cpp
//  COMSC210-Lab36
//
//  Created by Xiao Zhang on 11/27/24.
//

#include "BinaryTree.h"
#include <iostream>
using namespace std;

// insert is a helper function to insert a new node into the tree.
// It takes a reference to the current tree node and the new node
// and places the new node in the correct position recursively.
void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
    if (nodePtr == nullptr) {
        nodePtr = newNode; // Insert at the root or leaf position.
    } else if (newNode->value < nodePtr->value) {
        insert(nodePtr->left, newNode); // Search the left branch.
    } else {
        insert(nodePtr->right, newNode); // Search the right branch.
    }
}

// insertNode creates a new node with the given value and
// inserts it into the binary tree using the insert helper.
void BinaryTree::insertNode(const std::string &value) {
    TreeNode *newNode = new TreeNode; // Create a new tree node.
    newNode->value = value;           // Assign the value to the node.
    newNode->left = nullptr;
    newNode->right = nullptr;

    insert(root, newNode); // Call helper to insert the node.
}

// destroySubTree deletes all nodes in the subtree rooted at nodePtr.
// It is called recursively to clean up left and right branches.
void BinaryTree::destroySubTree(TreeNode *nodePtr) {
    if (nodePtr != nullptr) {
        destroySubTree(nodePtr->left);  // Destroy the left subtree.
        destroySubTree(nodePtr->right); // Destroy the right subtree.
        delete nodePtr;                 // Delete the current node.
    }
}

// searchNode checks if the specified value exists in the binary tree.
// Returns true if the value is found, otherwise returns false.
bool BinaryTree::searchNode(const std::string &value) {
    TreeNode *nodePtr = root; // Start searching at the root.

    while (nodePtr != nullptr) {
        if (nodePtr->value == value) {
            return true; // Value found.
        } else if (value < nodePtr->value) {
            nodePtr = nodePtr->left; // Search the left branch.
        } else {
            nodePtr = nodePtr->right; // Search the right branch.
        }
    }
    return false; // Value not found.
}

// removeNode deletes a node with the given value from the binary tree.
void BinaryTree::removeNode(const std::string &value) {
    deleteNode(value, root);
}

// deleteNode removes a node containing the specified value.
// It is called recursively until the correct node is found.
void BinaryTree::deleteNode(const std::string &value, TreeNode *&nodePtr) {
    if (nodePtr == nullptr) {
        return; // Base case: node not found.
    }
    if (value < nodePtr->value) {
        deleteNode(value, nodePtr->left); // Search the left branch.
    } else if (value > nodePtr->value) {
        deleteNode(value, nodePtr->right); // Search the right branch.
    } else {
        makeDeletion(nodePtr); // Node found; handle deletion.
    }
}

// makeDeletion handles the deletion of a node in the tree.
// It correctly reattaches child branches to maintain tree structure.
void BinaryTree::makeDeletion(TreeNode *&nodePtr) {
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr) {
        cout << "Cannot delete an empty node.\n";
    } else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Promote the left child.
        delete tempNodePtr;
    } else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Promote the right child.
        delete tempNodePtr;
    } else {
        // Node has two children. Replace with the smallest node
        // in the right subtree to maintain order.
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left != nullptr) {
            tempNodePtr = tempNodePtr->left; // Find leftmost child.
        }
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

// displayInOrder traverses and prints the values in the tree
// in ascending order (left, root, right).
void BinaryTree::displayInOrder(TreeNode *nodePtr) const {
    if (nodePtr != nullptr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

// displayPreOrder traverses and prints the values in the tree
// in pre-order sequence (root, left, right).
void BinaryTree::displayPreOrder(TreeNode *nodePtr) const {
    if (nodePtr != nullptr) {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

// displayPostOrder traverses and prints the values in the tree
// in post-order sequence (left, right, root).
void BinaryTree::displayPostOrder(TreeNode *nodePtr) const {
    if (nodePtr != nullptr) {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}
