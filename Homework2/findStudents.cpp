#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>

using namespace std;

    // for refrences i used c plusplus to learn the limit.h library and the iteration tool from geeksforgeeks
vector<int> findStudents(vector<int> id){
    vector<int> mods;
    vector<int> students;
    map<int, int> storage;
    int mindiff = INT_MAX;
    int ind1 = 0;
    int ind2 = 0;
    int stu1;
    int stu2;
    int mod1;
    int mod2;

    if(id.size() == 2){  // if there is a vector with the 2 id then there is no need to check and return what is given
        return id;
    }

    
    for(int i = 0; i < id.size(); i++){ // get the given id of students and are now finding their mod when divided by 330
        int modo = id[i] % 330; // get the remainder and store them in a new vector
        mods.push_back(modo);
    }


    for(int i = 0; i < mods.size(); i++){  // now with all the remainders, we use the original id given utlizing it as ...
        int idval = id[i];              // ... a key to store the modded value into a map
        int modval = mods[i];
        storage[idval] = modval;
    }

    sort(mods.begin(),mods.end()); // this sorts the mods in ascending order


    for(int i = 0, j = id.size() - 1; i < j;){      // run the for loop and it will go till there is no more possible options which can be told when i is no longer less than j
        int runsum = mods[i] + mods[j];             // we store the respective indexed mods to the running sum to keep track of each comibinations moded total
        int runval = runsum - (runsum > 330 ? 330 : 0);     // if runsum is greater than we subtract 330 from the remainder else we just set runval to runsum to ensure no num over 330

        if(runval < mindiff){           // if the minimum difference is greater than the current set running value then we can disregard the current indexed points...
            mindiff = runval;           // ...but if its not then we found a new possible combination set it to the tne variables indexing for next part
            ind1 = i;
            ind2 = j;
        }
        if(mindiff == 0){               // if the minimum difference is 0 then we stop because that is best case scenario and done have to keep indexing
            break;  
        }

        (runsum <= 330) ? i++ : j--;    // depending on the value of the running sum we change the i (left) or j (right) so only one index is moving and contiue to pinch
    }

    if(mods[0] + mods[1] < mindiff){ // this is a check to the first two elements in mod are less the minimum difference (ie the best combitnation)
        for(map<int,int>::iterator it1 = storage.begin();it1 != storage.end();it1++){   //  the creation of an iterator allows us to throught the map created 
            if(it1->second == mods[0]){ // we are using the it1 variable to point to a respective "value" in the map and match its value with the modded one so we know which one we are correctly calling back
                stu1 = it1->first;      // once we call back the value we can get the key (the original id) and save it to stu 1 to get the first student of the combination
            }
            if(it1->second == mods[1]){ // we do the same this as we did in search of stu1 but for the second student
                stu2 = it1->first;
            }
        }
    }
    else{
        mod1 = mods[ind1];  // this is the same idea as above but instead of the first two being the combination we call the saved...
        mod2 = mods[ind2];  // indexes from before and search for them
        map<int, int>::iterator it2;
        for (map<int, int>::iterator it2 = storage.begin(); it2 != storage.end(); it2++)
        {
            if(it2->second == mod1){
                stu1 = it2->first;
            }
            if(it2->second == mod2){
                stu2 = it2->first;
            }
        }
    }

    students.push_back(stu1); // now that we have searched for the combination and saved... 
    students.push_back(stu2); // ...each respective student, we just pushback them to a vector

    return students;
}
