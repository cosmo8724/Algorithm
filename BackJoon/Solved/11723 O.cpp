/* 23. 08. 21 */
#include <bits/stdc++.h>

using namespace std;

int M, num;
string str;
bitset<21> S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M;
	while (M--) {
		cin >> str;
		if (str == "all") { S.set(); }
		else if (str == "empty") { S.reset(); }
		else {
			cin >> num;
			if (str == "add") { S[num] = true; }
			else if (str == "remove") { S[num] = false; }
			else if (str == "check") { cout << S[num] << '\n'; }
			else if (str == "toggle") { S[num] = !S[num]; }
		}
	}

	return 0;
}