/* 23. 09. 26 */
#include <bits/stdc++.h>

using namespace std;

int TC, N;
vector<long long> dp(101);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[1] = dp[2] = dp[3] = 1;
	dp[4] = dp[5] = 2;
	for (int i{ 6 }; i <= 100; ++i) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	cin >> TC;
	while (TC--) {
		cin >> N;
		cout << dp[N] << '\n';
	}

	return 0;
}