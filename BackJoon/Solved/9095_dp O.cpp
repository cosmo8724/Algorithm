/* 23. 11. 01 */
/* 1, 2, 3 더하기 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_N{ 11 };
int TC, N;
vector<int> dp(MAX_N);

int main()
{
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i{ 4 }; i < MAX_N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	cin >> TC;
	while (TC--) {
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}