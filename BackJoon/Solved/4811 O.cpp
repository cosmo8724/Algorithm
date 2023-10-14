/* 23. 09. 17 */
#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<long long>> dp;

long long dfs(int whole, int half)
{
	if (!whole && !half) { return 1; }

	long long& ret{ dp[whole][half] };
	if (ret) { return ret; }
	if (whole) { ret += dfs(whole - 1, half + 1); }
	if (half) { ret += dfs(whole, half - 1); }

	return ret;
}

int main()
{
	while (true) {
		cin >> N;
		if (N == 0) { break; }

		vector<vector<long long>>(N + 1, vector<long long>(N + 1)).swap(dp);

		cout << dfs(N, 0) << '\n';
	}

	return 0;
}