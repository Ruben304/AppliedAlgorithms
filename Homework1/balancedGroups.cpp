#include "balancedGroups.h"
// your includes here

using namespace std;


Assignment balancedGroups(vector<int> const &birthdays){
	int runsuma = 0;
	int runsumb = 0;
	int temp;
	int diff;
	vector<int> ga; // Group A
	vector<int> gb; // Group B
	vector<int> sortedbirthdays;

	for (int i = 0; i < birthdays.size(); i++){ //this creates a copy of the vector we recieve since we cant change the original becuase its const
		sortedbirthdays.push_back(birthdays[i]);
	}
	
	for (int i = 0; i < sortedbirthdays.size(); i++) { //puts all the birthdays in descending order in the new vector
        for (int j = i + 1; j < sortedbirthdays.size(); j++) {
            if (sortedbirthdays[i] < sortedbirthdays[j]) {
                temp = sortedbirthdays[i];
                sortedbirthdays[i] = sortedbirthdays[j];
                sortedbirthdays[j] = temp;
            }
        }
    }

	for (int i = 0; i < sortedbirthdays.size(); i++){ 
		if (runsuma < runsumb){
			runsuma += sortedbirthdays[i];
			ga.push_back(sortedbirthdays[i]);
		} else if (runsuma > runsumb){
			runsumb += sortedbirthdays[i];
			gb.push_back(sortedbirthdays[i]);
		} else {
			runsuma += sortedbirthdays[i];
			ga.push_back(sortedbirthdays[i]);
		}
	}

	if (runsuma >= runsumb){
		diff = runsuma - runsumb;
	} else {
		diff = runsumb - runsuma;
	}

	return Assignment(diff, ga, gb); // Don't forget to change this
}

/* your helper function here if you have any */