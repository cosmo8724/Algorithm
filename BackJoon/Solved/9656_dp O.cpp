/* 23. 10. 25 */
/* 돌 게임 2 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);

	dp[1] = 1;
	dp[2] = 2;
	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}

	if (dp[N] & 1) { cout << "CY"; }
	else { cout << "SK"; }

	return 0;
}