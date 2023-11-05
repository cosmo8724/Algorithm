/* 23. 11. 04 */
/* 달나라 토끼를 위한 구매대금 지불 도우미 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

int N;
vector<int> dp;
array<int, 4> values{ 1, 2, 5, 7 };

int main()
{
	cin >> N;
	vector<int>(N + 1, numeric_limits<int>::max()).swap(dp);
	dp[0] = 0;
	
	for (const int& coin : values) {
		for (int i{ coin }; i <= N; ++i) {
			dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}

	cout << dp[N];

	return 0;
}