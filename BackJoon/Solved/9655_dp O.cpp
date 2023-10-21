/* 23. 10. 21 */
/* 돌 게임 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	if (dp[N] & 1) { cout << "SK"; }
	else { cout << "CY"; }

	return 0;
}