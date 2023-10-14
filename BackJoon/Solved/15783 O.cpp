/* 23. 09. 07 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
const int WALL = 6, VISIT = 100;
int N, M, ret = numeric_limits<int>::max();
vector<vector<int>> mp;
vector<pair<int, int>> cams;

int Counting()
{
	int _ret = 0;

	for (auto& v : mp) {
		for (int i : v) {
			if (i == 0) { ++_ret; }
		}
	}

	return _ret;
}

bool IsRange(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M || mp[y][x] == WALL) { return false; }
	return true;
}

void Execute(int idx)
{
	if (idx == cams.size()) {
		ret = min(ret, Counting());
		return;
	}

	vector<vector<int>> mp_bck(mp);

	for (int i{ 0 }; i < 4; ++i) {
		auto [cy, cx] = cams[idx];
		int ny, nx;
		vector<pair<int, int>> changed;

		if (mp[cy][cx] == 1) {
			while (true) {
				ny = cy + dy[i];
				nx = cx + dx[i];
				if (!IsRange(ny, nx)) { break; }
				if (mp[ny][nx] == 0) {
					mp[ny][nx] = VISIT;
					changed.push_back(make_pair(ny, nx));
				}
				cy = ny;
				cx = nx;
			}
		}
		else if (mp[cy][cx] == 2) {
			for (int j{ 0 }; j <= 2; j += 2) {
				int yOrigin = cy, xOrigin = cx;
				int dir = (i + j) % 4;
				while (true) {
					ny = yOrigin + dy[dir];
					nx = xOrigin + dx[dir];
					if (!IsRange(ny, nx)) { break; }
					if (mp[ny][nx] == 0) {
						mp[ny][nx] = VISIT;
						changed.push_back(make_pair(ny, nx));
					}
					yOrigin = ny;
					xOrigin = nx;
				}
			}
		}
		else if (mp[cy][cx] == 3) {
			for (int j{ 0 }; j < 2; ++j) {
				int yOrigin = cy, xOrigin = cx;
				int dir = (i + j) % 4;
				while (true) {
					ny = yOrigin + dy[dir];
					nx = xOrigin + dx[dir];
					if (!IsRange(ny, nx)) { break; }
					if (mp[ny][nx] == 0) {
						mp[ny][nx] = VISIT;
						changed.push_back(make_pair(ny, nx));
					}
					yOrigin = ny;
					xOrigin = nx;
				}
			}
		}
		else if (mp[cy][cx] == 4) {
			for (int j{ 0 }; j < 3; ++j) {
				int yOrigin = cy, xOrigin = cx;
				int dir = (i + j) % 4;
				while (true) {
					ny = yOrigin + dy[dir];
					nx = xOrigin + dx[dir];
					if (!IsRange(ny, nx)) { break; }
					if (mp[ny][nx] == 0) {
						mp[ny][nx] = VISIT;
						changed.push_back(make_pair(ny, nx));
					}
					yOrigin = ny;
					xOrigin = nx;
				}
			}
		}
		else {
			for (int j{ 0 }; j < 4; ++j) {
				int yOrigin = cy, xOrigin = cx;
				int dir = (i + j) % 4;
				while (true) {
					ny = yOrigin + dy[dir];
					nx = xOrigin + dx[dir];
					if (!IsRange(ny, nx)) { break; }
					if (mp[ny][nx] == 0) {
						mp[ny][nx] = VISIT;
						changed.push_back(make_pair(ny, nx));
					}
					yOrigin = ny;
					xOrigin = nx;
				}
			}
		}

		Execute(idx + 1);

		for (auto [changed_y, changed_x] : changed) {
			mp[changed_y][changed_x] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(M)).swap(mp);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cin >> mp[i][j];
			if (mp[i][j] && mp[i][j] != 6) {
				cams.push_back(make_pair(i, j));
			}
		}
	}

	Execute(0);

	cout << ret;

	return 0;
}