// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include<string>
#include <vector>
#include <iomanip>
#include <iostream>
using namespace std;

int LevenshteinDistanceCalculate(const string& st1, const string& st2) {

	if (st1.size() > st2.size()) {
		return LevenshteinDistanceCalculate(st2, st1);
	}

	const int min_size = st1.size();
	const int max_size = st2.size();
	vector<int> levdis(min_size + 1);

	for (int i = 0; i <= min_size; i++) {
		levdis[i] = i;
	}

	for (int j = 1; j < max_size; j++) {
		int previous_diagonal = levdis[0];
		int previous_diagonal_save;
		++levdis[0];

		for (int i = 1; i <= min_size; i++) {
			previous_diagonal_save = levdis[i];
			if (st1[i - 1] == st2[j - 1]) {
				levdis[i] = previous_diagonal;
			}
			else {
				levdis[i] = min(min(levdis[i - 1], levdis[i]), previous_diagonal) + 1;
			}
			previous_diagonal = previous_diagonal_save;
		}
	}
	return levdis[min_size];
}


int main() {

	string one = "taha here ion based on translation memory.";
	string two = "ion based on translation memory.";

	cout << (float)(LevenshteinDistanceCalculate(one, two)) << endl ;
	cout << std::fixed << std::setprecision(3) << (1 - (float)(LevenshteinDistanceCalculate(one, two) - 1) / (float)(max(one.size(), two.size()))) * 100 << endl;
}

