/* 23. 05. 26 */
#include <bits/stdc++.h>

using namespace std;

vector<int> ret;
const int max_size = 101;
int M, N, K, ya, yb, xa, xb, ny, nx, cnt = 0;
int a[max_size][max_size];
bool visited[max_size][max_size];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void DFS(int y, int x)
{
	if (visited[y][x]) return;
	visited[y][x] = true;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N) continue;
		if (a[ny][nx] == 0) DFS(ny, nx);
	}

	return;
}

int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> xa >> ya >> xb >> yb;
		
		for (int x = xa; x < xb; x++)
			for (int y = ya; y < yb; y++)
				a[y][x]++;
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] != 0 || visited[i][j]) continue;
			cnt = 0;
			DFS(i, j);
			ret.push_back(cnt);
		}
	}

	sort(ret.begin(), ret.end());

	cout << ret.size() << '\n';

	for (int i : ret)
		cout << i << ' ';

	return 0;
}