/* 23. 11. 03 */
/* 다이나믹이 뭐예요? */
#include <bits/stdc++.h>

using namespace std;

const int MOD{ 1'000'000'007 };
int N, M;
vector<vector<long long>> dp;

int main()
{
	cin >> N >> M;
	vector<vector<long long>>(N, vector<long long>(M)).swap(dp);
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
				continue;
			}

			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];
			dp[i][j] %= MOD;
		}
	}

	cout << dp[N - 1][M - 1];

	return 0;
}