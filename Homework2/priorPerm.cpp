#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// i used cplusplus (to learn about the assign function), youtube videos (to learn what permuation and lexicographical was)

// wanna identify the first number from the back of the array that is not in descending order, 
// then the largest element to the right swap less than that first number chosen and furthest left if multiple values
vector<int> priorPerm(vector<int> P){
  vector<int> lex;
    int n = P.size();
    int i = n - 2; 
    int j = n - 1;

    lex.assign(P.begin(), P.end()); // here we are copying the vector P to lex with the same content

    // i starts at n-2 because n-1 will cause i+1 to be out of the vector bounds
    while ((i >= 0) && (P[i] < P[i+1])) {// if i is in the bounds(non negative) and stops when i is the largest...
        i--;                                                 // ...this will find the largest i such that p[i] > p[i+1]
    }

    if (i < 0) { // this checks if the p is already in lexicographical order becuase if i is negative it would mean p[i] was always less than p[i + 1]...
        return lex; // ... and the condition that stopped it was i not being positive / went through all the numbers
    }

    // if i is found in a vector then we now try to find j as well 
    // we can set j to n-1 since there is no +1 counterpart and it used to find the largest number besides i, on the right of i 
    for (; j > i; j--) {
        if (P[j] < P[i]) {
            break;
        }
    }

    swap(lex[i], lex[j]); // once we found the index of i and j we want, we swap their content using the swap function

    int a;
    int b; // start at i- 1 to get everything of the right side of i and n-1 till the end of the vector 
    for (a = i+1, b = n-1; a < b; a++,b--) { // we essentially created two new indexes for the subvector we are reversing them with a and b ...
        swap(lex[a], lex[b]);                // ... since we are pinching the subvector each swap till the last iteration will swap leaving a reversed vector
    }

    return lex;
}
