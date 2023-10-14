/* 23. 09. 14 */
#include <bits/stdc++.h>

using namespace std;

int T, n;
vector<int> dp(10001);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	dp[0] = 1;
	for (int i{ 1 }; i <= 3; ++i) {
		for (int j{ i }; j <= 10000; ++j) {
			dp[j] += dp[j - i];
		}
	}

	cin >> T;
	while (T--) {
		cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}