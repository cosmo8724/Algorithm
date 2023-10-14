/* 23. 09. 04 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ 0, -1, 0, 1 };
int rdy[]{ 0, 1, 0, -1 };
int dx[]{ 1, 0, -1, 0 };
int R, C, T, ret;
vector<vector<int>> mp, nextMap;
vector<pair<int, int>> Path_A;
vector<pair<int, int>> Path_B;

vector<pair<int, int>> makePath(int sy, int* _dy)
{
	vector<pair<int, int>> v;
	int sx = 0, x = 0, y = sy, dir = 0;

	while (true) {
		int ny = y + _dy[dir];
		int nx = x + dx[dir];
		if (ny == sy && nx == sx) { break; }
		if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
			++dir;
			ny = y + _dy[dir];
			nx = x + dx[dir];
		}
		if (ny == sy && nx == sx) { break; }
		v.push_back(make_pair(ny, nx));
		y = ny;
		x = nx;
	}

	return v;
}

void moveDust()
{
	queue<pair<int, int>> dust;
	for (int i{ 0 }; i < R; ++i) {
		for (int j{ 0 }; j < C; ++j) {
			nextMap[i][j] = mp[i][j];
			if (mp[i][j] > 0) { dust.push(make_pair(i, j)); }
		}
	}

	while (dust.size()) {
		auto [cy, cx] = dust.front();
		dust.pop();

		int amount = mp[cy][cx] / 5;
		for (int i{ 0 }; i < 4; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C || mp[ny][nx] < 0) { continue; }

			nextMap[cy][cx] -= amount;
			nextMap[ny][nx] += amount;
		}
	}

	nextMap.swap(mp);
}

void moveAir(const vector<pair<int, int>>& path)
{
	for (size_t i{ path.size() - 1 }; i > 0; --i) {
		auto& [cy, cx] = path[i];
		auto& [py, px] = path[i - 1];
		mp[cy][cx] = mp[py][px];
	}
	mp[path[0].first][path[0].second] = 0;
}

int main()
{
	cin >> R >> C >> T;
	vector<vector<int>>(R, vector<int>(C, 0)).swap(mp);
	vector<vector<int>>(R, vector<int>(C, 0)).swap(nextMap);

	for (int i{ 0 }; i < R; ++i) {
		for (int j{ 0 }; j < C; ++j) {
			cin >> mp[i][j];
			if (mp[i][j] == -1) {
				if (Path_A.empty()) { Path_A = makePath(i, dy); }
				else { Path_B = makePath(i, rdy); }
			}
		}
	}

	while (T--) {
		moveDust();
		moveAir(Path_A);
		moveAir(Path_B);
	}

	for (int i{ 0 }; i < R; ++i) {
		for (int j{ 0 }; j < C; ++j) {
			if (mp[i][j] > 0) { ret += mp[i][j]; }
		}
	}

	cout << ret;

	return 0;
}