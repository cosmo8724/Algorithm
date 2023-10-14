/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };

int R, C, ret = 1;
vector<vector<char>> mp;
vector<vector<bool>> visited;
vector<bool> path(26, false);

void dfs(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) { continue; };
		if (path[mp[ny][nx] - 'A']) continue;

		path[mp[ny][nx] - 'A'] = true;
		visited[y][x] = true;

		cnt++;
		dfs(ny, nx);

		path[mp[ny][nx] - 'A'] = false;
		visited[y][x] = false;
	}

	if (cnt == 0) {
		int tmp = 0;

		for (int i = 0; i < 26; i++) {
			if (path[i]) { tmp++; }
		}

		ret = max(ret, tmp);
	}

	return;
}

int main()
{
	cin >> R >> C;
	vector<vector<char>>(R, vector<char>(C, 0)).swap(mp);
	vector<vector<bool>>(R, vector<bool>(C, 0)).swap(visited);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mp[i][j];
		}
	}

	visited[0][0] = true;
	path[mp[0][0] - 'A'] = true;

	dfs(0, 0);

	cout << ret;
}