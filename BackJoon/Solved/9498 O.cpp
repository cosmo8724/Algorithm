/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	short	Score = 0;

	cin >> Score;

	if (90 <= Score && Score <= 100)
		cout << "A";
	else if (80 <= Score && Score < 90)
		cout << "B";
	else if (70 <= Score && Score < 80)
		cout << "C";
	else if (60 <= Score && Score < 70)
		cout << "D";
	else
		cout << "F";

	return 0;
}