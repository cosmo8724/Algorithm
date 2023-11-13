/* 23. 11. 13 */
/* 돌 게임 4 */
#include <bits/stdc++.h>

using namespace std;

int N;
deque<bool> dp;

int main()
{
	cin >> N;
	if (N < 4) { dp.resize(4); }
	else { dp.resize(N + 1); }
	dp[1] = false;
	dp[2] = true;
	dp[3] = false;

	for (int i{ 4 }; i <= N; ++i) {
		dp[i] = (!dp[i - 1] || !dp[i - 3] || !dp[i - 4]) ? true : false;
	}

	if (dp[N]) { cout << "SK"; }
	else { cout << "CY"; }

	return 0;
}