/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, M, elem, ret = -1;
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
vector<pair<int, int>> empt;
vector<pair<int, int>> st;

int main()
{
	cin >> N >> M;
	vector<vector<int>> mp(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> elem;
			if (elem == 0) {
				empt.push_back(make_pair(i, j));
			}
			else if (elem == 2) {
				st.push_back(make_pair(i, j));
			}
			mp[i][j] = elem;
		}
	}

	for (int i = 0; i < empt.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				mp[empt[i].first][empt[i].second] = 1;
				mp[empt[j].first][empt[j].second] = 1;
				mp[empt[k].first][empt[k].second] = 1;

				vector<vector<bool>> visited(N, vector<bool>(M, false));
				for (int l = 0; l < st.size(); l++) {
					visited[st[l].first][st[l].second] = true;
				}

				queue<pair<int, int>> q;
				for (int l = 0; l < st.size(); l++) {
					q.push(make_pair(st[l].first, st[l].second));
				}

				int cnt = empt.size() - 3;
				while (q.size()) {
					const auto [y, x] = q.front();
					q.pop();

					for (int l = 0; l < 4; l++) {
						int ny = y + dy[l];
						int nx = x + dx[l];

						if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
						if (mp[ny][nx] != 0 || visited[ny][nx]) continue;

						q.push(make_pair(ny, nx));
						visited[ny][nx] = true;
						cnt--;
					}
				}

				ret = max(cnt, ret);

				mp[empt[i].first][empt[i].second] = 0;
				mp[empt[j].first][empt[j].second] = 0;
				mp[empt[k].first][empt[k].second] = 0;
			}
		}
	}

	cout << ret;
	
	return 0;
}