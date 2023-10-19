/* 23. 10. 19 */
#include <bits/stdc++.h>

using namespace std;

int N, M, X, U, V;
vector<vector<int>> OrderWin, OrderLose;
deque<bool> visited;

int bfs(int st, const vector<vector<int>>& Students)
{
	int ret{ 0 };
	queue<int> q;
	q.push(st);
	visited[st] = true;

	while (!q.empty()) {
		int here{ q.front() };
		q.pop();

		for (int next : Students[here]) {
			if (visited[next]) { continue; }

			q.push(next);
			visited[next] = true;
			++ret;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> X;
	OrderWin.resize(N);
	OrderLose.resize(N);
	visited.resize(N);

	for (int i{ 0 }, Winner, Loser; i < M; ++i) {
		cin >> Winner >> Loser;
		OrderWin[--Winner].push_back(--Loser);
		OrderLose[Loser].push_back(Winner);
	}

	U = bfs(--X, OrderLose);
	deque<bool>(N).swap(visited);
	V = bfs(X, OrderWin);

	cout << ++U << ' ' << N - V;

	return 0;
}