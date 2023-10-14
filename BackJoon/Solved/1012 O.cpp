/* 23. 05. 26 */
#include <bits/stdc++.h>

using namespace std;

const int max_size = 54;
int a[max_size][max_size];
bool visited[max_size][max_size];
int TC, N, M, K, y, x, ny, nx, Cnt;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void DFS(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (a[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;
		
		DFS(ny, nx);
	}

	return;
}

int main()
{
	cin >> TC;

	while (TC--)
	{
		fill(&a[0][0], &a[0][0] + max_size * max_size, 0);
		fill(&visited[0][0], &visited[0][0] + max_size * max_size, 0);
		Cnt = 0;

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			a[y][x] = 1;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (a[i][j] == 1 && !visited[i][j])
				{
					DFS(i, j);
					Cnt++;
				}
			}
		}

		cout << Cnt << '\n';
	}

	return 0;
}