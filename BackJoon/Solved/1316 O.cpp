/* 23. 08. 28 */
#include <bits/stdc++.h>

using namespace std;

int N, ret;
string s;
bitset<26> alpha;

int main()
{
	cin >> N;
	while (N--) {
		cin >> s;
		alpha.reset();
		bool flag = true;
		for (int i{ 0 }; i < s.size() - 1; ++i) {
			alpha[s[i] - 'a'] = true;
			if (s[i] != s[i + 1] && alpha[s[i + 1] - 'a']) { flag = false; break; }
		}
		if (flag) { ++ret; }
	}

	cout << ret;

	return 0;
}