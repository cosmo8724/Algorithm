/* 23. 09. 23 */
#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> walk_time, bike_time, walk_cost, bike_cost;
vector<vector<int>> dp;

int dfs(int idx, int current_time)
{
	if (idx == N) { return 0; }

	int& ret{ dp[idx][current_time] };
	if (ret) { return ret; }
	ret = numeric_limits<int>::min();

	if (current_time >= walk_time[idx]) { ret = max(ret, dfs(idx + 1, current_time - walk_time[idx]) + walk_cost[idx]); }
	if (current_time >= bike_time[idx]) { ret = max(ret, dfs(idx + 1, current_time - bike_time[idx]) + bike_cost[idx]); }

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> K;
	walk_time.resize(N);
	bike_time.resize(N);
	walk_cost.resize(N);
	bike_cost.resize(N);
	vector<vector<int>>(N, vector<int>(K + 1)).swap(dp);
	for (int i{ 0 }; i < N; ++i) {
		cin >> walk_time[i] >> walk_cost[i] >> bike_time[i] >> bike_cost[i];
	}

	cout << dfs(0, K);

	return 0;
}