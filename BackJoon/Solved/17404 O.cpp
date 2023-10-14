/* 23. 10. 02 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_COST{ static_cast<int>(1e9) };
int N, ret{ MAX_COST };
vector<int> cost[3], dp[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i{ 0 }; i < 3; ++i) {
		dp[i].resize(N + 1);
		cost[i].resize(N + 1);
	}
	for (int i{ 1 }; i <= N; ++i) { cin >> cost[0][i] >> cost[1][i] >> cost[2][i]; }

	for (int color{ 0 }; color < 3; ++color) {
		for (int i{ 0 }; i < 3; ++i) {
			if (i == color) { dp[i][1] = cost[i][1]; }
			else { dp[i][1] = MAX_COST; }
		}
		for (int i{ 2 }; i <= N; ++i) {
			dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + cost[0][i];
			dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + cost[1][i];
			dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + cost[2][i];
		}
		for (int i{ 0 }; i < 3; ++i) {
			if (i != color) { ret = min(ret, dp[i][N]); }
		}
	}

	cout << ret;

	return 0;
}