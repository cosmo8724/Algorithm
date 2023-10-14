/* 23. 09. 25 */
#include <bits/stdc++.h>

using namespace std;

const string MAX_STR{ "111111111111111111111111111111111111111111111111111" };
int TC, N;
vector<int> need{ 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
vector<string> dp(101, MAX_STR);

string& Choose_Min(string& strA, string&& strB)
{
	if (strA.size() == strB.size()) { return strA < strB ? strA : strB; }
	else { return strA.size() < strB.size() ? strA : strB; }
}

void Min_Memoization()
{
	dp[0] = "";
	for (int i{ 0 }; i < 101; ++i) {
		for (int j{ 0 }; j < 10; ++j) {
			if (i - need[j] < 0) { continue; }
			if (j == 0 && dp[i - need[j]] == "") { continue; }
			dp[i] = Choose_Min(dp[i], dp[i - need[j]] + to_string(j));
		}
	}

	return;
}

string FindMax(int cnt)
{
	string ret{ "" };
	if (cnt & 1) {
		ret.push_back('7');
		cnt -= need[7];
	}

	while (cnt) {
		ret.push_back('1');
		cnt -= need[1];
	}

	return ret;
}

int main()
{
	Min_Memoization();

	cin >> TC;
	while (TC--) {
		cin >> N;
		cout << dp[N] << ' ' << FindMax(N) << '\n';
	}

	return 0;
}