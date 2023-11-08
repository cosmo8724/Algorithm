/* 23. 11. 07 */
/* 문제 출제 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int ret, cur;
vector<int> cost(5);
int dp[16], ai[16];

int Go(int cur, int score)
{
	if (score > 15) {
		if (cur < 4) { return INF * -1; }
		else { return 0; }
	}

	int& _ret{ dp[cur] };
	if (_ret) { return _ret; }

	for (int i{ 4 }; i >= 0; --i) {
		_ret = max(_ret, Go(cur + 1, score + i + 1) + cost[i]);
	}

	return _ret;
}

int main()
{
	for (int i{ 0 }; i < 5; ++i) { cin >> cost[i]; }

	for (int i{ 1 }; i <= 3; ++i) {
		for (int j{ 0 }; j < 5; ++j) {
			dp[i] = dp[i - 1];
			int score{ ai[i - 1] + j + 1 };
			if (score > 10) {
				ai[i] = ai[i - 1];
				continue;
			}
			if (dp[i] < dp[i - 1] + cost[j]) {
				dp[i] = dp[i - 1] + cost[j];
				ai[i] = score;
			}
		}
	}
	ret = *max_element(begin(dp), end(dp));
	//memset(dp, 0, sizeof(dp));
	//memset(ai, 0, sizeof(ai));

	for (int i{ 4 }; i <= 15; ++i) {
		for (int j{ 0 }; j < 5; ++j) {
			dp[i] = dp[i - 1];
			int score{ ai[i - 1] + j + 1 };
			if (score > 15) {
				ai[i] = ai[i - 1];
				continue;
			}
			if (dp[i] < dp[i - 1] + cost[j]) {
				dp[i] = dp[i - 1] + cost[j];
				ai[i] = score;
			}
		}
	}

	ret = max(ret, *max_element(begin(dp) + 4, end(dp)));

	//ret = max(ret, Go(0, 0));
	cout << ret;

	return 0;
}