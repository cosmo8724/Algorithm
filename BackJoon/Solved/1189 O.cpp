/* 23. 08. 14 */
#include <bits/stdc++.h>

using namespace std;

int R, C, K, ret;
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
vector<vector<char>> mp;
vector<vector<bool>> visited;

void dfs(int y, int x, int cost)
{
	if (y == 0 && x == C - 1) {
		if (cost == K) { ret++; }
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) { continue; }
		if (mp[ny][nx] == 'T') { continue; }

		visited[ny][nx] = true;
		dfs(ny, nx, cost + 1);
		visited[ny][nx] = false;
	}
}

int main()
{
	cin >> R >> C >> K;
	
	vector<vector<char>>(R, vector<char>(C, 0)).swap(mp);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mp[i][j];
		}
	}

	vector<vector<bool>>(R, vector<bool>(C, false)).swap(visited);
	visited[R - 1][0] = true;

	dfs(R - 1, 0, 1);

	cout << ret;

	return 0;
}