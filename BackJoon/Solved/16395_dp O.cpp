/* 23. 10. 24 */
/* 파스칼의 삼각형 */
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int>> dp;

int main()
{
	cin >> n >> k;
	dp.resize(n);
	for (int i{ 1 }; i <= n; ++i) {
		dp[i - 1].resize(i);
		dp[i - 1].front() = dp[i - 1].back() = 1;
	}

	for (int i{ 2 }; i < n; ++i) {
		for (int j{ 1 }; j < i; ++j) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	cout << dp[n - 1][k - 1];

	return 0;
}