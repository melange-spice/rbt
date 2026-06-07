#pragma once
#include <iostream>
using namespace std;

struct Node
{
    int data;
    char color; // r for red b for black
    Node* left;
    Node* right;
};

class rbt
{

    Node* root;

    //insertion helper functions
    //----------------------------------------
    int insert_like_bst(Node* n);
    Node* find_parent(Node* n);

    int determine_case(Node* n, Node* parent, Node* grand_parent, Node* uncle);
    int determine_case(Node* n);

    void three_node_case(Node* n);
    void four_node_case(Node* n);
    //----------------------------------------
    

    //deletion helper functions
    //----------------------------------------
    bool delete_like_bst(int value);
    Node* search(int value);
    Node* smallest(Node* starting_node);
    void checkdeletion(Node* t);
    //----------------------------------------

    //rotation functions
    //----------------------------------------
    void rotate_right(Node* n);
    void rotate_left(Node* n);
    void rotate_right(Node* n, Node* grand_parent, Node* parent);
    void rotate_left(Node* n, Node* grand_parent, Node* parent);
    //----------------------------------------

    //display helper functions
    //----------------------------------------
    void predisplay(Node* t);
    //----------------------------------------
public:
    rbt();
    ~rbt();

    //display preorder
    void preorder();

    

    void insert(int value);
    bool deletenode(int v);

    //bool delete_(int value);
    
};

