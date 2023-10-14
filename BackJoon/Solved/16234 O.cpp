/* 23. 08. 10 */
#include <bits/stdc++.h>

using namespace std;

int N, L, R, ret;
int dy[]{ -1, 0, 1, 0 };
int dx[]{ 0, 1, 0, -1 };
vector<vector<int>> mp;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> unions;

bool OpenGate(int y, int x, vector<pair<int, int>>& uni)
{
	uni.push_back(make_pair(y, x));
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) {
			continue;
		}
		
		int diff = abs(mp[y][x] - mp[ny][nx]);
		if (L <= diff && diff <= R) {
			OpenGate(ny, nx, uni);
		}
	}

	//mp[y][x] = accumulate(uni.begin(), uni.end(), 0) / uni.size();

	if (uni.size() != 1) {
		return true;
	}

	return false;
}

int main()
{
	cin >> N >> L >> R;
	vector<vector<int>>(N, vector<int>(N, 0)).swap(mp);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}

	while (true) {
		vector<vector<bool>>(N, vector<bool>(N, 0)).swap(visited);
		unions.clear();
		ret++;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					vector<pair<int, int>> uni;
					if (OpenGate(i, j, uni)) {
						unions.push_back(uni);
					}
				}
			}
		}

		if (unions.empty()) {
			break;
		}
		else {
			for (const auto& uni : unions) {
				int sum = 0;
				for (const auto& idx : uni) {
					sum += mp[idx.first][idx.second];
				}
				for (const auto& idx : uni) {
					mp[idx.first][idx.second] = sum / uni.size();
				}
			}
		}
	}

	cout << ret - 1;

	return 0;
}