#include <string>
#include "trie.h"

using namespace std;

// I used geeksforgeeks.com and their page on trie to help in writing this and a few youtube videos

void Trie::insert(string key, int val) {
    TrieNode *current = root;// get the starting node 

    for (int i = 0; i < key.size(); i++) { // for the length of the word traverse
        int index = key[i] - 'a'; // this calculates the index of child node for the char to traverse
        if (!current->children[index]) { // if the character node does not exist, it makes one
            current->children[index] = new TrieNode();
            tree_size = tree_size + 1;
        }
        current = current->children[index]; // traverse to the next node for the next character
    }

    if (current->val == 0) { //if the word was just created then it wouldnt have a value so we check to see if its zero and if new then increase map
        map_size = map_size + 1;
    }
    current->val = val; // pass the given value to the end of the word
}

int Trie::search(string key) {
    TrieNode *current = root; // get the starting node 

    for (int i = 0; i < key.size(); i++) { // for the length of word traverse
        int index = key[i] - 'a'; // this calculates the index of child node for the char to traverse
        if (!current->children[index]) { // if the character node dosent exist then 0 for not found
            return 0;
        }
        current = current->children[index]; // if the node is reached then set it child to current 
    }

    return current->val; // return the value of the end of the word 
}

void Trie::remove(string key) {
    TrieNode *current = root; // get the starting node
    TrieNode *parent = NULL; // get the parent node 
    int index; // set the index

    for (int i = 0; i < key.size(); i++) { // for the size key(word)
        index = key[i] - 'a'; // this calculates the index of child node for the char to traverse
        if (!current->children[index]) { //checks if the current child index exist, if not exit
            return;
        }
        parent = current; // set the parent as current to be able to set the next node as current
        current = current->children[index]; // the new current is set to the child node with the needed index 
    }
    if (current->val != 0) { // once at the end of the word, if the value of the node isnt zero then it is still being counted so take off from count
        map_size = map_size - 1;
    }
    current->val = 0; // now set the ending node value to zero to mean its no longer a word

    if (current == root) { // before we start deleting, if the current node is the root then do exit since it cant be deleted 
        return;
    }

    if (!current->children[index]) { //  checks to see if last node doesnt have any children to remove it
        parent->children[index] = NULL; // sets the child that is the last letter of key of the parent to NULLi.e the very end
        delete current; // delete the node
        current = parent; // assigned it back to one before
        parent = NULL; 
        tree_size = tree_size - 1; // lower the tree size since were deleting a node 
    }
}
