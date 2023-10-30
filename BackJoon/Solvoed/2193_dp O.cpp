/* 23. 10. 30 */
/* 이친수 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<long long> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	dp[1] = dp[2] = 1;
	for (int i{ 3 }; i <= N; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[N];
	
	return 0;
}