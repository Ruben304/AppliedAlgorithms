#include "node.h"
#include <cstdlib>

int calcWeight(node* root) {
    int leftWeight;
    int rightWeight;
    if (root == nullptr) { //if the node called is a null then there is no weight
        return 0;
    }

    leftWeight = calcWeight(root->left); // continue to call the function to find weight of left subtree
    rightWeight = calcWeight(root->right); // continue to call the functiont tp find weight of right subtree

    return 1 + leftWeight + rightWeight; // this is finding the total weight of the node 
}

bool isWeightBalanced(node* root, int k) {
    
    if (root == nullptr) { // tree is empty then true cuz balanced
        return true;
    }

    int leftW = calcWeight(root->left); // calculate the weight of the left sub tree
    int rightW = calcWeight(root->right); // calculate the weight of the right sub tree
    if (abs(leftW - rightW) > k) { // the difference of left subtree and right subtree more than k 
        return false;
    }

    if (k == 0 && leftW != rightW) { // in cases 1 and 3 both k are 0 but return 0 if they are unbalanced 
        return false;
    }
    bool leftB = isWeightBalanced(root->left, k); // check to see the left sub tree is balanced
    bool rightB = isWeightBalanced(root->right, k); // check to see the right sub tree is balanced

    return leftB && rightB; // both sides being true means the total tree is balanced
}


// your helper methods here