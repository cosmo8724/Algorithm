/* 23. 08. 29 */
#include <bits/stdc++.h>

using namespace std;

int X;

int main()
{
	cin >> X;

	int st = 1, i = 0, cnt = 1;
	while (true) {
		st += ++i;
		if (st > X) { break; }
		++cnt;
	}

	cout << X - st + i + 1 << '/' << cnt;

	return 0;
}