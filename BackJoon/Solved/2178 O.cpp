/* 23. 05. 26 */
#include <bits/stdc++.h>

using namespace std;

int N, M, value, y, x;
int a[104][104];
int visited[104][104];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int main()
{	
	scanf_s("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf_s("%1d", &a[i][j]);

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0, 0 });

	while (q.size())
	{
		tie(y, x) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (a[ny][nx] == 0)
				continue;
			if (visited[ny][nx])
				continue;

			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
		}
	}

	printf("%d", visited[N - 1][M - 1]);

	return 0;
}