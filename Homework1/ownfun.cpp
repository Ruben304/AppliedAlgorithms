#include <iostream>
#include <map>
#include <utility>

using namespace std;

//creating a map for for a pair of integers 
map<pair<int, int>, int> nums; //used a map because wenchao recommended

int fun(int x, int y) {
    //create int var to store the return
    int result;

    // i am using the first if statement to check if the a respective result of fun has been computed to avoid redundancies
    // i use the integer pair as a key for a respective calculation so it can just be recalled
    // this is done my checking if there is a calculation of a respective because anything more than 1 would be yes
    if (nums.count({x, y}) > 0) {
        return nums[{x, y}];
    }

    //follows the four cases given
    if ((x == 0) && (y == 0)) {
        result = 1;
    } else if ((x != 0) && (y == 0)) {
        result = x + 1;
    } else if ((x == 0) && (y != 0)) {
        result = fun(1, y - 1);
    } else {
        result = fun(x - 1, fun(x - 1, y - 1));
    }

    //we are storing the results of the map and using x,y as a key to be able to refrence for future uses
    nums[{x, y}] = result;

    return result;
}

int main() {
    //collects x and y that are prompted from the user
    int x, y;
    cout << "Enter an X and Y value: ";
    cin >> x >> y;
    cout << fun(x, y) << endl;
    return 0;
}
