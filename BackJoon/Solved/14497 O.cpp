/* 23. 08. 12 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };

int N, M;
vector<vector<char>> mp;
pair<int, int> start{};
pair<int, int> target{};

int bfs()
{
	vector<vector<int>> visited(N, vector<int>(M, 0));
	visited[start.first][start.second] = 1;

	queue<pair<int, int>> q;
	q.push(start);

	int cnt = 0;
	while (mp[target.first][target.second] != '0') {
		cnt++;

		queue<pair<int, int>> level;
		while (q.size()) {
			auto [cy, cx] = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }
				if (visited[ny][nx]) { continue; }

				visited[ny][nx] = cnt;

				if (mp[ny][nx] == '0') { q.push(make_pair(ny, nx)); }
				else {
					mp[ny][nx] = '0';
					level.push(make_pair(ny, nx));
				}
			}
		}
		q.swap(level);
	}

	return cnt;
}

int main()
{
	cin >> N >> M;
	cin >> start.first >> start.second;
	cin >> target.first >> target.second;
	start.first--;
	start.second--;
	target.first--;
	target.second--;

	vector<vector<char>>(N, vector<char>(M, 0)).swap(mp);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
		}
	}
	
	cout << bfs();

	return 0;
}