/* 23. 11. 01 */
/* 피보나치 */
#include <bits/stdc++.h>

using namespace std;

int T, P;
long long Q;
vector<long long> dp;

void Make_DP(int N, long long mod)
{
	dp.resize(N + 1);
	dp[1] = dp[2] = 1;
	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= mod;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i{ 1 }; i <= T; ++i) {
		cin >> P >> Q;
		Make_DP(P, Q);
		cout << "Case #" << i << ": " << dp[P] % Q << '\n';
	}

	return 0;
}