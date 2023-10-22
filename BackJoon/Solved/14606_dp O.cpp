/* 23. 10. 22 */
/* 피자 (small) */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[1] = 0;
	dp[2] = 1;
	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = (i / 2 * (i - i / 2)) + dp[i / 2] + dp[i - i / 2];
	}
	cout << dp[N];

	return 0;
}