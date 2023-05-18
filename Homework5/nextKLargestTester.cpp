#include "BST.h"
#include <vector>
#include <iostream>
using namespace std;

// To compile: 
// g++ -std=c++17 nextKLargestTester.cpp BST.cpp nextKLargest.cpp -o Tester

int main(){

    int arr1[]= {5,4,3,1,7,6,9};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    vector<int> nums(arr1, arr1 + n1);
    BST b1(nums);

    string tree1 = b1.print();
    cout << "Tree 1: " << endl << tree1 << endl;

    int x=3; int k=4; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b1.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 7 << endl;

    x=6; k=4; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b1.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 9 << endl;

    x=2; k=4; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b1.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 6 << endl;

    x=0; k=2; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b1.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 3 << endl;

    int arr2[]= {11, 3, 17, 8, 9, 16, 31, 19, 2, 10};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> nums2(arr2, arr2 + n2);
    BST b2(nums2);

    string tree2 = b2.print();
    cout << endl << "Tree 2: " << endl << tree2 << endl;
    
    x=3; k=5; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b2.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 16 << endl;

    x=16; k=0; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b2.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 16 << endl;

    x=1; k=12; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b2.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 31 << endl;

    int arr3[]= {17, 23, 9, 6, 7, 21, 24, 4, 2, 33, 25, 26, 20, 19, 16, 15};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    vector<int> nums3(arr3, arr3 + n3);
    BST b3(nums3);

    string tree3 = b3.print();
    cout << endl << "Tree 3: " << endl << tree3 << endl;

    x=7; k=5; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b3.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 19 << endl;

    x=2; k=14; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b3.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 26 << endl;

    x=17; k=20; 
    cout << "x=" << x << ", k=" << k << ": ";
    cout << "Your result: " << b3.nextKLargest(x, k) << "  |  ";
    cout << "Expected answer: " << 33 << endl;

    return 0;
}