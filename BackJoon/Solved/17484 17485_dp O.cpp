/* 23. 11. 04 */
/* 진우의 달 여행 (Small & Large) */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int dx[] { -1, 0, 1 };
int N, M, ret{ numeric_limits<int>::max() };
vector<vector<int>> board, dp[3];

int Go(int row, int col, int dir)
{
	if (row == N) { return 0; }

	int& _ret{ row == 0 ? dp[0][row][col] : dp[dir][row][col] };
	if (~_ret) { return _ret; }
	_ret = INF;

	if (dir == -1) {
		for (int i{ 0 }; i < 3; ++i) {
			int nx{ col + dx[i] };
			if (nx < 0 || nx >= M) { continue; }
			_ret = min(_ret, Go(row + 1, nx, i));
		}
	}
	else {
		for (int i{ 1 }; i <= 2; ++i) {
			int nextDir{ (dir + i) % 3 };
			int nx{ col + dx[nextDir] };
			if (nx < 0 || nx >= M) { continue; }
			_ret = min(Go(row + 1, nx, nextDir), _ret);
		}
	}

	_ret += board[row][col];

	return _ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(M)).swap(board);
	for (int i{ 0 }; i < 3; ++i) { vector<vector<int>>(N, vector<int>(M, -1)).swap(dp[i]); }

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cin >> board[i][j];
		}
	}

	for (int i{ 0 }; i < M; ++i) {
		ret = min(ret, Go(0, i, -1));
	}

	cout << ret;

	return 0;
}