/* 23. 08. 11 */
#include <bits/stdc++.h>

using namespace std;

int R, C, ret = numeric_limits<int>::max();
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
vector<vector<char>> mp;
pair<int, int> pos;
queue<pair<int, int>> fire;
vector<vector<int>> fvisited;

void Fbfs()
{
	while (fire.size()) {
		auto [cy, cx] = fire.front();
		fire.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C || fvisited[ny][nx] != 1004 || mp[ny][nx] == '#') {
				continue;
			}

			fire.push(make_pair(ny, nx));
			fvisited[ny][nx] = fvisited[cy][cx] + 1;
		}
	}
}

bool Jbfs(int y, int x)
{
	if (pos.first == 0 || pos.second == 0 || pos.first == R - 1 || pos.second == C - 1) {
		ret = 1;
		return true;
	}

	queue<pair<int, int>> q;
	q.push(make_pair(pos.first, pos.second));

	vector<vector<int>> visited(R, vector<int>(C, 0));
	visited[pos.first][pos.second] = 1;

	while (q.size()) {
		auto [cy, cx] = q.front();
		q.pop();

		if (cy == 0 || cx == 0 || cy == R - 1 || cx == C - 1) {
			ret = visited[cy][cx];
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx]) {
				continue;
			}
			if (mp[ny][nx] == '#' || visited[cy][cx] + 1 >= fvisited[ny][nx]) {
				continue;
			}

			q.push(make_pair(ny, nx));
			visited[ny][nx] = visited[cy][cx] + 1;
		}
	}

	return false;
}

int main()
{
	cin >> R >> C;
	vector<vector<char>>(R, vector<char>(C, 0)).swap(mp);
	vector<vector<int>>(R, vector<int>(C, 1004)).swap(fvisited);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mp[i][j];

			if (mp[i][j] == 'J') {
				pos = make_pair(i, j);
			}
			else if (mp[i][j] == 'F') {
				fire.push(make_pair(i, j));
				fvisited[i][j] = 1;
			}
		}
	}

	Fbfs();
	if (Jbfs(pos.first, pos.second)) {
		cout << ret;
	}
	else {
		cout << "IMPOSSIBLE";
	}

	return 0;
}