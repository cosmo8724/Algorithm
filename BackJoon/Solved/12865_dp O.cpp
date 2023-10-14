/* 23. 09. 18 */
#include <bits/stdc++.h>

using namespace std;

int N, K, W, V;
vector<int> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	dp.resize(K + 1);
	while (N--) {
		cin >> W >> V;

		for (int i{ K }; i >= W; --i) {
			dp[i] = max(dp[i - W] + V, dp[i]);
		}
	}

	cout << dp[K];

	return 0;
}