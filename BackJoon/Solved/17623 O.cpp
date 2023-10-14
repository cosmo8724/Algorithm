/* 23. 10. 06 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

int TC, N;
vector<string> dp(1001);	/* idx == val(), value == dmap() */

map<char, char> mp{
	{ '1', '(' },
	{ '2', ')' },
	{ '3', '{' },
	{ '4', '}' },
	{ '5', '[' },
	{ '6', ']' },
};

bool Check(string_view origin, string_view combined)
{
	if (origin.empty()) { return true; }
	if (origin.size() == combined.size()) { return origin > combined; }
	else { return origin.size() > combined.size(); }

	return false;
}

int main()
{
	dp[1] = "12";
	dp[2] = "34";
	dp[3] = "56";

	for (int val{ 1 }; val <= 1000; ++val) {
		if (val % 2 == 0 && Check(dp[val], "1" + dp[val / 2] + "2")) { dp[val] = "1" + dp[val / 2] + "2"; }
		if (val % 3 == 0 && Check(dp[val], "3" + dp[val / 3] + "4")) { dp[val] = "3" + dp[val / 3] + "4"; }
		if (val % 5 == 0 && Check(dp[val], "5" + dp[val / 5] + "6")) { dp[val] = "5" + dp[val / 5] + "6"; }

		for (int i{ 1 }; i <= val; ++i) {
			if (Check(dp[val], dp[i] + dp[val - i])) { dp[val] = dp[i] + dp[val - i]; }
		}
	}

	cin >> TC;
	while (TC--) {
		cin >> N;
		for (char sz : dp[N]) { cout << mp[sz]; }
		cout << '\n';
	}

	return 0;
}