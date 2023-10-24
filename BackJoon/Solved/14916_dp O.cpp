/* 23. 10. 24 */
/* 거스름돈 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int N;
array<int, 2> coins{ 5, 2 };
vector<int> dp;

int main()
{
	cin >> N;
	vector<int>(N + 1, INF).swap(dp);

	dp[N] = 0;
	for (int coin : coins) {
		for (int i{ N - coin }; i >= 0; --i) {
			dp[i] = min(dp[i], dp[i + coin] + 1);
		}
	}

	if (dp[0] == INF) { cout << -1; }
	else { cout << dp[0]; }

	return 0;
}