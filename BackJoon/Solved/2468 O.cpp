/* 23. 05. 26 */
#include <bits/stdc++.h>

using namespace std;

const int max_size = 101;
int a[max_size][max_size];
bool visited[max_size][max_size];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int N, h = 1, max_h, ret, max_ret = 1, ny, nx;

void DFS(int y, int x)
{
	if (visited[y][x]) return;
	
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		if (a[ny][nx] <= h) continue;
		
		DFS(ny, nx);
	}

	return;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			max_h = max(max_h, a[i][j]);
		}
	}

	while (h <= 100)
	{
		fill(&visited[0][0], &visited[0][0] + max_size * max_size, 0);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (a[i][j] <= h || visited[i][j]) continue;

				DFS(i, j);
				ret++;
			}
		}
		max_ret = max(ret, max_ret);
		ret = 0;
		h++;
	}

	cout << max_ret << '\n';

	return 0;
}