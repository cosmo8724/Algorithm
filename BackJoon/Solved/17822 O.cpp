/* 23. 09. 07 */
#include <bits/stdc++.h>

using namespace std;

const int DELETED = 10000;
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int N, M, T, x, d, k, ret;
bool flag = 1;
vector<vector<int>> cir;
deque<deque<bool>> visited;

void Rotate(int idx, int dir, int cnt)
{
	for (int i{ idx - 1 }; i < N; i += idx) {
		if (dir) { rotate(cir[i].begin(), cir[i].begin() + cnt, cir[i].end()); }
		else { rotate(cir[i].begin(), cir[i].begin() + M - cnt, cir[i].end()); }
	}
}

void dfs(int y, int x)
{
	for (int dir{ 0 }; dir < 4; ++dir) {
		int ny = y + dy[dir];
		int nx = (x + dx[dir] + M) % M;

		if (ny < 0 || ny >= N || visited[ny][nx]) { continue; }
		if (cir[y][x] == cir[ny][nx]) {
			visited[y][x] = visited[ny][nx] = true;
			flag = false;
			dfs(ny, nx);
		}
	}
}

bool Delete_Same_Element()
{
	flag = true;
	deque<deque<bool>>(N, deque<bool>(M, false)).swap(visited);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (cir[i][j] == DELETED || visited[i][j]) { continue; }
			dfs(i, j);
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (visited[i][j]) { cir[i][j] = DELETED; }
		}
	}

	return flag;
}

void Compare_AVG(double avg)
{
	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (cir[i][j] == DELETED) { continue; }
			if (static_cast<double>(cir[i][j]) > avg) { --cir[i][j]; }
			else if (static_cast<double>(cir[i][j]) < avg) { ++cir[i][j]; }
		}
	}
}

int main()
{
	cin >> N >> M >> T;
	vector<vector<int>>(N, vector<int>(M)).swap(cir);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cin >> cir[i][j];
		}
	}

	while (T--) {
		cin >> x >> d >> k;
		Rotate(x, d, k);
		if (Delete_Same_Element()) {
			int cnt = 0, sum = 0;
			for (int i{ 0 }; i < N; ++i) {
				for (int j{ 0 }; j < M; ++j) {
					if (cir[i][j] != DELETED) { ++cnt; sum += cir[i][j]; }
				}
			}
			Compare_AVG(static_cast<double>(sum) / static_cast<double>(cnt));
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (cir[i][j] != DELETED) { ret += cir[i][j]; }
		}
	}

	cout << ret;

	return 0;
}