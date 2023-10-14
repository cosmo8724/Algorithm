/* 23. 10. 10 */
#include <bits/stdc++.h>

using namespace std;

const int INF{ static_cast<int>(1e9) };
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int N, M, T, D, ret;
vector<vector<int>> mp, cost;
vector<int> nodes;

int ConvertIndex(int y, int x)
{
	return y * 100 + x;
}

void Floyd()
{
	for (int y{ 0 }; y < N; ++y) {
		for (int x{ 0 }; x < M; ++x) {
			for (int dir{ 0 }, ny, nx; dir < 4; ++dir) {
				ny = y + dy[dir];
				nx = x + dx[dir];

				if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }

				int diff{ abs(mp[ny][nx] - mp[y][x]) };
				if (diff <= T) {
					int& _cost{ cost[ConvertIndex(y, x)][ConvertIndex(ny, nx)] };
					if (mp[ny][nx] > mp[y][x]) { _cost = static_cast<int>(pow(diff, 2)); }
					else { _cost = 1; }
				}
			}
		}
	}

	for (int mid : nodes) {
		for (int from : nodes) {
			for (int to : nodes) {
				cost[from][to] = min(cost[from][to], cost[from][mid] + cost[mid][to]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> T >> D;

	const int ARR_SIZE{ N * 100 + M + 1 };
	vector<vector<int>>(N, vector<int>(M)).swap(mp);
	vector<vector<int>>(ARR_SIZE, vector<int>(ARR_SIZE, INF)).swap(cost);
	nodes.reserve(N * M);

	for (int i{ 0 }; i < N; ++i) {
		string s;
		cin >> s;
		for (int j{ 0 }; j < M; ++j) {
			if (isupper(s[j])) { mp[i][j] = s[j] - 'A'; }
			else { mp[i][j] = s[j] - 'a' + 26; }
		}
	}

	for (int i{ 0 }; i < N; ++i) {
		for (int j{ 0 }; j < M; ++j) {
			nodes.push_back(i * 100 + j);
		}
	}

	Floyd();

	ret = mp[0][0];
	for (int to : nodes) {
		if (D >= cost[0][to] + cost[to][0]) {
			ret = max(ret, mp[to / 100][to % 100]);
		}
	}

	cout << ret;

	return 0;
}