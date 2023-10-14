/* 23. 09. 17 */
#include <bits/stdc++.h>

using namespace std;

int n, k, value;
vector<int> dp;

int main()
{
	cin >> n >> k;
	dp.resize(k + 1);
	for (int i{ 0 }; i < n; ++i) {
		cin >> value;
		++dp[value];
		for (int j{ value }; j <= k; ++j) {
			dp[j] += dp[j - value];
		}
	}

	cout << dp[k];

	return 0;
}