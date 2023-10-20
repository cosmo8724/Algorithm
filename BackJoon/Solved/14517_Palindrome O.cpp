/* 23. 10. 19 */
#include <bits/stdc++.h>

using namespace std;

const int MOD{ 10'007 };
string S;
string::size_type lenS;
vector<vector<int>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S;
	lenS = S.size();

	/* DP[i][j] : idx_i부터 idx_j까지 펠린드롬의 개수. */
	vector<vector<int>>(lenS, vector<int>(lenS)).swap(dp);
	for (int i{ 0 }; i < lenS; ++i) { dp[i][i] = 1; }
	for (int i{ 0 }; i < lenS - 1; ++i) {
		/* [ab] 한 글자 한 글자씩 펠린드롬을 이루어 2. */
		if (S[i] != S[i + 1]) { dp[i][i + 1] = 2; }
		/* [aa] 한 글자씩과 두 글자 합하여 3. */
		else { dp[i][i + 1] = 3; }
	}
	for (int diff{ 2 }; diff < lenS; ++diff) {
		for (int from{ 0 }, to; from < lenS - diff; ++from) {
			to = from + diff;
			dp[from][to] += dp[from + 1][to];
			dp[from][to] += dp[from][to - 1];
			dp[from][to] -= dp[from + 1][to - 1];

			while (dp[from][to] < 0) { dp[from][to] += MOD; }
			dp[from][to] %= MOD;

			if (S[from] == S[to]) {
				dp[from][to] += dp[from + 1][to - 1] + 1;
				dp[from][to] %= MOD;
			}
		}
	}
	cout << dp[0][lenS - 1];

	return 0;
}