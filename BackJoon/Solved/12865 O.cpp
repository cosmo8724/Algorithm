/* 23. 09. 02 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<pair<int, int>> v;
vector<vector<int>> dp;

int main()
{
	cin >> N >> K;
	v.resize(N + 1);
	vector<vector<int>>(N + 1, vector<int>(K + 1, 0)).swap(dp);

	for (int i{ 1 }; i <= N; ++i) { cin >> v[i].first >> v[i].second; }
	
	for (int i{ 1 }; i <= N; ++i) {
		for (int j{ 1 }; j <= K; ++j) {
			if (v[i].first <= j) { dp[i][j] = max(dp[i - 1][j], v[i].second + dp[i - 1][j - v[i].first]); }
			else { dp[i][j] = dp[i - 1][j]; }
		}
	}

	cout << dp[N][K];

	return 0;
}