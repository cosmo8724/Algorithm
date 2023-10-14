/* 23. 08. 27 */
#include <bits/stdc++.h>

using namespace std;

int cnt;
string s;

int main()
{
	while (true) {
		cin >> s;
		if (cin.fail()) { break; }
		++cnt;
	}

	cout << cnt;

	return 0;
}