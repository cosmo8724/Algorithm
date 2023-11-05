/* 23. 11. 04 */
/* 피보나치는 지겨웡~ */
#include <bits/stdc++.h>

using namespace std;

const int MOD{ 1'000'000'007 };
int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[0] = dp[1] = 1;
	dp[2] = 3;

	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = 1 + dp[i - 1] + dp[i - 2];
		dp[i] %= MOD;
	}

	cout << dp[N];

	return 0;
}