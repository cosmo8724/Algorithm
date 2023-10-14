/* 23. 09. 21 */
#include <bits/stdc++.h>

using namespace std;

const string YES{ "1\n" }, NO{ "0\n" };
int N, M, from, to;
vector<int> nums;
deque<deque<bool>> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	nums.resize(N + 1);
	deque<deque<bool>>(N + 1, deque<bool>(N + 1)).swap(dp);
	for (int i{ 1 }; i <= N; ++i) { cin >> nums[i]; }

	for (int i{ 1 }; i <= N; ++i) { dp[i][i] = true; }
	for (int i{ 1 }; i < N; ++i) {
		if (nums[i] == nums[i + 1]) {
			dp[i][i + 1] = true;
		}
	}
	for (int len{ 3 }; len <= N; ++len) {
		for (int i{ 1 }; i <= N - len + 1; ++i) {
			if (nums[i] == nums[i + len - 1] && dp[i + 1][i + len - 2]) {
				dp[i][i + len - 1] = true;
			}
		}
	}

	cin >> M;
	while (M--) {
		cin >> from >> to;
		if (dp[from][to]) { cout << YES; }
		else { cout << NO; }
	}

	return 0;
}