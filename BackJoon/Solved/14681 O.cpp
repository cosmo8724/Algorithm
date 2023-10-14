/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	short	x, y, Space;
	cin >> x >> y;

	if (x > 0)
	{
		if (y > 0)
			Space = 1;
		else if (y < 0)
			Space = 4;
	}
	else if (x < 0)
	{
		if (y > 0)
			Space = 2;
		else if (y < 0)
			Space = 3;
	}

	cout << Space;

	return 0;
}