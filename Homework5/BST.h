//
//  BST.h
//

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* A Binary Search Tree node */
struct Node
{
    int key;    // the key stored by this node
    Node *left;   // the left child of this node
    Node *right;  // the right child of this node
};

/**
 * Implements a Binary Search Tree keyed by Integers
 */
class BST{
public:
    /* constructs an empty Binary Search Tree */
    BST();
    
    /* constructs a one-node Binary Search Tree with the given key */
    BST(int num);
    
    /* constructs a Binary Search Tree by repeatedly inserting ints in <nums>
     in the order they appear in the vector */
    BST(vector<int>& nums);
    
    /* insert num as a new key to the BST */
    void insert(int num);
    
    /* return the BST rooted at this node as a human-readable string */
    string print();

    /* return the next kth largest key after x. 
     return the largest key in the tree if k is larger than the number of keys larger than x.
     note that x needs not be a key in the tree. */
    int nextKLargest(int x, int k);
    
private:
    /* insert num as a new key to the BST at node 'leaf' */
    void insert(int num, Node *leaf);    
    
    /* return the BST rooted at leaf as a human-readable string,
     indented by <depth> characters */
    string print(Node *leaf, int depth);
    
    /* return a string of <depth> spaces */
    string RepeatChar(int depth);
    
public:
    Node *root;
};


#endif /* BST_h */
