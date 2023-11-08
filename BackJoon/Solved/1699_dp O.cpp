/* 23. 11. 08 */
/* 제곱수의 합 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> dp;

int main()
{
	cin >> N;
	dp.resize(N + 1);
	iota(begin(dp), end(dp), 0);

	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[N];

	return 0;
}