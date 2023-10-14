/* 23. 08. 14 */
#include <bits/stdc++.h>

using namespace std;

int N, M, H, a, b, ret = numeric_limits<int>::max();
bool possible = false;
vector<vector<bool>> visited;

bool Go()
{
	for (int i = 1; i <= N; i++) {
		int line = i;

		for (int j = 1; j <= H; j++) {
			if (visited[j][line]) { line++; }
			else if (visited[j][line - 1]) { line--; }
		}

		if (i != line) { return false; }
	}

	possible = true;
	return true;
}

void PutLedder(int raw, int cnt)
{
	if (cnt > 3 || cnt >= ret) { return; }
	if (Go()) {
		ret = min(ret, cnt);
		return;
	}

	for (int i = raw; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			if (visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) { continue; }

			visited[i][j] = true;
			PutLedder(i, cnt + 1);
			visited[i][j] = false;
		}
	}
}

int main()
{
	cin >> N >> M >> H;
	vector<vector<bool>>(H + 1, vector<bool>(N + 1, false)).swap(visited);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		visited[a][b] = true;
	}

	PutLedder(1, 0);

	if (possible) { cout << ret; }
	else { cout << -1; }

	return 0;
}