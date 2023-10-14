/* 23. 10. 05 */
#include <bits/stdc++.h>

using namespace std;

int TC, ret;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> TC;
	while (TC--) {
		cin >> s;
		ret = 0;
		for (int i{ 0 }, sum{ 1 }; i < s.size(); ++i) {
			if (s[i] == 'O') { ret += sum++; }
			else { sum = 1; }
		}
		cout << ret << '\n';
	}

	return 0;
}