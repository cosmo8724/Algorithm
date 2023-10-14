/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, M;
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
vector<pair<int, int>> outline;
vector<pair<int, int>> deletelist;
vector<vector<bool>> visited;

void CheckOutline(const vector<vector<int>>& mp, int y, int x)
{
	visited[y][x] = true;

	if (mp[y][x] == 1) {
		deletelist.push_back(make_pair(y, x));
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
			continue;
		}
		if (visited[ny][nx]) {
			continue;
		}

		CheckOutline(mp, ny, nx);
	}

	return;
}

bool CheckEmpty(const vector<vector<int>>& mp)
{
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (mp[y][x]) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	cin >> N >> M;
	vector<vector<int>> cheese(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
		}
	}

	int lastcnt = 0, ret = 0;
	do {
		vector<vector<bool>>(N, vector<bool>(M, false)).swap(visited);
		vector<pair<int, int>>().swap(deletelist);
		CheckOutline(cheese, 0, 0);

		for (auto& pair : deletelist) {
			cheese[pair.first][pair.second] = 0;
		}

		lastcnt = deletelist.size();
		ret++;
	} while (lastcnt && !CheckEmpty(cheese));

	cout << ret << '\n' << lastcnt;

	return 0;
}