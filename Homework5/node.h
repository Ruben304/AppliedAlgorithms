#ifndef _NODE
#include <cstddef>
#define _NODE

struct node {
    int data;
    node* left;
    node* right;
    node(int x) : data(x), left(NULL), right(NULL) {}
};

bool isWeightBalanced(node* node, int k);

#endif