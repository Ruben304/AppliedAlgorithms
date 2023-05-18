#include "BST.h"
#include <vector>
#include <algorithm>

void inorder(Node* root,vector<int>&V){
    if(root==NULL){ // if the node passed in NULL then just exit 
        return;
    }
    inorder(root->left,V); // push all the nodes in order to a vector
    V.push_back(root->key);
    inorder(root->right,V);
}

Node* firstNodeSearch(int x, Node* curr) {
    Node* next;
    if (curr == NULL) { // if node is NULL then exit 
        return NULL;
    }

    if (curr->key == x) { // if the node passed in equal to exactly x then x is the starting node
        return curr;
    }

    if (curr->key < x) { // if the node is less then x ...
        next = curr->right; //.. check its right traverse and if NULL then at max and return
        if (next == NULL) {
            return curr;
        }
        return firstNodeSearch(x, next); // if not at max set a new current node
    } else { // if the node is more than x ...
        next = curr->left; // .. check its left travers and if NULL then at min and return 
        if (next == NULL) {
            return curr;
        }
        return firstNodeSearch(x, next);
    }
}

/* this is the function that you need to implement */
int BST::nextKLargest(int x, int k) {
    int start_index; //starting index
    Node* start_node = firstNodeSearch(x, root); // find the first node after x or 1.first node (if x is smallest) 2. last node (if x the largest)
    int start_val = start_node->key; // starting value
    vector<int> key_values; // vector of the value in the BT
    inorder(root, key_values); // sorting the BT and creating a vector with it
    
    vector<int>::iterator start_iter = find(begin(key_values), end(key_values), start_val); // returns the first element that matches start_val
    if (start_iter != end(key_values)) { // if end() is returned then start_val was not found but other wise it will get the index that value
        start_index = distance(begin(key_values), start_iter); // from first iteration to the one we want
    }
    
    if (x == 0) { // since it is 0 then we you want the predecessor of the expected starting node 
        return key_values[k-1];
    }
    
    if (start_index + k > key_values.size() - 1) { //if there is less nodes than the Kth elements after than just return last
        return key_values.back();
    } else { // otherwise return the Kth largest after x
        return key_values[start_index + k];
    }
}