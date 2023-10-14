/* 23. 09. 26 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> stair, dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	stair.resize(N);
	dp.resize(N + 1);
	for (int i{ 0 }; i < N; ++i) { cin >> stair[i]; }
	dp[1] = stair[0];
	dp[2] = dp[1] + stair[1];
	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = max(dp[i - 2] + stair[i - 1], dp[i - 3] + stair[i - 2] + stair[i - 1]);
	}

	cout << dp[N];

	return 0;
}