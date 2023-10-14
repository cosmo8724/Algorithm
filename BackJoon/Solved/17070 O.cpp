/* 23. 09. 15 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ 0, 1, 1 };
int dx[]{ 1, 1, 0 };
int N;
vector<vector<int>> mp, dp[3];

bool Check(int y, int x, int dir) {
	if (y >= N || x >= N) { return false; }
	if (dir == 0 || dir == 2) { return !mp[y][x]; }
	else { return !mp[y][x] && !mp[y - 1][x] && !mp[y][x - 1]; }
}

int main()
{
	cin >> N;
	vector<vector<int>>(N, vector<int>(N)).swap(mp);
	for (int i{ 0 }; i < 3; ++i) { vector<vector<int>>(N, vector<int>(N)).swap(dp[i]); }

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < N; ++j) {
			cin >> mp[i][j];
		}
	}

	dp[0][0][1] = 1;
	for (int y{ 0 }; y < N; ++y) {
		for (int x{ 0 }; x < N; ++x) {
			if (Check(y + dy[0], x + dx[0], 0)) { dp[0][y + dy[0]][x + dx[0]] += dp[0][y][x]; }
			if (Check(y + dy[1], x + dx[1], 1)) { dp[1][y + dy[1]][x + dx[1]] += dp[0][y][x]; }

			if (Check(y + dy[0], x + dx[0], 0)) { dp[0][y + dy[0]][x + dx[0]] += dp[1][y][x]; }
			if (Check(y + dy[1], x + dx[1], 1)) { dp[1][y + dy[1]][x + dx[1]] += dp[1][y][x]; }
			if (Check(y + dy[2], x + dx[2], 2)) { dp[2][y + dy[2]][x + dx[2]] += dp[1][y][x]; }

			if (Check(y + dy[1], x + dx[1], 1)) { dp[1][y + dy[1]][x + dx[1]] += dp[2][y][x]; }
			if (Check(y + dy[2], x + dx[2], 2)) { dp[2][y + dy[2]][x + dx[2]] += dp[2][y][x]; }
		}
	}

	cout << dp[0][N - 1][N - 1] + dp[1][N - 1][N - 1] + dp[2][N - 1][N - 1];

	return 0;
}