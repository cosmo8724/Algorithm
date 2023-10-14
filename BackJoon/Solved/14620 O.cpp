/* 23. 08. 14 */
#include <bits/stdc++.h>

using namespace std;

int N, ret = numeric_limits<int>::max();
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
vector<vector<int>> mp;
vector<vector<bool>> visited;

vector<vector<int>> Calc_Cost()
{
	vector<vector<int>> ret(N + 2, vector<int>(N + 2, -1));

	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			int sum = mp[i][j];
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];

				if (ny < 1 || nx < 1 || ny > N || nx > N) {
					sum = -1;
					break;
				}

				sum += mp[ny][nx];
			}
			ret[i][j] = sum;
		}
	}

	return ret;
}

void Put_Seed(int cost, int cnt)
{
	if (cnt == 3) {
		ret = min(ret, cost);
		return;
	}

	for (int i = 2; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (mp[i][j] == -1 || visited[i][j] || visited[i - 1][j] || visited[i + 1][j] || visited[i][j - 1] || visited[i][j + 1]) { continue; }

			visited[i][j] = true;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				visited[ny][nx] = true;
			}

			Put_Seed(cost + mp[i][j], cnt + 1);

			visited[i][j] = false;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				visited[ny][nx] = false;
			}
		}
	}
}

int main()
{
	cin >> N;
	vector<vector<int>>(N + 2, vector<int>(N + 2, -1)).swap(mp);
	vector<vector<bool>>(N + 2, vector<bool>(N + 2, false)).swap(visited);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> mp[i][j];
		}
	}

	Calc_Cost().swap(mp);

	Put_Seed(0, 0);

	cout << ret;

	return 0;
}