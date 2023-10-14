/* 23. 09. 14 */
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> dp;

int main()
{
	cin >> n;
	dp.resize(n + 1);
	dp[1] = 1;
	for (int i{ 2 }; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n];

	return 0;
}