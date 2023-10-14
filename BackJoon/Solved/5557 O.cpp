/* 23. 09. 21 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> nums;
vector<vector<long long>> dp;

long long dfs(int idx, int value)
{
	if (idx == N - 1) {
		if (value == nums[idx]) { return 1; }
		return 0;
	}
	if (value < 0 || value > 20) { return 0; }

	long long& ret{ dp[idx][value] };
	if (ret) { return ret; }
	ret += dfs(idx + 1, value + nums[idx]);
	ret += dfs(idx + 1, value - nums[idx]);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	nums.resize(N);
	vector<vector<long long>>(N, vector<long long>(21)).swap(dp);
	for (int i{ 0 }; i < N; ++i) { cin >> nums[i]; }

	cout << dfs(1, nums[0]);

	return 0;
}