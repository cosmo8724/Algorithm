/* 23. 09. 13 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int N, M, cnt, ret;
vector<vector<int>> mp, visited;

queue<pair<int, int>> Delete_Next() {
	visited[0][0] = 1;
	queue<pair<int, int>> air, _ret;
	air.push(make_pair(0, 0));

	while (!air.empty()) {
		auto [cy, cx] { air.front() };
		air.pop();

		for (int i{ 0 }; i < 4; ++i) {
			int ny{ cy + dy[i] };
			int nx{ cx + dx[i] };

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }
			if (mp[ny][nx]) { ++visited[ny][nx]; continue; }
			if (visited[ny][nx]) { continue; }

			visited[ny][nx] = 1;
			air.push(make_pair(ny, nx));
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			if (visited[i][j] >= 2) { _ret.push(make_pair(i, j)); }
		}
	}

	return _ret;
}

int Delete_Cheese(queue<pair<int, int>>&& q) {
	int size{ static_cast<int>(q.size()) };

	while (!q.empty()) {
		auto [cy, cx] { q.front() };
		mp[cy][cx] = 0;
		q.pop();
	}

	return size;
}

int main()
{
	cin >> N >> M;
	vector<vector<int>>(N, vector<int>(M)).swap(mp);

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			cin >> mp[i][j];
			if (mp[i][j]) { ++cnt; }
		}
	}

	while (cnt > 0) {
		vector<vector<int>>(N, vector<int>(M)).swap(visited);
		cnt -= Delete_Cheese(Delete_Next());
		++ret;
	}

	cout << ret;

	return 0;
}