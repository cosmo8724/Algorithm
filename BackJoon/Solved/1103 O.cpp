/* 23. 09. 16 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int N, M;
vector<vector<int>> board, dp;
deque<deque<bool>> visited;

int dfs(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M || board[y][x] == -1) { return 0; }
	if (visited[y][x]) {
		cout << -1;
		exit(0);
	}
	int& ret{ dp[y][x] };
	if (~ret) { return ret; }

	visited[y][x] = true;
	ret = 0;

	for (int i{ 0 }; i < 4; ++i) {
		int ny{ y + dy[i] * board[y][x] };
		int nx{ x + dx[i] * board[y][x] };
		ret = max(ret, dfs(ny, nx) + 1);
	}

	visited[y][x] = false;

	return ret;
}

int main()
{
	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(M)).swap(board);
	vector<vector<int>>(N, vector<int>(M, -1)).swap(dp);
	deque<deque<bool>>(N, deque<bool>(M)).swap(visited);
	for (int i{ 0 }; i < N; ++i) {
		string s;
		cin >> s;
		for (int j{ 0 }; j < M; ++j) {
			if (s[j] == 'H') { board[i][j] = -1; }
			else { board[i][j] = s[j] - '0'; }
		}
	}

	cout << dfs(0, 0);

	return 0;
}