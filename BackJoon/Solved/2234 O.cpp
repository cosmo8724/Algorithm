/* 23. 08. 21 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ 0, -1, 0, 1 };
int dx[]{ -1, 0, 1, 0 };
int N, M, roomcnt, roommax, roommix;
vector<vector<int>> mp;
vector<vector<int>> visited;
vector<int> rooms;

int bfs(int y, int x, int index)
{
	int ret = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	visited[y][x] = index;

	while (q.size()) {
		auto [cy, cx] = q.front();
		q.pop();
		++ret;

		for (int i = 0; i < 4; i++) {
			if (mp[cy][cx] & (1 << i)) { continue; }

			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] != -1) { continue; }

			q.push(make_pair(ny, nx));
			visited[ny][nx] = index;
		}
	}

	return ret;
}

int main()
{
	cin >> M >> N;
	vector<vector<int>>(N, vector<int>(M, 0)).swap(mp);
	vector<vector<int>>(N, vector<int>(M, -1)).swap(visited);
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cin >> mp[i][j];
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (visited[i][j] == -1) {
				int cnt = bfs(i, j, roomcnt++);
				roommax = max(roommax, cnt);
				rooms.push_back(cnt);
			}
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (i < N - 1 && visited[i][j] != visited[i + 1][j]) {
				roommix = max(roommix, rooms[visited[i][j]] + rooms[visited[i + 1][j]]);
			}
			if (j < M - 1 && visited[i][j] != visited[i][j + 1]) {
				roommix = max(roommix, rooms[visited[i][j]] + rooms[visited[i][j + 1]]);
			}
		}
	}

	cout << roomcnt << '\n' << roommax << '\n' << roommix;

	return 0;
}