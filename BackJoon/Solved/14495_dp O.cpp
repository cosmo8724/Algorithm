/* 23. 10. 25 */
/* 피보나치 비스무리한 수열 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> dp;

int main()
{
	cin >> N;
	if (N < 3) {
		cout << 1;
		return 0;
	}
	dp.resize(N + 1);
	dp[0] = dp[1] = dp[2] = dp[3] = 1;
	for (int i{ 4 }; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 3];
	}
	cout << dp[N];

	return 0;
}