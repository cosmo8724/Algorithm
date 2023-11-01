/* 23. 11. 01 */
/* 악수 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[1] = 1;
	dp[2] = 2;

	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10;
	}

	cout << dp[N];

	return 0;
}