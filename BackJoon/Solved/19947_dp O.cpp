/* 23. 10. 24 */
/* 투자의 귀재 배주형 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

int H, Y;
array<double, 3> funds{ 1.05, 1.20, 1.35 };
vector<int> dp;

int main()
{
	cin >> H >> Y;
	vector<int>(Y + 1, H).swap(dp);

	/*for (int i{ 0 }, year; i < 3; ++i) {
		year = i * 2 + 1;
		for (int j{ year }; j <= Y; ++j) {
			dp[j] = max(dp[j], static_cast<int>(dp[j - year] * funds[i]));
		}
	}*/

	for (int j{ 1 }; j <= Y; ++j) {
		dp[j] = max(dp[j], static_cast<int>(dp[j - 1] * funds[0]));
		if (j >= 3) { dp[j] = max(dp[j], static_cast<int>(dp[j - 3] * funds[1])); }
		if (j >= 5) { dp[j] = max(dp[j], static_cast<int>(dp[j - 5] * funds[2])); }
	}

	cout << dp[Y];

	return 0;
}