/* 23. 08. 16 */
#include <bits/stdc++.h>

using namespace std;

int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
int M, N, zeroCnt, ret = numeric_limits<int>::min();
vector<vector<int>> mp;
vector<vector<int>> visited;
queue<pair<int, int>> q;

int main()
{
	cin >> M >> N;
	vector<vector<int>>(N, vector<int>(M, 0)).swap(mp);
	vector<vector<int>>(N, vector<int>(M, 0)).swap(visited);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> mp[i][j];
				if (mp[i][j] == 1) {
					q.push(make_pair(i, j));
					visited[i][j] = 1;
				}
				else if (mp[i][j] == 0) { zeroCnt++; }
			}
		}

	if (q.empty()) { ret = -1; }
	else {
		if (zeroCnt == 0) { ret = 0; }
		else {
			while (q.size()) {
				auto [cy, cx] = q.front();
				q.pop();

				for (int i = 0; i < 4; i++) {
					int ny = cy + dy[i];
					int nx = cx + dx[i];

					if (ny < 0 || nx < 0 || ny >= N || nx >= M) { continue; }
					if (visited[ny][nx] || mp[ny][nx] == -1) { continue; }

					mp[ny][nx] = 1;
					zeroCnt--;
					visited[ny][nx] = visited[cy][cx] + 1;
					q.push(make_pair(ny, nx));

					ret = max(ret, visited[ny][nx] - 1);
				}
			}
			if (zeroCnt) { ret = -1; }
		}
	}

	cout << ret;

	return 0;
}