#include "countOOO.h"
// your includes here
#include <map>
#include <string>


using namespace std;

int mergeCombine(vector<string> &rankedListB, map<string, int>& storage, int left, int middle, int right) {
    // Merge the two sorted subarrays and count OOO pairs

    vector<string> temp; // this is a vector that holds temporarly holds the merged vectors

		// setting the starting index for the vectors
    int leftsub = left;
    int rightsub = middle;
    int count = 0;

    while (leftsub < middle && rightsub <= right) { // this means the while loop will continue to run until there is no more elements in teh subvector
        if (storage[rankedListB[leftsub]] <= storage[rankedListB[rightsub]]) { // compares the the first element in each sub and pushes the smaller one to temp 
            temp.push_back(rankedListB[leftsub++]); // if the left is smaller the index of leftsub is incremented
        } else {
            temp.push_back(rankedListB[rightsub++]);// if the right is smaller than index of rightsub is incremented 
            count += (middle - leftsub); // the count of OOO pairs is incremented by the number of elements the number of leftsub is greater than the element in the rightsub
        } // this follows the if p appears before q in A but p appears after q in B
    }

    while (leftsub < middle) { // of the elements in the left subvector is pushed to temp
        temp.push_back(rankedListB[leftsub++]);
    }

    while (rightsub <= right) { // of the elements in the left subvector is pushed to temp
        temp.push_back(rankedListB[rightsub++]);
    }

    for (int i = left; i <= right; i++) { // the temp vector is copied back to Bob's list (i.e. the original[passed])
        rankedListB[i] = temp[i - left];
    }

    return count;
}

int mergeSort(vector<string>& rankedListB, map<string, int>& storage, int left, int right) {
    // Sort the vector and count OOO pairs

    if (left == right) { // if there is only one element is the array then they are equal and have zero OOO
        return 0;
    }

    int middle = (left + right) / 2; // following the idea of merge sort we get the middle index to start splitting
    int count = mergeSort(rankedListB, storage, left, middle) + mergeSort(rankedListB, storage, middle + 1, right); // recursively call mergesort until its single elements 
    count += mergeCombine(rankedListB, storage, left, middle + 1, right); // once all individually we run them through another helper function and store the return into count

    return count; // the end of the second function ultimately returns the the number of OOP in count
}

int countOOO(vector<string> rankedListA, vector<string> rankedListB) {

    map<string, int> storage; // using a map to store all the values in Alices list and store their respective index

    for (int i = 0; i < rankedListA.size(); i++) { // here is where we store the index
        storage[rankedListA[i]] = i;
    }

    return mergeSort(rankedListB, storage, 0, rankedListB.size() - 1); // calling a helper function to get final return of OOO count
}
