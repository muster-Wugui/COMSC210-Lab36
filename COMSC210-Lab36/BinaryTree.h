//
//  BinaryTree.h
//  COMSC210-Lab36
//
//  Created by Xiao Zhang on 11/27/24.
//

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>
#include <iostream>

class BinaryTree {
private:
    struct TreeNode {
        std::string value; // The value in the node
        TreeNode *left;    // Pointer to the left child node
        TreeNode *right;   // Pointer to the right child node
    };
    
    // root points to the topmost node of the tree.
    TreeNode *root;
    
    //Private member functions for internal operations.
    void insert(TreeNode *&nodePtr, TreeNode *&newNode); // Insert node
    void destroySubTree(TreeNode *nodePtr);              // Destroy subtree
    void deleteNode(const std::string &value, TreeNode *&nodePtr); // Delete a node
    void makeDeletion(TreeNode *&nodePtr);               // Handle node deletion
    void displayInOrder(TreeNode *nodePtr) const;        // In-order traversal
    void displayPreOrder(TreeNode *nodePtr) const;       // Pre-order traversal
    void displayPostOrder(TreeNode *nodePtr) const;      // Post-order traversal
    
public:
    BinaryTree() { root = nullptr; } // Constructor
    ~BinaryTree() { destroySubTree(root); }// Destructor
    
    // Public interface for inserting, searching, and removing nodes.
    void insertNode(const std::string &value);
    bool searchNode(const std::string &value);
    void removeNode(const std::string &value);
    
    // Public wrappers for tree traversal functions.
    void displayInOrder() const     {  displayInOrder(root); }
    void displayPreOrder() const    {  displayPreOrder(root); }
    void displayPostOrder() const   {  displayPostOrder(root); }
};

#endif // BINARYTREE_H
