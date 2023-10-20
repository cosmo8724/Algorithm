/* 23. 10. 20 */
/* 다리 놓기 */
#include <bits/stdc++.h>

using namespace std;

int TC, N, M;
vector<vector<int>> dp(31, vector<int>(31));

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i{ 1 }; i <= 30; ++i) { dp[1][i] = i; }
	for (int i{ 2 }; i <= 30; ++i) {
		for (int j{ 1 }; j <= 30; ++j) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}
	
	cin >> TC;
	while (TC--) {
		cin >> N >> M;
		cout << dp[N][M] << '\n';
	}

	return 0;
}