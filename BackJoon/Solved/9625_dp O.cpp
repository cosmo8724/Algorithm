/* 23. 10. 20 */
/* BABBA */
#include <bits/stdc++.h>

using namespace std;

int K;
vector<int> dp;

int main()
{
	cin >> K;
	dp.resize(K + 1);

	dp[0] = 0;
	dp[1] = 1;
	for (int i{ 2 }; i <= K; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[K - 1] << ' ' << dp[K];

	return 0;
}