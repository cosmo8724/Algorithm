/* 23. 11. 01 */
/* 돌 게임 3 */
#include <bits/stdc++.h>

using namespace std;

int N;
deque<bool> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;

	for (int i{ 4 }; i <= N; ++i) {
		dp[i] = !dp[i - 1] || !dp[i - 3] || !dp[i - 4] ? true : false;
	}

	if (dp[N]) { cout << "SK"; }
	else { cout << "CY"; }

	return 0;
}