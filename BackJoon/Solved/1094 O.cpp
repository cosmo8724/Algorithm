/* 23. 08. 21 */
#include <bits/stdc++.h>

using namespace std;

int X, ret;

int main()
{
	cin >> X;

	for (int i{ 0 }; i <= 6; ++i) {
		if ((1 << i) & X) { ++ret; }
	}

	cout << ret;

	return 0;
}