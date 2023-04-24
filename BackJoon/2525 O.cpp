#include <iostream>

using namespace std;

int main()
{
	short	H, M, m;
	cin >> H >> M >> m;

	H += m / 60;
	M += m % 60;

	if (H >= 24)
		H -= 24;

	if (M >= 60)
	{
		if (H != 23)
			H++;
		else
			H = 0;
		M -= 60;
	}

	cout << H << ' ' << M;

	return 0;
}