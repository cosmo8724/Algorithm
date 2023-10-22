/* 23. 10. 22 */
/* 타일 장식물 */
#include <bits/stdc++.h>

using namespace std;

int N;
long long ret;
vector<long long> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[1] = dp[2] = 1;

	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	ret = dp[N] * 2LL + (dp[N - 1] + dp[N]) * 2LL;
	cout << ret;

	return 0;
}