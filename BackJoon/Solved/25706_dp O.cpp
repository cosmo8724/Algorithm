/* 23. 10. 29 */
/* 자전거 묘기 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> roads, dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	roads.resize(N);
	dp.resize(N);
	for (int i{ 0 }; i < N; ++i) { cin >> roads[i]; }

	dp.back() = 1;
	for (int i{ N - 2 }; i >= 0; --i) {
		if (roads[i]) {
			int landspot{ roads[i] + 1 + i };
			if (landspot >= N) { dp[i] = 1; }
			else { dp[i] = dp[landspot] + 1; }
		}
		else { dp[i] = dp[i + 1] + 1; }
	}

	for (int i : dp) {
		cout << i << ' ';
	}

	return 0;
}