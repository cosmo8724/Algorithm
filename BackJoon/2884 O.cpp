/* 23.04.24 */
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	short	H, M;
	cin >> H >> M;

	M -= 45;
	if (M < 0)
	{
		if (H != 0)
			H--;
		else
			H = 23;
		M += 60;
	}

	cout << H << ' ' << M;

	return 0;
}