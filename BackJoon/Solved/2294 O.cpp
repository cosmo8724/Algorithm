/* 23. 09. 17 */
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> values, dp;

int main()
{
	cin >> n >> k;
	values.resize(n);
	vector<int>(k + 1, static_cast<int>(1e9)).swap(dp);
	for (int i{ 0 }; i < n; ++i) { cin >> values[i]; }
	sort(begin(values), end(values));

	dp[0] = 0;
	for (int i{ 0 }; i <= k; ++i) {
		for (int value : values) {
			if (i + value > k) { continue; }
			dp[i + value] = min(dp[i + value], dp[i] + 1);
		}
	}

	if (dp[k] == static_cast<int>(1e9)) { cout << -1; }
	else { cout << dp[k]; }

	return 0;
}