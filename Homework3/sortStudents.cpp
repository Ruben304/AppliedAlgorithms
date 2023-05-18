#include "sortStudents.h"
// your includes here
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;    

// alot of youtubes videos was used to solve this problem 
// others websites used were geeksforgeeks and 

std::vector<int> sortStudents(std::vector<int> days, std::vector<int> ids) {
    vector<int> output; // the end return
    unordered_map<int, vector<int>> birthdays; //this is to group the days given by the respective id 
    int i;

    // Group the days 
    for (int& day : days) { // iterrate through days vector to group the birthday by sotring them in a map
        birthdays[day].push_back(day); // this allows for mutliple calls of the same number and be returned easier
    } // all the days with the same number have the same key ^^^^^

    // Add the days in the order specified by ids
    for (int& id : ids) {
        vector<int>& bdays = birthdays[id]; // here it gets the vector of birthdays with a respective key that was implented for a group 
        for (i = 0; i < bdays.size(); i++) { // then pushes it to the vector being returned
            output.push_back(bdays[i]);
        }
        bdays.clear();
    }

    // Add the remaining days in their original order
    for (pair<const int, vector<int>>& it : birthdays) { //all the elements of an id have been pushed along with their corressponding group from the map earlier 
        vector<int>& bdays = it.second;                  
        for (i = 0; i < bdays.size(); i++) { // here is it getting the remaining ones that are not with an id or group to be in the same order
            output.push_back(bdays[i]);
        }
    }

    return output; // all of the days sorted by the resprective id index then the remaining days of original order 
}