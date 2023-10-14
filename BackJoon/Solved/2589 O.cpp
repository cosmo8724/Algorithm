/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, M, maxdist;
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
vector<vector<char>> mp;

void bfs(int y, int x)
{
	vector<vector<int>> visited(N, vector<int>(M, 0));
	queue<pair<int, int>> q;

	visited[y][x] = 1;
	q.push(make_pair(y, x));

	while (q.size()) {
		auto [cy, cx] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] || mp[ny][nx] == 'W') {
				continue;
			}

			visited[ny][nx] = visited[cy][cx] + 1;
			q.push(make_pair(ny, nx));

			maxdist = max(maxdist, visited[ny][nx]);
		}
	}
}

int main()
{
	cin >> N >> M;
	vector<vector<char>>(N, vector<char>(M, 0)).swap(mp);

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < M; j++) {
			mp[i][j] = s[j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}

	cout << maxdist - 1;

	return 0;
}