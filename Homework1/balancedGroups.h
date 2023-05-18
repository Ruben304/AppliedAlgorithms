#ifndef __BALANCED_H__
#define __BALANCED_H__

#include <vector>
#include <iostream>

using namespace std;

struct Assignment {
	int diff;
	vector<int> ga; // Group A
	vector<int> gb; // Group B
	Assignment(int d, vector<int> va, vector<int> vb):
		diff(d), ga(va), gb(vb) {}
	void printAssignment() {
		cout << "Group A: ";
		for (int e: ga) {
			cout << e << " ";
		}
		cout << endl;
		cout << "Group B: ";
		for (int e: gb) {
			cout << e << " ";
		}
		cout << endl;
	}
};

Assignment balancedGroups(vector<int> const &birthdays);

#endif /* __BALANCED_H__*/