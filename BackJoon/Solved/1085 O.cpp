/* 23.04.24 */
#include <iostream>

using namespace std;

int main()
{
	short x, y, w, h;
	short Dist = 0;

	cin >> x >> y >> w >> h;

	if (w < 1 || w > 1000 || h < 1 || h > 1000)
		return 0;
	if (x < 1 || x >= w || y < 1 || y >= h)
		return 0;

	Dist = min<short>(x, y);
	Dist = min<short>(Dist, w - x);
	Dist = min<short>(Dist, h - y);

	cout << Dist;

	return 0;
}