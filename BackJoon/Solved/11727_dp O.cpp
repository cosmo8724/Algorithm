/* 23. 11. 03 */
/* 2xn 타일링 2 */
#include <bits/stdc++.h>

using namespace std;

const int MOD{ 10'007 };
int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[1] = 1;
	dp[2] = 3;	/* ll = ㅁ */
	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
		dp[i] %= MOD;
	}

	cout << dp[N];

	return 0;
}