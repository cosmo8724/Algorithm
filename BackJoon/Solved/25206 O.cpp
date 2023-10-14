/* 23. 08. 28 */
#include <bits/stdc++.h>

using namespace std;

double score, sum, mysum;
string name, grade;
map<string, double> table{
	{ "A+", 4.5 }, { "A0", 4.0 }, { "B+", 3.5 }, { "B0", 3.0 }, { "C+", 2.5 }, { "C0", 2.0 }, { "D+", 1.5 }, { "D0", 1.0 }, { "F", 0.0 }
};

int main()
{
	for (int i{ 0 }; i < 20; ++i) {
		cin >> name >> score >> grade;
		if (grade == "P") { continue; }

		sum += score;
		mysum += score * table[grade];
	}

	cout << mysum / sum;

	return 0;
}