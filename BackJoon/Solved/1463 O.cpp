/* 23. 09. 26 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N;
vector<int> dp;

int main()
{
	cin >> N;
	vector<int>(N + 1, INF).swap(dp);
	dp[N] = 0;

	for (int i{ N }; i >= 1; --i) {
		if (i % 3 == 0) { dp[i / 3] = min(dp[i / 3], dp[i] + 1); }
		if (i % 2 == 0) { dp[i / 2] = min(dp[i / 2], dp[i] + 1); }
		dp[i - 1] = min(dp[i - 1], dp[i] + 1);
	}

	cout << dp[1];

	return 0;
}