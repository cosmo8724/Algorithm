/* 23. 09. 23 */
#include <bits/stdc++.h>
#include <array>

using namespace std;

int _next;
vector<int> commands;
vector<array<array<int, 5>, 5>> dp;

int Cost(int from, int to)
{
	if (from == 0) { return 2; }
	if (from == to) { return 1; }
	if (abs(from - to) == 2) { return 4; }
	return 3;
}

int dfs(int idx, int left, int right)
{
	if (idx == commands.size()) { return 0; }

	int& ret{ dp[idx][left][right] };
	if (~ret) { return ret; }

	int move_left{ dfs(idx + 1, commands[idx], right) + Cost(left, commands[idx]) };
	int move_right{ dfs(idx + 1, left, commands[idx]) + Cost(right, commands[idx]) };

	return ret = min(move_left, move_right);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (true) {
		cin >> _next;
		if (_next == 0) { break; }

		commands.push_back(_next);
	}
	dp.resize(commands.size());
	for (int i{ 0 }; i < dp.size(); ++i) {
		for (int j{ 0 }; j < 5; ++j) {
			for (int k{ 0 }; k < 5; ++k) {
				dp[i][j][k] = -1;
			}
		}
	}
	
	cout << dfs(0, 0, 0);

	return 0;
}