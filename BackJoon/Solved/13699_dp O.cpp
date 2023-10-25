/* 23. 10. 25 */
/* 점화식 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> dp;

int main()
{
	cin >> N;

	dp.resize(N + 1);
	dp[0] = dp[1] = 1;
	dp[2] = 2;

	for (int i{ 3 }; i <= N; ++i) {
		for (int j{ 0 }; j < i; ++j) {
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}

	cout << dp[N];

	return 0;
}