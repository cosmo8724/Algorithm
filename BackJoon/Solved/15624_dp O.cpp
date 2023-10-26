/* 23. 10. 26 */
/* 피보니차 수 7 */
#include <bits/stdc++.h>

using namespace std;

const int MOD{ 1'000'000'007 };
int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[1] = 1;

	for (int i{ 2 }; i <= N; ++i) {
		dp[i] = dp[i - 1] % MOD + dp[i - 2] % MOD;
		dp[i] %= MOD;
	}

	cout << dp[N];
	
	return 0;
}