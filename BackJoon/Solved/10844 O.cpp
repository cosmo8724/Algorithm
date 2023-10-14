/* 23. 09. 26 */
#include <bits/stdc++.h>

using namespace std;

const int MOD{ 1'000'000'000 };
int N, ret;
vector<vector<int>> dp;

int main()
{
	cin >> N;
	vector<vector<int>>(N + 1, vector<int>(10)).swap(dp);
	for (int i{ 1 }; i < 10; ++i) { dp[1][i] = 1; }

	for (int i{ 2 }; i <= N; ++i) {
		for (int j{ 0 }; j < 10; ++j) {
			if (j == 0) { dp[i][j] = dp[i - 1][j + 1]; }
			else if (j == 9) { dp[i][j] = dp[i - 1][j - 1]; }
			else { dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]; }
			dp[i][j] %= MOD;
		}
	}

	for (int i{ 0 }; i < 10; ++i) { ret += dp[N][i] % MOD; }

	cout << ret % MOD;

	return 0;
}