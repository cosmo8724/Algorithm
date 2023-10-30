/* 23. 10. 30 */
/* 피보나치 수의 확장 */
#include <bits/stdc++.h>

using namespace std;

const int MAX_N{ 1'000'000 };
const int MOD{ 1'000'000'000 };
int N;
vector<long long> dp(2 * MAX_N + 2, 0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	N += MAX_N;
	dp[MAX_N] = 0;
	dp[MAX_N + 1] = 1;

	if (N == MAX_N) {
		cout << 0 << '\n' << 0;
		return 0;
	}
	else if (N > MAX_N) {
		for (int i{ MAX_N + 2 }; i <= N; ++i) {
			dp[i] = dp[i - 1] % MOD + dp[i - 2] % MOD;
			dp[i] %= MOD;
		}
	}
	else {
		for (int i{ MAX_N - 1 }; i >= N; --i) {
			dp[i] = dp[i + 2] % MOD - dp[i + 1] % MOD;
			dp[i] %= MOD;
		}
	}

	if (dp[N] > 0) { cout << 1 << '\n' << dp[N]; }
	else { cout << -1 << '\n' << abs(dp[N]); }

	return 0;
}