/* 23. 11. 13 */
/* 이동하기 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ 0, 1 };
int dx[]{ 1, 0 };
int N, M;
vector<vector<int>> board, dp;

int Go(int y, int x)
{
	if (y == N || x == M) { return 0; }

	int& ret{ dp[y][x] };
	if (~ret) { return ret; }
	ret = 0;

	for (int dir{ 0 }, ny, nx; dir < 2; ++dir) {
		ny = y + dy[dir];
		nx = x + dx[dir];
		if (ny >= N || nx >= M) { continue; }

		ret = max(ret, Go(ny, nx));
	}

	ret += board[y][x];

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(M)).swap(board);
	vector<vector<int>>(N, vector<int>(M, -1)).swap(dp);
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cin >> board[i][j];
		}
	}

	cout << Go(0, 0);

	return 0;
}