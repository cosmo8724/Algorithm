/* 23. 08. 16 */
#include <bits/stdc++.h>

using namespace std;

int dx[]{ 0, 1, 0, -1, 0, 0 };
int dy[]{ 0, 0, 0, 0, 1, -1 };
int dz[]{ -1, 0, 1, 0, 0, 0 };
int M, N, H, zeroCnt, ret = numeric_limits<int>::min();
vector<vector<vector<int>>> mp;
vector<vector<vector<int>>> visited;
queue<tuple<int, int, int>> q;

int main()
{
	cin >> M >> N >> H;
	vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M, 0))).swap(mp);
	vector<vector<vector<int>>>(H, vector<vector<int>>(N, vector<int>(M, 0))).swap(visited);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> mp[i][j][k];
				if (mp[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					visited[i][j][k] = 1;
				}
				else if (mp[i][j][k] == 0) { zeroCnt++; }
			}
		}
	}

	if (q.empty()) { ret = -1; }
	else {
		if (zeroCnt == 0) { ret = 0; }
		else {
			while (q.size()) {
				auto [cz, cy, cx] = q.front();
				q.pop();

				for (int i = 0; i < 6; i++) {
					int nz = cz + dz[i];
					int ny = cy + dy[i];
					int nx = cx + dx[i];

					if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M) { continue; }
					if (visited[nz][ny][nx] || mp[nz][ny][nx] == -1) { continue; }

					mp[nz][ny][nx] = 1;
					zeroCnt--;
					visited[nz][ny][nx] = visited[cz][cy][cx] + 1;
					q.push(make_tuple(nz, ny, nx));

					ret = max(ret, visited[nz][ny][nx] - 1);
				}
			}
			if (zeroCnt) { ret = -1; }
		}
	}

	cout << ret;

	return 0;
}