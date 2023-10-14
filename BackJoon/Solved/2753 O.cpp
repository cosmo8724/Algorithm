/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	short	Year = 1;
	cin >> Year;

	short	Result = Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0);
	cout << Result;

	return 0;
}