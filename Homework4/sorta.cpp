
#include <string>
#include <vector>

using namespace std;

// i got the steps to approach this problem from geekforgeeks but there is was still alot to be changed such as ...
//... impleneting it with string that had numbers and sorting it through a version of bubble sort

string sortByFreq(string s){
    int num = s.length(); // this will get the length of the input string given 
    string newS; // this will be where i store the new string 
    vector<pair<char, int>> vectorP; // a vector of pairs is created where the frequency of a respective character and the character itself
    char c; // character value 
    int freq[36] = {0}; // 36 for the possible characters

    // array to store the frequency of each character
    for (int i = 0; i < num; i++) { 
        if (isdigit(s[i])) { // do the check to see if that index of a string to a number
            freq[s[i] - '0' + 26]++; // getting the differece of the indexed char number and 0 lets us know what number is and adding 26 to bypass 26 letters
        }
        else { // getting the difference of the indexed char number and subtracting a tell its place in the alphabet which we can use to store in freq
            freq[s[i] - 'a']++; 
        }
    }
 


    // storing the frequency and the corresponding character
    for (int i = 0; i < 36; i++) { // for all the possible options...
        if (freq[i] > 0) { // ... go through each one and see if it even occurs 
            if (i < 26) { // if the index is less than 26 then it means the freq number corresponds to a character
                c = 'a' + i; // finding the respective character by getting that index from a
            }
            else {
                c = '0' + i - 26; // finding the respective number by adding to the starting zero and subtracting the 26 from before since we want the actual value and not index
            }
            vectorP.push_back(make_pair(c, freq[i])); // now i get that char (int/char) with the number of times it appears intially in a pair and add to to a vector
        }
    }
 


    // sorting the vector based on the frequency in ascending order and then the character in alphanumeric order
    for (int i = 0; i < vectorP.size() - 1; i++) {// index through the vector
        for (int j = i + 1; j < vectorP.size(); j++) { // index through vector, 1 ahead of i
            if ((vectorP[i].second == vectorP[j].second && vectorP[i].first > vectorP[j].first) || vectorP[i].second > vectorP[j].second) { // there is only 2 ways to entice a swap ...
            // ... the first is if the two values have the same frequency, and the onein front is high value like 3,b > 3,a will swap ...
            // ... the second is the frequency of the first is higher than the second so swap
                swap(vectorP[i], vectorP[j]);
            }
        }
    }
 


    // printing the sorted characters based on frequency
    for (int i = 0; i < vectorP.size(); i++) { 
        for (int j = 0; j < vectorP[i].second; j++) { // for every frequency we add the corresponding characters that are at the frequency before going to the next
            newS = newS + vectorP[i].first;
        }
    }

    return newS;
}

