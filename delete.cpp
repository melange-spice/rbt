#pragma once
#include "rbt.h"

bool rbt::delete_like_bst(int value)
{
    if (root == nullptr)
        return false;

    Node *current = search(value);
    // value not in the tree
    if (current == nullptr)
        return false;

    // at this point we should have found the value
    Node *parent = find_parent(current);

    // Leaf node case that is no childern of current
    if (current->left == nullptr && current->right == nullptr)
    {
        // determine if the current is parent's left or right child
        if (parent->right == current)
            parent->right = nullptr;
        else if (parent->left == current)
            parent->left = nullptr;

        // explicit check for a tree with a single node
        if (current == root)
        {
            parent = nullptr;
            root = nullptr;
        }

        delete current;
        current = nullptr;
    }
    // 1 child case: left
    else if (current->left != nullptr && current->right == nullptr)
    {
        // determine if the current is parent's left or right child
        if (parent->right == current)
            parent->right = current->left;
        else if (parent->left == current)
            parent->left = current->left;

        // explicit check for the root case with only the left subtree
        if (current == root)
        {
            parent = nullptr;
            root = current->left;
        }

        delete current;
        current = nullptr;
    }
    // 1 child case: right
    else if (current->left == nullptr && current->right != nullptr)
    {
        // determine if the current is parent's left or right child
        if (parent->right == current)
            parent->right = current->right;
        else if (parent->left == current)
            parent->left = current->right;

        // explicit check for the root case with only the right subtree
        if (current == root)
        {
            parent = nullptr;
            root = current->right;
        }

        delete current;
        current = nullptr;
    }
    // 2 child case
    else if (current->left != nullptr && current->right != nullptr)
    {
        // find the smallest of the right subtree
        Node* smallest_right = smallest(current->right);
        Node* parent_sr = find_parent(smallest_right);

        // change the to_delete value
        current->data = smallest_right->data;

        //delete the smallest of the right subtree
        // determine if the smallest_right is it's parent's left or right child
        if (parent_sr->right == smallest_right)
            parent_sr->right = smallest_right->right; //the left most node can have a right child
        else if (parent_sr->left == smallest_right) 
            parent_sr->left = smallest_right->right; //the left most node can have a right child

        delete smallest_right;
        smallest_right = nullptr;
    }
    return true;
}

// given the value return the node where the value is located in the tree
Node *rbt::search(int value)
{
    Node *current = root;

    // if we haven't found the value then search for the value in the tree
    while (current->data != value)
    {
        // go to left subtree
        if (value < current->data)
        {
            current = current->left; // advance the child
        }
        else if (value > current->data)
        {
            // go to right subtree
            current = current->right; // advance the child
        }

        // value is not in the current tree
        if (current == nullptr)
            return current;
    }
    return current;
}

// returns the smallest node given the starting node of the tree
Node *rbt::smallest(Node *starting_node)
{
    // go to the left most value
    while (starting_node->left != nullptr)
    {
        starting_node = starting_node->left;
    }

    return starting_node;
}